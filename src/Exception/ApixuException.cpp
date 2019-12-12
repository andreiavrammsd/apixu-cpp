#include <exception>
#include <string>
#include <Apixu/Exception/ApixuException.h>

namespace Apixu {
    namespace Exception {
        using std::exception;
        using std::string;

        ApixuException::ApixuException(string msg) : msg(move(msg)) {}

        const char *ApixuException::what() const noexcept {
            return msg.c_str();
        }
    }
}
