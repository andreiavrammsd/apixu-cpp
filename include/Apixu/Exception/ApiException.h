#ifndef APIXU_EXCEPTION_API_EXCEPTION_H_
#define APIXU_EXCEPTION_API_EXCEPTION_H_


#include <string>

#include "ApixuException.h"

namespace Apixu {
    namespace Exception {
        using std::string;

        class ApiException : public ApixuException {
        public:
            ApiException(string message, int code);

            int getCode() const;

        private:
            int code;
        };
    }
}

#endif // APIXU_EXCEPTION_API_EXCEPTION_H_
