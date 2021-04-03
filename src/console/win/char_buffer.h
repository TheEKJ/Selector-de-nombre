#ifndef _SN_CONSOLE_WIN_CHAR_BUFFER_H
#define _SN_CONSOLE_WIN_CHAR_BUFFER_H
#include "../char_buffer.h"

#include <vector>
#include <windows.h>

namespace console
{
   class WinCharBuffer : public CharBuffer
   {
   public:
      WinCharBuffer(std::initializer_list<char> buffer, const Rect& rc);

      virtual void setColor(Color color) override;
      virtual void setPosition(const Point& pos) override;
      virtual void setOffset(const Point& offset) override;
      
      virtual Point offset() const override;
      virtual Point position() const override;
      virtual Rect rect() const override;

      virtual char getChar(int index) const override;

      CHAR_INFO* getCharInfo();
   private:
      std::vector<CHAR_INFO> m_buffer;
      Point m_offset;
      Rect m_rect;
   };
} // namespace console

#endif