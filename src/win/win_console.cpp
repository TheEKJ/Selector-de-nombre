#include "win_console.h"

#include "event_queue.h"
#include "convert.h"
#include "exception.h"

#include <string>

namespace sn
{
   WinConsole::~WinConsole()
   {
      SetConsoleMode(m_hConsoleStdIn, m_originalStdInMode);
      this->setColor(m_color);
   }

   void WinConsole::init()
   {
      m_hConsoleStdIn = GetStdHandle(STD_INPUT_HANDLE);
      m_hConsoleStdOut = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
         NULL,
         NULL,
         CONSOLE_TEXTMODE_BUFFER,
         NULL);

      SetConsoleActiveScreenBuffer(m_hConsoleStdOut);

      if(!GetConsoleMode(m_hConsoleStdIn, &m_originalStdInMode)) throw Exception("Error al obtener modo!");
      
      DWORD inmode = ENABLE_WINDOW_INPUT;

      if(!SetConsoleMode(m_hConsoleStdIn, inmode)) throw Exception("Error al poner el modo ConsoleStdIn!");

      CONSOLE_SCREEN_BUFFER_INFO csbi;
      if(!GetConsoleScreenBufferInfo(m_hConsoleStdOut, &csbi)) throw Exception("GetConsoleScreenBufferInfo error!");

      m_color = details::to_win32(csbi.wAttributes);
   }

   HANDLE WinConsole::getStdIn()
   {
      return m_hConsoleStdIn;
   }

   HANDLE WinConsole::getStdOut()
   {
      return m_hConsoleStdOut;
   }

   EventQueue* WinConsole::queue()
   {
      return WinEventQueue::GetInstance();
   }

   void WinConsole::writeText(const char* text, const Point& pos)
   {
      DWORD cNumWritten;
      WriteConsoleOutputCharacter(m_hConsoleStdOut,
         text,
         strlen(text),
         details::to_win32(pos),
         &cNumWritten);
   }

   void WinConsole::fillChar(char chr, int length, const Point& pos)
   {
      DWORD cNumWritten;
      FillConsoleOutputCharacter(m_hConsoleStdOut,
         chr,
         length,
         details::to_win32(pos),
         &cNumWritten);
   }

   void WinConsole::setTitle(const char* title)
   {
      SetConsoleTitle(title);
   }

   void WinConsole::setColor(Color color)
   {
      SetConsoleTextAttribute(m_hConsoleStdOut, details::to_win32(color));
   }

   void WinConsole::setCursorPos(const Point& pos)
   {
      SetConsoleCursorPosition(m_hConsoleStdOut, details::to_win32(pos));
   }

   void WinConsole::clear()
   {
      COORD coord = {0};
      CONSOLE_SCREEN_BUFFER_INFO csbi;
      DWORD cCharsWritten;
      DWORD dwConSize;
   
      if(!GetConsoleScreenBufferInfo(m_hConsoleStdOut, &csbi)) return;

      dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

      FillConsoleOutputCharacter(m_hConsoleStdOut, ' ', dwConSize,
         coord,
         &cCharsWritten);

      SetConsoleCursorPosition(m_hConsoleStdOut, coord);
   }
} // namespace sn