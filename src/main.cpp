#include "console.h"
#include "event_queue.h"

#include <iostream>

int main()
{
   sn::Console* console = sn::Console::GetInstance();
   console->init();
   console->clear();
   console->setTitle("Selector de nombre");

   sn::EventQueue* queue = console->queue();

   sn::Point p;
   const char* buf = "˂";

   bool is_run = true;
   while(is_run) {
      sn::Event ev;
      queue->getEvents(ev);

      switch(ev.type) {
      case sn::Event::KeyDown_Type:
         switch(ev.key) {
         case sn::Left_Key:
            buf = "˂";
            p.x--;
            break;
         case sn::Right_Key:
            buf = "˃";
            p.x++;
            break;
         case sn::Up_Key:
            buf = "˄";
            p.y--;
            break;
         case sn::Down_Key:
            buf = "˅";
            p.y++;
            break;
         case sn::Escape_Key: is_run = false; break;
         }
         break;
      }
      
      console->clear();
      console->writeText("asdas\nasd", p);
   }

   return 0;
}