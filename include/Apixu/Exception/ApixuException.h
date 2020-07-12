// Copyright 2019 <Andrei Avram>
#ifndef INCLUDE_APIXU_EXCEPTION_APIXUEXCEPTION_H_
#define INCLUDE_APIXU_EXCEPTION_APIXUEXCEPTION_H_

#include <exception>
#include <string>
#include <utility>

namespace Apixu {
namespace Exception {
class ApixuException : public std::exception {
   public:
    explicit ApixuException(const std::string &msg) : msg(msg) {}

    const char *what() const noexcept override { return msg.c_str(); }

   private:
    const std::string msg;
};
}  // namespace Exception
}  // namespace Apixu

#endif  // INCLUDE_APIXU_EXCEPTION_APIXUEXCEPTION_H_
