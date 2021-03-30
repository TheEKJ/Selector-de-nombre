#include "event_queue.h"

#ifdef _WIN32
   #include "win/event_queue.h"

   typedef sn::WinEventQueue EventQueueType;
#endif

namespace sn
{
   static EventQueueType g_console;

   EventQueue* EventQueue::GetInstance()
   {
      return &g_console;
   }
} // namespace sn
