// Copyright 2019 <Andrei Avram>
#include "Apixu/time.h"

#include <string>

namespace apixu {
struct tm apixu::Time::parse(const std::string &input)
{
    struct tm time {
        0
    };
    int year = 0, month = 0, day = 0, hour = 0, min = 0;

    const char *format = "%4d-%2d-%2d %2d:%2d";
    const int number_of_fields_converted = 5;

    if (sscanf(input.c_str(), format, &year, &month, &day, &hour, &min) ==
        number_of_fields_converted) {
        time.tm_year = year - 1900;
        time.tm_mon = month - 1;
        time.tm_mday = day;
        time.tm_hour = hour;
        time.tm_min = min;
    }

    return time;
}
}  // namespace apixu
