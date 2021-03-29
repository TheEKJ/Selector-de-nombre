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

      void events()
      {
         ReadConsoleInput(m_hConsole,
            record,
            128,
            &numbers);

         for(int i = 0; i < numbers; i++) {
            switch(record[i].EventType) {
            case KEY_EVENT:
               printf("%c\n", record[i].Event.KeyEvent.uChar);
               break;
            }
         }
      }

      virtual void init() override;
      virtual void clear() override;
      virtual void setColor(Color color) override;
      virtual void setCursorPos(const Point& pos) override;
   private:
      HANDLE m_hConsole;
      HANDLE m_hConsoleScreenBuffer;
      DWORD m_originalConsoleMode;

      INPUT_RECORD record[128];
      DWORD numbers;
   };
} // namespace sn


#endif