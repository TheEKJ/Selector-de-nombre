#ifndef _SN_APP_CLAMP_H
#define _SN_APP_CLAMP_H

namespace app
{
   template<typename T>
   T clamp(const T& value, const T& min, const T& max)
   {
      return value > max ? max :
             value < min ? min :
             value;
   }
} // namespace app

#endif