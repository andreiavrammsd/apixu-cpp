#include <string>

using namespace std;

namespace Apixu {
    namespace HTTP {
        class Exception : public exception {
        public:
            explicit Exception(string msg) : msg(move(msg)) {}
            const char* what() const noexcept override {
                return msg.c_str();
            }

        private:
            string msg;
        };
    }
}
