#include "Condition.hpp"

using namespace std;

namespace Apixu {
    namespace Response {
        int Condition::getCode() const {
            return code;
        }

        const string &Condition::getDay() const {
            return day;
        }

        const string &Condition::getNight() const {
            return night;
        }

        int Condition::getIcon() const {
            return icon;
        }
    };
}
