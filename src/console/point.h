#ifndef SN_CONSOLE_POINT_H
#define SN_CONSOLE_POINT_H

namespace console
{
   template<typename T>
   class PointT
   {
   public:
      T x, y;

      PointT() : x(0), y(0) {}
      PointT(const T& x, const T& y) : x(x), y(y) {}
      PointT(const T& xy) : x(xy), y(xy) {}
   };

   typedef PointT<short> Point;
} // namespace console

#endif