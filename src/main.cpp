#include "console.h"

#include <iostream>

// ESC "\x1b"
// CSI "\x1b[""

int main()
{
   // Iniciando la configuracion de la consola
   sn::Console::Init();

   sn::Console::Release();
   return 0;
}