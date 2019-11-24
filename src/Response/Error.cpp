#ifndef APIXU_ERROR_CPP
#define APIXU_ERROR_CPP


#include "Error.hpp"

namespace Apixu {
    namespace Response {
        using namespace std;
        using nlohmann::json;

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

#endif //APIXU_ERROR_CPP
