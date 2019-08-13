#include "CurrentCondition.h"

namespace Apixu {
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
