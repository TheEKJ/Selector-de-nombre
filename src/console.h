#ifndef SN_CONSOLE_H
#define SN_CONSOLE_H
#include "color.h"
#include "point.h"

namespace sn
{
   class Console
   {  
   public:
      static void Init();
      static void Clear();
      static void SetColor(Color color);
      static void SetCursorPos(const Point& pos);
      static void Release();
   };
} // namespace sn


#endif