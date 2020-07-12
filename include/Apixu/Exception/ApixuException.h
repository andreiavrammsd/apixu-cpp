// Copyright 2019 <Andrei Avram>
#ifndef INCLUDE_APIXU_EXCEPTION_APIXUEXCEPTION_H_
#define INCLUDE_APIXU_EXCEPTION_APIXUEXCEPTION_H_

#include <exception>
#include <string>

namespace Apixu {
namespace Exception {
class ApixuException : public std::exception {
   public:
    explicit ApixuException(std::string msg);

    const char *what() const noexcept override;

   private:
    std::string msg;
};
}  // namespace Exception
}  // namespace Apixu

#endif  // INCLUDE_APIXU_EXCEPTION_APIXUEXCEPTION_H_
