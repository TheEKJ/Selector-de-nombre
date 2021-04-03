#ifndef _SN_CONSOLE_EVENT_H
#define _SN_CONSOLE_EVENT_H
#include "keys.h"

namespace console
{
   struct Event
   {
      enum Type {
         KeyDown_Type,
         KeyUp_Type
      };   

      Keys key;
      Type type;
   };
} // namespace console

#endif