// Copyright 2019 <Andrei Avram>
#include "Apixu/Response/Error.h"

#include <string>

namespace Apixu {
    namespace Response {
        int Error::getCode() const {
            return code;
        }

        const string &Error::getMessage() const {
            return message;
        }

        const Error &ErrorResponse::getError() const {
            return error;
        }
    }  // namespace Response
}  // namespace Apixu
