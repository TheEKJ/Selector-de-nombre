#ifndef _SN_APP_H
#define _SN_APP_H
#include "console/point.h"
#include "console/color.h"

#include <string>

namespace console
{
   class Console;
   class EventQueue;
}

namespace app
{
   class App
   {
   public:
      App();

      bool init();
      void run();

      static App* GetInstance();
   private:
      static App* m_instance;

      void paint(console::Console* console);
      void queueEvent(console::EventQueue* queue);

      console::Console* m_console;
      console::Point m_cursorPos;
      console::Color m_consoleColor;
      std::string m_name;
      bool m_run;
   };
} // namespace app

#endif