#ifndef APIXU_EXCEPTION_APIXU_EXCEPTION_H_
#define APIXU_EXCEPTION_APIXU_EXCEPTION_H_


#include <exception>
#include <string>

namespace Apixu {
    namespace Exception {
        using std::exception;
        using std::string;

        class ApixuException : public exception {
        public:
            explicit ApixuException(string msg);

            const char *what() const noexcept override;

        private:
            string msg;
        };
    }
}

#endif // APIXU_EXCEPTION_APIXU_EXCEPTION_H_
