#include "event_queue.h"

#ifdef _WIN32
   #include "win/event_queue.h"

   typedef console::WinEventQueue EventQueueType;
#endif

namespace console
{
   static EventQueueType g_console;

   EventQueue* EventQueue::GetInstance()
   {
      return &g_console;
   }
} // namespace console