#ifndef _SN_CONSOLE_H
#define _SN_CONSOLE_H
#include "color.h"
#include "point.h"

namespace sn
{
   class Console
   {  
   public:
      virtual ~Console() {}
      
      virtual void events() {}

      virtual void init() = 0;
      virtual void clear() = 0;
      virtual void setColor(Color color) = 0;
      virtual void setCursorPos(const Point& pos) = 0;

      static Console* GetInstance();
   protected:
      Console() = default;
   };
} // namespace sn


#endif