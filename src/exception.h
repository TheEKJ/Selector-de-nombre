#ifndef _SN_EXCEPTION_H
#define _SN_EXCEPTION_H
#include <cstring>
#include <stdexcept>

namespace sn
{
   class Exception : public std::exception
   {
   public:
      Exception() noexcept;
      Exception(const std::string& msg) noexcept;
      
      const char* what() const noexcept;
   private:
      std::string m_msg;
   };
} // namespace sn


#endif