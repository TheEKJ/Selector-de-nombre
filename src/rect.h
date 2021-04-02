#ifndef _SN_RECT_H
#define _SN_RECT_H

template<typename T>
class PointT;

namespace sn
{
   template<typename T>
   class RectT
   {
   public:
      T x, y;
      T w, h;

      RectT() : x(0), y(0), w(0), h(0) {}
      RectT(T x, T y, T width, T height) : x(x), y(y), w(width), h(height) {}

      RectT& setOrigin(const PointT<T>& pos) {
         x = pos.x;
         y = pos.y;

         return *this;
      }

      PointT<T> origin() const {
         return PointT<T>(x, y);
      }

      PointT<T> size() const {
         return PointT<T>(w, h);
      }
   };

   typedef RectT<short> Rect;
} // namespace sn


#endif