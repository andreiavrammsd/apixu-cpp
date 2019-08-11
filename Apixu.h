#ifndef APIXU_DEV_APIXU_H
#define APIXU_DEV_APIXU_H


#include "Condition.h"
#include <curl/curl.h>

using namespace std;

namespace Apixu {
    class Apixu {
    public:
        explicit Apixu(const string &apiKey);

        vector<Condition> conditions();

    private:
        const string &apiKey;
        const string docWeatherConditionsURL = "https://www.apixu.com/doc/Apixu_weather_conditions.json";

        static string get(const string &url) {
            auto curl = curl_easy_init();
            CURLcode res;
            string readBuffer;
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
            res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);
            return readBuffer;
        }

        static size_t writeCallback(void *contents, size_t size, size_t nmemb, void *userp) {
            ((std::string *) userp)->append((char *) contents, size * nmemb);
            return size * nmemb;
        }
    };
}

#endif //APIXU_DEV_APIXU_H
