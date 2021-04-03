#ifndef SN_CONSOLE_CONVERT_H
#define SN_CONSOLE_CONVERT_H
#include "color.h"
#include "point.h"
#include "rect.h"

#include <windows.h>

namespace console::details
{
   inline int to_win32(Color color)
   {
      static_assert(
         (int)DkBlue_Color    == 1  &&
         (int)DkGreen_Color   == 2  &&
         (int)DkCyan_Color    == 3  &&
         (int)DkRed_Color     == 4  &&
         (int)DkViolet_Color  == 5  &&
         (int)DkYellow_Color  == 6  &&
         (int)DkWhite_Color   == 7  &&
         (int)DkGray_Color    == 8  &&
         (int)Blue_Color      == 9  &&
         (int)Green_Color     == 10 &&
         (int)Cyan_Color      == 11 &&
         (int)Red_Color       == 12 &&
         (int)Violet_Color    == 13 &&
         (int)Yellow_Color    == 14 &&
         (int)White_Color     == 15,
         "Color not match with Win32!");

      return (int)color;
   }

   inline Color from_win32(DWORD attributes)
   {
      static_assert(
         (int)DkBlue_Color    == 1  &&
         (int)DkGreen_Color   == 2  &&
         (int)DkCyan_Color    == 3  &&
         (int)DkRed_Color     == 4  &&
         (int)DkViolet_Color  == 5  &&
         (int)DkYellow_Color  == 6  &&
         (int)DkWhite_Color   == 7  &&
         (int)DkGray_Color    == 8  &&
         (int)Blue_Color      == 9  &&
         (int)Green_Color     == 10 &&
         (int)Cyan_Color      == 11 &&
         (int)Red_Color       == 12 &&
         (int)Violet_Color    == 13 &&
         (int)Yellow_Color    == 14 &&
         (int)White_Color     == 15,
         "Color not match with Win32!");
         
      return (Color)attributes;
   }

   inline COORD to_win32(const Point& point)
   {
      return {point.x, point.y};
   }

   inline Point from_win32(const COORD& coord)
   {
      return Point(coord.X, coord.Y);
   }

   inline SMALL_RECT to_win32(const Rect& rc)
   {
      return {rc.x, rc.y, rc.x+rc.w, rc.y+rc.h};
   }
} // namespace console

#endif