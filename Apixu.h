#ifndef APIXU_DEV_APIXU_H
#define APIXU_DEV_APIXU_H


#include "Condition.h"
#include "CurrentWeather.h"
#include <curl/curl.h>

using namespace std;

namespace Apixu {
    class Apixu {
    public:
        explicit Apixu(string apiKey);

        vector<Condition> conditions();
        CurrentWeather current(const string& q);

    private:
        const string apiKey;

        const string API_URL = "https://api.apixu.com/v1/";
        const string API_FORMAT = "json";
        const string API_KEY_PARAM = "key";
        const string DOC_WEATHER_CONDITIONS_URL = "https://www.apixu.com/doc/Apixu_weather_conditions.json";
        const string USER_AGENT = "Apixu C++/0.1.0";

        string url(const string &method, const map<string, string> &params);
        string get(const string &url);
        static size_t writeCallback(void *contents, size_t size, size_t nmemb, void *userp);
    };
}

#endif //APIXU_DEV_APIXU_H
