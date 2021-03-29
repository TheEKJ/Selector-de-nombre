#include "console.h"

#include <iostream>

// ESC "\x1b"
// CSI "\x1b[""

int main()
{
   sn::Console* console = sn::Console::GetInstance();
   
   // Iniciando la configuracion de la consola
   console->init();

   while(true) {
      console->events();
   }

   return 0;
}