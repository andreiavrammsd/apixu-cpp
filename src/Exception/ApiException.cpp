#include "ApixuException.cpp"

namespace Apixu {
    namespace Exception {
        class ApiException : public ApixuException {
        public:
            ApiException(string message, int code) : ApixuException(move(message)), code(code) {}

            int getCode() const {
                return code;
            }

        private:
            int code;
        };
    }
}
