#ifndef APIXU_TIME_H_
#define APIXU_TIME_H_


#include <string>

namespace Apixu {
    using std::string;

    class Time {
    public:
        static struct tm parse(const string &input);

        virtual ~Time() = default;
    };
}

#endif // APIXU_TIME_H_
