#include "Apixu/Response/Condition.hpp"

namespace Apixu {
    namespace Response {
        using std::string;

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
