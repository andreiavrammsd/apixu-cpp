// Copyright 2019 <Andrei Avram>
#ifndef INCLUDE_APIXU_EXCEPTION_APIEXCEPTION_H_
#define INCLUDE_APIXU_EXCEPTION_APIEXCEPTION_H_


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
    }  // namespace Exception
}  // namespace Apixu

#endif  // INCLUDE_APIXU_EXCEPTION_APIEXCEPTION_H_
