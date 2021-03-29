#include "console.h"

#ifdef _WIN32
   #include "win/win_console.h"
   typedef sn::WinConsole ConsoleImplType;
#endif

namespace sn
{
   ConsoleImplType g_console;

   Console* Console::GetInstance()
   {
      return &g_console;
   }
} // namespace sn
