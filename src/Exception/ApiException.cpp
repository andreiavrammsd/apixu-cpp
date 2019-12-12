#include <string>
#include "Apixu/Exception/ApixuException.h"
#include "Apixu/Exception/ApiException.h"

namespace Apixu {
    namespace Exception {
        using std::string;

        ApiException::ApiException(string message, int code) : ApixuException(move(message)), code(code) {}

        int ApiException::getCode() const {
            return code;
        }
    }
}
