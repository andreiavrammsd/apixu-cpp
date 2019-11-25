#ifndef APIXU_EXCEPTION_APIXU_EXCEPTION_
#define APIXU_EXCEPTION_APIXU_EXCEPTION_


#include <exception>
#include <string>

namespace Apixu {
    namespace Exception {
        using std::exception;
        using std::string;

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

#endif // APIXU_EXCEPTION_APIXU_EXCEPTION_
