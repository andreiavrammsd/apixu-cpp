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

        string API_URL = "https://api.apixu.com/v1/";
        string API_FORMAT = "json";
        string API_KEY_PARAM = "key";
        string DOC_WEATHER_CONDITIONS_URL = "https://www.apixu.com/doc/Apixu_weather_conditions.json";

        string url(const string &method, const map<string, string> &params);
        static string get(const string &url);
        static size_t writeCallback(void *contents, size_t size, size_t nmemb, void *userp);
    };
}

#endif //APIXU_DEV_APIXU_H
