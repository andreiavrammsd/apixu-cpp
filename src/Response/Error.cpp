#include "Apixu/Response/Error.h"

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
    }
}
