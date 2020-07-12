// Copyright 2019 <Andrei Avram>
#include <exception>
#include <string>
#include <utility>

namespace apixu {
namespace http {
class Exception : public std::exception {
   public:
    explicit Exception(const std::string& msg) : msg_(msg) {}

    const char* what() const noexcept override { return msg_.c_str(); }

   private:
    const std::string msg_;
};
}  // namespace http
}  // namespace apixu
