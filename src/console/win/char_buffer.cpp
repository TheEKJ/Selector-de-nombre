#include "char_buffer.h"

#include "console.h"
#include "convert.h"

#include <cassert>

namespace console
{
   WinCharBuffer::WinCharBuffer(std::initializer_list<char> buffer, const Rect& rc) :
      m_rect(rc)
   {
      for(char item : buffer) {
         CHAR_INFO chrInfo;
         chrInfo.Char.AsciiChar = item;
         chrInfo.Attributes = Console::GetInstance()->color();
         m_buffer.push_back(chrInfo);
      }
   }

   void WinCharBuffer::setColor(Color color)
   {
      for(CHAR_INFO& item : m_buffer) {
         item.Attributes = details::to_win32(color);
      }
   }

   void WinCharBuffer::setPosition(const Point& pos)
   {
      m_rect.setOrigin(pos);
   }

   void WinCharBuffer::setOffset(const Point& offset)
   {
      m_offset = offset;
   }

   Point WinCharBuffer::offset() const
   {
      return m_offset;
   }

   Point WinCharBuffer::position() const
   {
      return m_rect.origin();
   }

   Rect WinCharBuffer::rect() const
   {
      return m_rect;
   }

   char WinCharBuffer::getChar(int index) const
   { 
      assert(index >= 0 && index < m_buffer.size());
      return m_buffer[index].Char.AsciiChar;
   }

   CHAR_INFO* WinCharBuffer::getCharInfo()
   {
      return &m_buffer[0];
   }
} // namespace console