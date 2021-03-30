#ifndef _SN_EVENT_H
#define _SN_EVENT_H
#include "keys.h"

namespace sn
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
} // namespace sn


#endif