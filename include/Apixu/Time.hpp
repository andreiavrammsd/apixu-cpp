#ifndef APIXU_TIME_HPP_
#define APIXU_TIME_HPP_


#include <string>

namespace Apixu {
    using std::string;

    class Time {
    public:
        static struct tm parse(const string &input);

        virtual ~Time() = default;
    };
}

#endif // APIXU_TIME_HPP_
