#ifndef _SN_WIN_WIN_CONSOLE_H
#define _SN_WIN_WIN_CONSOLE_H
#include "console.h"

#include <windows.h>

#include <cstdio>

namespace sn
{
   class WinConsole : public Console
   {  
   public:
      WinConsole() {}
      ~WinConsole();

      virtual void init() override;
      virtual void clear() override;

      virtual void writeText(const char* text, const Point& pos) override;
      virtual void fillChar(char chr, int length, const Point& pos) override;
      virtual void setTitle(const char* title) override;
      virtual void setColor(Color color) override;
      virtual void setCursorPos(const Point& pos) override;

      virtual EventQueue* queue() override;

      HANDLE getStdIn();
      HANDLE getStdOut();
   private:
      HANDLE m_hConsoleStdIn;
      HANDLE m_hConsoleStdOut;

      DWORD m_originalStdInMode;
      Color m_color;
   };
} // namespace sn


#endif