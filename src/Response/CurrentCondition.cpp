// Copyright 2019 <Andrei Avram>
#include "Apixu/Response/CurrentCondition.h"

#include <string>

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
    }  // namespace Response
}  // namespace Apixu
