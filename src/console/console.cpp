#include "console.h"

#ifdef _WIN32
   #include "win/win_console.h"
   #include "win/char_buffer.h"

   typedef console::WinConsole ConsoleImplType;
   typedef console::WinCharBuffer CharBufferType;
#endif

namespace console
{
   static ConsoleImplType g_console;

   Console* Console::GetInstance()
   {
      return &g_console;
   }

   std::unique_ptr<CharBuffer> Console::createChrBuffer(std::initializer_list<char> buffer, const Rect& rc)
   {
      return std::unique_ptr<CharBuffer>(new CharBufferType(buffer, rc));
   }
} // namespace console