// Copyright 2019 <Andrei Avram>
#include <string>
#include <exception>
#include <utility>

namespace Apixu {
    namespace Http {
        class Exception : public std::exception {
        public:
            explicit Exception(std::string msg) : msg(move(msg)) {}

            const char *what() const noexcept override {
                return msg.c_str();
            }

        private:
            std::string msg;
        };
    }  // namespace Http
}  // namespace Apixu
