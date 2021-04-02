#include "console.h"
#include "event_queue.h"
#include "char_buffer.h"

#include <iostream>

int main()
{
   sn::Console* console = sn::Console::GetInstance();

   if(!console->init()) {
      puts("Error al iniciar consola!");
      return 1;
   }

   std::unique_ptr<sn::CharBuffer> chrBuf = console->createChrBuffer(
      {'a', 'b', 'c',
       'd', 'e', 'f'},
      sn::Rect(0, 0, 3, 2));

   chrBuf->setColor(sn::DkGreen_Color);

   console->clear();
   console->setTitle("Selector de nombre");

   sn::EventQueue* queue = console->queue();

   sn::Point p;

   bool is_run = true;
   while(is_run) {
      sn::Event ev;
      queue->getEvents(ev);

      switch(ev.type) {
      case sn::Event::KeyDown_Type:
         switch(ev.key) {
         case sn::Left_Key:
            p.x--;
            break;
         case sn::Right_Key:
            p.x++;
            break;
         case sn::Up_Key:
            p.y--;
            break;
         case sn::Down_Key:
            p.y++;
            break;
         case sn::Escape_Key: is_run = false; break;
         }
         break;
      }
      
      console->clear();
      chrBuf->setPosition(p);
      console->writeCharBuffer(chrBuf.get());
   }

   return 0;
}