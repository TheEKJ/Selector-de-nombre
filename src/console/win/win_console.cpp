#include "win_console.h"

#include "event_queue.h"
#include "convert.h"
#include "char_buffer.h"

#include <string>
#include <stdexcept>

namespace console
{
   WinConsole::~WinConsole()
   {
      SetConsoleMode(m_hConsoleStdIn, m_originalStdInMode);
      this->setColor(m_color);
      SetConsoleActiveScreenBuffer(GetStdHandle(STD_OUTPUT_HANDLE));
      CloseHandle(m_hConsoleStdOut);
   }

   bool WinConsole::init()
   {
      m_hConsoleStdIn = GetStdHandle(STD_INPUT_HANDLE);
      m_hConsoleStdOut = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
         FILE_SHARE_READ | FILE_SHARE_WRITE,
         NULL,
         CONSOLE_TEXTMODE_BUFFER,
         NULL);

      if(m_hConsoleStdOut == INVALID_HANDLE_VALUE ||
         m_hConsoleStdIn == INVALID_HANDLE_VALUE)
         return false;

      if(!SetConsoleActiveScreenBuffer(m_hConsoleStdOut)) return false;

      if(!GetConsoleMode(m_hConsoleStdIn, &m_originalStdInMode)) return false;
      
      if(!SetConsoleMode(m_hConsoleStdIn, ENABLE_WINDOW_INPUT)) return false;

      m_color = details::from_win32(getCSBI().wAttributes);

      return true;
   }

   void WinConsole::clear()
   {
      COORD coord = {0};
      CONSOLE_SCREEN_BUFFER_INFO csbi = getCSBI();
      DWORD cCharsWritten;
      DWORD dwConSize;
   
      dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

      FillConsoleOutputCharacter(m_hConsoleStdOut, ' ', dwConSize,
         coord,
         &cCharsWritten);

      FillConsoleOutputAttribute(m_hConsoleStdOut,
         getCSBI().wAttributes,
         dwConSize,
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
      setCursorPos(pos);

      WriteConsole(m_hConsoleStdOut,
         text,
         strlen(text),
         &cNumWritten,
         NULL);
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

   std::string WinConsole::readText(const Point& pos, int length)
   {
      std::string result(length, '\0');
      DWORD cNumWritten;

      ReadConsoleOutputCharacter(
         m_hConsoleStdOut,
         &result[0],
         result.size(),
         details::to_win32(pos),
         &cNumWritten
      );

      return result;
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

   Point WinConsole::getCursorPos() const
   {
      return details::from_win32(getCSBI().dwCursorPosition);
   }

   Color WinConsole::color() const
   {
      return details::from_win32(getCSBI().wAttributes);
   }

   CONSOLE_SCREEN_BUFFER_INFO WinConsole::getCSBI() const
   {
      CONSOLE_SCREEN_BUFFER_INFO csbi;
      GetConsoleScreenBufferInfo(m_hConsoleStdOut, &csbi);
      
      return csbi;
   }
} // namespace console