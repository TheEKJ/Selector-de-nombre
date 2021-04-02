#ifndef _SN_CHAR_BUFFER_H
#define _SN_CHAR_BUFFER_H
#include "color.h"
#include "point.h"
#include "rect.h"

namespace sn
{
   class CharBuffer
   {
   public:
      CharBuffer() = default;

      virtual void setPosition(const Point& pos) = 0;
      virtual void setColor(Color color) = 0;
      virtual void setOffset(const Point& offset) = 0;
      
      virtual Point offset() const = 0;
      virtual Rect rect() const = 0;
   };
} // namespace sn


#endif