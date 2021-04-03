#ifndef _SN_CONSOLE_WIN_WIN_CONSOLE_H
#define _SN_CONSOLE_WIN_WIN_CONSOLE_H
#include "console.h"

#include <windows.h>

#include <cstdio>

namespace console
{
   class WinConsole : public Console
   {  
   public:
      WinConsole() {}
      ~WinConsole();

      virtual bool init() override;
      virtual void clear() override;

      virtual void fillChar(char chr, int length, const Point& pos) override;
      virtual void writeText(const char* text, const Point& pos) override;
      virtual void writeCharBuffer(CharBuffer* buffer) override;

      virtual std::string readText(const Point& pos, int length) override;

      virtual void setTitle(const char* title) override;
      virtual void setColor(Color color) override;
      virtual void setCursorPos(const Point& pos) override;

      virtual Point getCursorPos() const override;

      virtual Color color() const override;
      virtual EventQueue* queue() override;

      HANDLE getStdIn();
      HANDLE getStdOut();
   private:
      CONSOLE_SCREEN_BUFFER_INFO getCSBI() const;

      HANDLE m_hConsoleStdIn;
      HANDLE m_hConsoleStdOut;

      DWORD m_originalStdInMode;
      Color m_color;
   };
} // namespace console


#endif