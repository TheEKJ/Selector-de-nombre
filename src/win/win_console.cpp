#include "win_console.h"

#include "convert.h"
#include "exception.h"

namespace sn
{
   WinConsole::~WinConsole()
   {
      SetConsoleMode(m_hConsole, m_originalConsoleMode);
      CloseHandle(m_hConsoleScreenBuffer);
   }

   void WinConsole::init()
   {
      m_hConsole = GetStdHandle(STD_INPUT_HANDLE);
      m_hConsoleScreenBuffer = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,  FILE_SHARE_READ | FILE_SHARE_WRITE,
      NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

      if(m_hConsoleScreenBuffer == INVALID_HANDLE_VALUE) throw Exception("Error al obtener el handle de la consola!");

      if(!GetConsoleMode(m_hConsole, &m_originalConsoleMode)) throw Exception("Error al obtener modo!");
      
      DWORD mode = m_originalConsoleMode;
      mode |= ENABLE_WINDOW_INPUT;
      // Activas la secuencias de consola
      // Ver https://docs.microsoft.com/en-us/windows/console/console-virtual-terminal-sequences

      //TODO: El HANDLE debe ser <<<<STD_INPUT_HANDLE>>>>
      if(!SetConsoleMode(m_hConsole, mode)) throw Exception("Error al poner el modo!");
   }

   void WinConsole::setColor(Color color)
   {
      SetConsoleTextAttribute(m_hConsole, details::to_win32(color));
   }

   void WinConsole::setCursorPos(const Point& pos)
   {
      SetConsoleCursorPosition(m_hConsole, details::to_win32(pos));
   }

   void WinConsole::clear()
   {
      DWORD mode = 0;
      GetConsoleMode(m_hConsole, &mode);
      DWORD originalMode = mode;
      mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;      

      DWORD written = 0;
      // rgb(247, 99, 0)
      printf("\x1b[2J");
   }
} // namespace sn
//TODO: Activar las secuencias de terminal de consola (https://docs.microsoft.com/en-us/windows/console/console-virtual-terminal-sequences)