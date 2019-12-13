// Copyright 2019 <Andrei Avram>
#ifndef INCLUDE_APIXU_EXCEPTION_APIXUEXCEPTION_H_
#define INCLUDE_APIXU_EXCEPTION_APIXUEXCEPTION_H_


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
    }  // namespace Exception
}  // namespace Apixu

#endif  // INCLUDE_APIXU_EXCEPTION_APIXUEXCEPTION_H_
