#include <utility>

#include "ApixuException.cpp"

using namespace std;

namespace Apixu {
    namespace Exception {
        class FatalErrorException : public ApixuException {
        public:
            explicit FatalErrorException(string msg) : msg(move(msg)) {}

            const char* what() const noexcept override {
                return msg.c_str();
            }
        private:
            string msg;
        };
    }
}
