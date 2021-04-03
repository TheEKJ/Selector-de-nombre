#include "app/app.h"

int main()
{
   app::App app;

   if(!app.init()) {
      return 1;
   }
   
   app.run();
   return 0;
}