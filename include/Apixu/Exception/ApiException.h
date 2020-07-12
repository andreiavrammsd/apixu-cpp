// Copyright 2019 <Andrei Avram>
#ifndef INCLUDE_APIXU_EXCEPTION_APIEXCEPTION_H_
#define INCLUDE_APIXU_EXCEPTION_APIEXCEPTION_H_

#include <string>

#include "ApixuException.h"

namespace Apixu {
namespace Exception {
class ApiException : public ApixuException {
   public:
    ApiException(const std::string& message, int code)
        : ApixuException(message), code(code)
    {
    }

    int getCode() const { return code; }

   private:
    int code;
};
}  // namespace Exception
}  // namespace Apixu

#endif  // INCLUDE_APIXU_EXCEPTION_APIEXCEPTION_H_
