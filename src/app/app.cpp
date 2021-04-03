#include "app.h"

#include "console/console.h"
#include "console/char_buffer.h"
#include "console/event_queue.h"
#include "scripts/clamp.h"

#include <cassert>

using namespace console;

namespace app
{
   App* App::m_instance = nullptr;
   std::unique_ptr<CharBuffer> g_chrBuffer(nullptr);

   App::App() :
      m_console(Console::GetInstance()),
      m_run(false)
   {
      assert(m_instance == nullptr);
      m_instance = this;
   }

   bool App::init()
   {
      if(!m_console->init()) return false;
      m_console->setTitle("Selector de nombre");
      m_consoleColor = m_console->color();

      g_chrBuffer = m_console->createChrBuffer({
         '0', ' ', ' ', '1', ' ', ' ', '2', ' ', ' ', '3',
         '4', ' ', ' ', '5', ' ', ' ', '6', ' ', ' ', '7',
         '8', ' ', ' ', '9', ' ', ' ', 'A', ' ', ' ', 'B',
         'C', ' ', ' ', 'D', ' ', ' ', 'E', ' ', ' ', 'F',
         'G', ' ', ' ', 'H', ' ', ' ', 'I', ' ', ' ', 'J',
         'K', ' ', ' ', 'L', ' ', ' ', 'M', ' ', ' ', 'N',
         'O', ' ', ' ', 'P', ' ', ' ', 'Q', ' ', ' ', 'R',
         'S', ' ', ' ', 'T', ' ', ' ', 'U', ' ', ' ', 'V',
         'W', ' ', ' ', 'X', ' ', ' ', 'Y', ' ', ' ', 'Z',
         'a', ' ', ' ', 'b', ' ', ' ', 'c', ' ', ' ', 'd',
         'e', ' ', ' ', 'f', ' ', ' ', 'g', ' ', ' ', 'h',
         'i', ' ', ' ', 'j', ' ', ' ', 'k', ' ', ' ', 'l',
         'm', ' ', ' ', 'n', ' ', ' ', 'o', ' ', ' ', 'p',
         'q', ' ', ' ', 'r', ' ', ' ', 's', ' ', ' ', 't',
         'u', ' ', ' ', 'v', ' ', ' ', 'w', ' ', ' ', 'x',
         'y', ' ', ' ', 'z', ' ', ' ', '_', ' ', ' ', '-',
         '*', ' ', ' ', '.', ' ', ' ', ',', ' ', ' ', ';'
      }, Rect(0, 5, 10, 17));
      m_cursorPos = g_chrBuffer->position();

      return true;  
   }

   void App::run()
   {
      m_run = true;

      while(m_run) {
         paint(m_console);
         queueEvent(m_console->queue());
      }
   }

   void App::paint(Console* console)
   {
      console->clear();

      console->setColor(m_consoleColor);
      console->writeText("Ingrese su nombre:", Point());

      console->setColor(Yellow_Color);
      console->writeText(m_name.c_str(), Point(0, 2));
      console->setColor(m_consoleColor);

      console->writeCharBuffer(g_chrBuffer.get());
      console->setColor(Red_Color);
      console->writeText(console->readText(m_cursorPos, 1).c_str(), m_cursorPos);
   }

   void App::queueEvent(EventQueue* queue)
   {
      Event ev;
      queue->getEvents(ev);

      switch(ev.type) {
      case Event::KeyDown_Type:
         if(ev.key == Escape_Key)
            m_run = false;
         if(ev.key == Right_Key)
            m_cursorPos.x = clamp<short>(m_cursorPos.x+3, 0, g_chrBuffer->position().x+g_chrBuffer->rect().w-1);
         if(ev.key == Left_Key)
            m_cursorPos.x = clamp<short>(m_cursorPos.x-3, 0, g_chrBuffer->position().x+g_chrBuffer->rect().w-1);
         if(ev.key == Down_Key)
            m_cursorPos.y = clamp<short>(m_cursorPos.y+1, g_chrBuffer->position().y, g_chrBuffer->position().y+g_chrBuffer->rect().h-1);
         if(ev.key == Up_Key) 
            m_cursorPos.y = clamp<short>(m_cursorPos.y-1, g_chrBuffer->position().y, g_chrBuffer->position().y+g_chrBuffer->rect().h);

         if(ev.key == Backspace_Key)
            if(m_name.size() > 0)
               m_name.erase(m_name.size()-1);

         if(ev.key == Enter_Key) {
            short bufferY = m_cursorPos.y-g_chrBuffer->position().y;
            char chr = g_chrBuffer->getChar(m_cursorPos.x + bufferY*g_chrBuffer->rect().w);
            if(chr != ' ')
               m_name.push_back(chr);
         }

         if(ev.key == Space_Key)
            m_name.push_back(' ');

         break;
      }
   }

   App* App::GetInstance()
   {
      return m_instance;
   }
} // namespace app
