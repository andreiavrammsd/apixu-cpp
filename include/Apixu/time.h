// Copyright 2019 <Andrei Avram>
#ifndef INCLUDE_APIXU_TIME_H_
#define INCLUDE_APIXU_TIME_H_

#include <string>

namespace apixu {
class Time {
   public:
    static struct tm parse(const std::string &input);

    virtual ~Time() = default;
};
}  // namespace apixu

#endif  // INCLUDE_APIXU_TIME_H_
