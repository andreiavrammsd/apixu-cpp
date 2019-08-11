#ifndef APIXU_DEV_APIXU_H
#define APIXU_DEV_APIXU_H


#include "Condition.h"
#include "CurrentWeather.h"
#include <curl/curl.h>

using namespace std;

namespace Apixu {
    class Apixu {
    public:
        explicit Apixu(const string &apiKey);

        vector<Condition> conditions();
        CurrentWeather current(const string& q);

    private:
        const string &apiKey;
        const string docWeatherConditionsURL = "https://www.apixu.com/doc/Apixu_weather_conditions.json";

        static string get(const string &url);
        string url(const string &method, const map<string, string> &params);
        static size_t writeCallback(void *contents, size_t size, size_t nmemb, void *userp);
    };
}

#endif //APIXU_DEV_APIXU_H
