#include "event_queue.h"

#include "win_console.h"
#include "exception.h"
#include "keys.h"

namespace sn
{
   static void KeyEventProc(Event& ev, KEY_EVENT_RECORD ker)
   {
      ev.type = (ker.bKeyDown == TRUE ? Event::KeyDown_Type : Event::KeyUp_Type);
      ev.key = win32_to_keys(ker.wVirtualKeyCode);
   }

   void WinEventQueue::queueEvent(const Event& ev)
   {
      m_events.push(ev);
   }  

   void WinEventQueue::getEvents(Event& ev)
   {
      WinConsole* console = reinterpret_cast<WinConsole*>(Console::GetInstance());

      if(!ReadConsoleInput(console->getStdIn(), m_inputBuf, ARRAYSIZE(m_inputBuf), &m_cNumRead))
         throw Exception("ReadConsoleInput error!");

      for(int i = 0; i < m_cNumRead; i++) {
         switch(m_inputBuf[i].EventType) {
         case KEY_EVENT:
            KeyEventProc(ev, m_inputBuf[i].Event.KeyEvent);
            break;
         }
      }
   }
} // namespace sn
