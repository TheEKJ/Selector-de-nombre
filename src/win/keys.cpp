#include "keys.h"

namespace sn
{
   Keys win32_to_keys(int code)
   {
      switch(code) {
      case 0x08:  return Backspace_Key;   break;
      case 0x0D:  return Enter_Key;       break;
      case 0x1B:  return Escape_Key;      break;
      case 0x20:  return Space_Key;       break;
      case 0x25:  return Left_Key;        break;
      case 0x26:  return Up_Key;          break;
      case 0x27:  return Right_Key;       break;
      case 0x28:  return Down_Key;        break;
      default:    return Nil_Key;         break;
      }
   }
} // namespace sn
