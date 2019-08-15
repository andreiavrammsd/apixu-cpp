#include "ApixuException.cpp"

using namespace std;

namespace Apixu {
    namespace Exception {
        class ApiException : public ApixuException {
        public:
            ApiException(int code, string message) : ApixuException(), code(code), message(move(message)) {
            }

            int getCode() const {
                return code;
            }

            string getMessage() {
                return message;
            }

        private:
            int code;
            string message;
        };
    }
}
