#ifndef _SN_WIN_EVENT_QUEUE_H
#define _SN_WIN_EVENT_QUEUE_H
#include "../event_queue.h"
#include "win_console.h"

#include <queue>

namespace sn
{
   class WinEventQueue : public EventQueue
   {
   public:
      virtual void queueEvent(const Event& ev) override;
      virtual void getEvents(Event& ev) override;
   private:
      std::queue<Event> m_events;

      WinConsole* m_console;
      INPUT_RECORD m_inputBuf[128];
      DWORD m_cNumRead;
   };
} // namespace sn


#endif