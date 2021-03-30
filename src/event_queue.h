#ifndef _SN_EVENT_QUEUE_H
#define _SN_EVENT_QUEUE_H
#include "event.h"

namespace sn
{
   class EventQueue
   {
   public:
      virtual void queueEvent(const Event& ev) = 0;
      virtual void getEvents(Event& ev) = 0;

      static EventQueue* GetInstance();
   };
} // namespace sn


#endif