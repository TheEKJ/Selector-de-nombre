#ifndef _SN_CONSOLE_CONSOLE_H
#define _SN_CONSOLE_CONSOLE_H
#include "color.h"
#include "point.h"
#include "rect.h"

#include <memory>
#include <string>

namespace console
{
   class EventQueue;
   class CharBuffer;

   class Console
   {  
   public:
      virtual ~Console() {}
      
      virtual bool init() = 0;
      virtual void clear() = 0;

      virtual void fillChar(char chr, int length, const Point& pos) = 0;
      virtual void writeText(const char* text, const Point& pos) = 0;
      virtual void writeCharBuffer(CharBuffer* buffer) = 0;

      virtual std::string readText(const Point& pos, int length) = 0;

      virtual void setTitle(const char* title) = 0;
      virtual void setColor(Color color) = 0;
      virtual void setCursorPos(const Point& pos) = 0;

      std::unique_ptr<CharBuffer> createChrBuffer(std::initializer_list<char> buffer, const Rect& rc);

      virtual Point getCursorPos() const = 0;
      
      virtual Color color() const = 0;
      virtual EventQueue* queue() = 0;

      static Console* GetInstance();
   protected:
      Console() = default;
   };
} // namespace console

#endif