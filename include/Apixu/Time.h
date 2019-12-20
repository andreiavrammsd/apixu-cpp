// Copyright 2019 <Andrei Avram>
#ifndef INCLUDE_APIXU_TIME_H_
#define INCLUDE_APIXU_TIME_H_


#include <string>

namespace Apixu {
    class Time {
    public:
        static struct tm parse(const std::string &input);

        virtual ~Time() = default;
    };
}  // namespace Apixu

#endif  // INCLUDE_APIXU_TIME_H_
