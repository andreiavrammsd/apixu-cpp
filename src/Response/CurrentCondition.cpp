// Copyright 2019 <Andrei Avram>
#include "Apixu/Response/CurrentCondition.h"

#include <string>
#include <memory>

namespace Apixu {
    namespace Response {
        std::shared_ptr<string> CurrentCondition::getText() const {
            return text;
        }

        std::shared_ptr<string> CurrentCondition::getIcon() const {
            return icon;
        }

        std::shared_ptr<int> CurrentCondition::getCode() const {
            return code;
        }
    }  // namespace Response
}  // namespace Apixu
