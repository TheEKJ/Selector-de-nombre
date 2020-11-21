#include "console.h"

#include <cstdio>
#include <windows.h>
#include <stdexcept>

#include "convert.h"

namespace
{
   HANDLE g_hConsole;
   DWORD g_originalConsoleMode;
}


namespace sn
{
   void Console::Init()
   {
      g_hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,  FILE_SHARE_READ | FILE_SHARE_WRITE,
      NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

      if(g_hConsole == INVALID_HANDLE_VALUE) throw std::runtime_error("Error al obtener el handle de la consola!");

      if(!GetConsoleMode(g_hConsole, &g_originalConsoleMode)) throw std::runtime_error("Error al obtener modo!");
      
      DWORD mode = g_originalConsoleMode;
      mode |= ENABLE_WINDOW_INPUT;
      // Activas la secuencias de consola
      // Ver https://docs.microsoft.com/en-us/windows/console/console-virtual-terminal-sequences
      if(!SetConsoleMode(g_hConsole, mode)) throw std::runtime_error("Error al poner el modo!");
   }

   void Console::SetColor(Color color)
   {
      SetConsoleTextAttribute(g_hConsole, details::to_win32(color));
   }

   void Console::SetCursorPos(const Point& pos)
   {
      SetConsoleCursorPosition(g_hConsole, details::to_win32(pos));
   }

   void Console::Clear()
   {
      DWORD mode = 0;
      GetConsoleMode(g_hConsole, &mode);
      DWORD originalMode = mode;
      mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;      

      DWORD written = 0;
      // rgb(247, 99, 0)
      printf("\x1b[2J");
   }

   void Console::Release()
   {
      SetConsoleMode(g_hConsole, g_originalConsoleMode);
   }
} // namespace sn
//TODO: Activar las secuencias de terminal de consola (https://docs.microsoft.com/en-us/windows/console/console-virtual-terminal-sequences)