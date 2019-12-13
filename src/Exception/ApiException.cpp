// Copyright 2019 <Andrei Avram>
#include "Apixu/Exception/ApiException.h"

#include <string>
#include <utility>

#include "Apixu/Exception/ApixuException.h"

namespace Apixu {
    namespace Exception {
        using std::string;

        ApiException::ApiException(string message, int code) : ApixuException(move(message)), code(code) {}

        int ApiException::getCode() const {
            return code;
        }
    }  // namespace Exception
}  // namespace Apixu
