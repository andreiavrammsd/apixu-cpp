// Copyright 2019 <Andrei Avram>
#include "Apixu/Response/CurrentCondition.h"

#include <string>
#include <memory>

namespace Apixu {
    namespace Response {
        std::shared_ptr<std::string> CurrentCondition::getText() const {
            return text;
        }

        std::shared_ptr<std::string> CurrentCondition::getIcon() const {
            return icon;
        }

        std::shared_ptr<int> CurrentCondition::getCode() const {
            return code;
        }
    }  // namespace Response
}  // namespace Apixu
