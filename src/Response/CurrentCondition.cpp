#include "CurrentCondition.hpp"

namespace Apixu {
    namespace Response {
        const string *CurrentCondition::getText() const {
            return text;
        }

        string *CurrentCondition::getIcon() const {
            return icon;
        }

        int *CurrentCondition::getCode() const {
            return code;
        }
    }
}
