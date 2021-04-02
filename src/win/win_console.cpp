#include "win_console.h"

#include "event_queue.h"
#include "convert.h"
#include "exception.h"
#include "char_buffer.h"

#include <string>

namespace sn
{
   WinConsole::~WinConsole()
   {
      SetConsoleMode(m_hConsoleStdIn, m_originalStdInMode);
      this->setColor(m_color);
   }

   bool WinConsole::init()
   {
      m_hConsoleStdIn = GetStdHandle(STD_INPUT_HANDLE);
      m_hConsoleStdOut = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
         NULL,
         NULL,
         CONSOLE_TEXTMODE_BUFFER,
         NULL);

      SetConsoleActiveScreenBuffer(m_hConsoleStdOut);

      if(!GetConsoleMode(m_hConsoleStdIn, &m_originalStdInMode)) return false;
      
      if(!SetConsoleMode(m_hConsoleStdIn, m_originalStdInMode | ENABLE_WINDOW_INPUT)) return false;

      CONSOLE_SCREEN_BUFFER_INFO csbi;
      if(!GetConsoleScreenBufferInfo(m_hConsoleStdOut, &csbi)) return false;

      m_color = details::to_win32(csbi.wAttributes);

      return true;
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

   void WinConsole::writeCharBuffer(CharBuffer* buffer)
   {
      WinCharBuffer* winBuffer = reinterpret_cast<WinCharBuffer*>(buffer);

      SMALL_RECT rc = details::to_win32(winBuffer->rect());

      WriteConsoleOutput(m_hConsoleStdOut,
         winBuffer->getCharInfo(),
         details::to_win32(winBuffer->rect().size()), 
         details::to_win32(winBuffer->offset()),
         &rc);
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

   Color WinConsole::color() const
   {
      CONSOLE_SCREEN_BUFFER_INFO csbi;
      GetConsoleScreenBufferInfo(m_hConsoleStdOut, &csbi);

      return details::to_win32(csbi.wAttributes);
   }
} // namespace sn