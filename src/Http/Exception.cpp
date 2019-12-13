// Copyright 2019 <Andrei Avram>
#include <string>
#include <exception>
#include <utility>

namespace Apixu {
    namespace Http {
        using std::exception;
        using std::string;

        class Exception : public exception {
        public:
            explicit Exception(string msg) : msg(move(msg)) {}

            const char *what() const noexcept override {
                return msg.c_str();
            }

        private:
            string msg;
        };
    }  // namespace Http
}  // namespace Apixu
