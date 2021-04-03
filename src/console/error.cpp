#include "error.h"

#include <string>
#include <windows.h>
#include <lmerr.h>
#include <Wininet.h>

namespace console
{
   void ShowLastError()
   {
      HMODULE hmodule = NULL;
      DWORD flags =
         FORMAT_MESSAGE_ALLOCATE_BUFFER |
         FORMAT_MESSAGE_FROM_SYSTEM |
         FORMAT_MESSAGE_IGNORE_INSERTS;
      LPSTR msgbuf = NULL;

      DWORD errorCode = GetLastError();

      if (errorCode >= NERR_BASE && errorCode <= MAX_NERR) {
         hmodule = LoadLibraryEx("netmsg.dll",
                  NULL, LOAD_LIBRARY_AS_DATAFILE);
         if (hmodule)
            flags |= FORMAT_MESSAGE_FROM_HMODULE;
      }
      else if (errorCode >= INTERNET_ERROR_BASE && errorCode <= INTERNET_ERROR_LAST) {
         hmodule = LoadLibraryEx("wininet.dll",
                  NULL, LOAD_LIBRARY_AS_DATAFILE);
         if (hmodule)
            flags |= FORMAT_MESSAGE_FROM_HMODULE;
      }

      if (!FormatMessageA(flags,
                  hmodule,
                  errorCode,
                  MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                  reinterpret_cast<LPSTR>(&msgbuf),
                  0, NULL)) {
         msgbuf = NULL;
      }

      if (hmodule)
         FreeLibrary(hmodule);

      std::string msg;
      msg += std::to_string(errorCode);
      msg += " - ";
      if (msgbuf) {
         msg += msgbuf;
         LocalFree(msgbuf);
      }

      ::MessageBox(NULL, msg.c_str(), "Fatal Error", MB_ICONERROR | MB_OK);
   }
} // namespace console