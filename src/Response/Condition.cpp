// Copyright 2019 <Andrei Avram>
#include "Apixu/Response/Condition.h"

#include <string>

namespace Apixu {
namespace Response {
int Condition::getCode() const { return code; }

const std::string &Condition::getDay() const { return day; }

const std::string &Condition::getNight() const { return night; }

int Condition::getIcon() const { return icon; }
}  // namespace Response
}  // namespace Apixu
