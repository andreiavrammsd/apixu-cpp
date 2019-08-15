#ifndef APIXU_DEV_EXCEPTION
#define APIXU_DEV_EXCEPTION


#include <stdexcept>

using namespace std;

namespace Apixu {
    namespace Exception {
        class ApixuException : public exception {
        public:
            explicit ApixuException(string msg) : msg(move(msg)) {}

            const char* what() const noexcept override {
                return msg.c_str();
            }

        private:
            string msg;
        };
    }
}


#endif //APIXU_DEV_EXCEPTION
