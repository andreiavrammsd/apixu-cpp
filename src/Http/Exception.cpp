#include <string>
#include <exception>

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
    }
}
