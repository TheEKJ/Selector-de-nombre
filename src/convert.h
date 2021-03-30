#ifndef SN_CONVERT_H
#define SN_CONVERT_H
#include "color.h"
#include "point.h"

#include <windows.h>

namespace sn::details
{
   constexpr inline int to_win32(Color color)
   {
      static_assert(
         (int)DkBlue    == 1  &&
         (int)DkGreen   == 2  &&
         (int)DkCyan    == 3  &&
         (int)DkRed     == 4  &&
         (int)DkViolet  == 5  &&
         (int)DkYellow  == 6  &&
         (int)DkWhite   == 7  &&
         (int)DkGray    == 8  &&
         (int)Blue      == 9  &&
         (int)Green     == 10 &&
         (int)Cyan      == 11 &&
         (int)Red       == 12 &&
         (int)Violet    == 13 &&
         (int)Yellow    == 14 &&
         (int)White     == 15,
         "Color not match with Win32!");

      return (int)color;
   }

   constexpr inline Color to_win32(DWORD attributes)
   {
      static_assert(
         (int)DkBlue    == 1  &&
         (int)DkGreen   == 2  &&
         (int)DkCyan    == 3  &&
         (int)DkRed     == 4  &&
         (int)DkViolet  == 5  &&
         (int)DkYellow  == 6  &&
         (int)DkWhite   == 7  &&
         (int)DkGray    == 8  &&
         (int)Blue      == 9  &&
         (int)Green     == 10 &&
         (int)Cyan      == 11 &&
         (int)Red       == 12 &&
         (int)Violet    == 13 &&
         (int)Yellow    == 14 &&
         (int)White     == 15,
         "Color not match with Win32!");
      return (Color)attributes;
   }

   constexpr inline COORD to_win32(const Point& point)
   {
      return {point.x, point.y};
   }
} // namespace sn


#endif