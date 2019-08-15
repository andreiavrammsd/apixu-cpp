#ifndef APIXU_TIME_H
#define APIXU_TIME_H

#include <string>

using namespace std;

namespace Apixu {
    class Time {
    public:
        static struct tm parse(const string& input);
    };
}


#endif //APIXU_TIME_H
