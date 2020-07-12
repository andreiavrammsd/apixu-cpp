// Copyright 2019 <Andrei Avram>
#include "Apixu/Exception/ApixuException.h"

#include <exception>
#include <string>
#include <utility>

namespace Apixu {
namespace Exception {
ApixuException::ApixuException(std::string msg) : msg(move(msg)) {}

const char *ApixuException::what() const noexcept { return msg.c_str(); }
}  // namespace Exception
}  // namespace Apixu
