#ifndef APIXU_DEV_APIXU_H
#define APIXU_DEV_APIXU_H


#include "Response/Condition.cpp"
#include "Response/CurrentWeather.cpp"
#include "HTTP/HTTP.h"

using namespace std;
using namespace Apixu::Response;
using namespace Apixu::HTTP;

namespace Apixu {
    class Apixu {
    public:
        explicit Apixu(string apiKey);

        vector<Condition> conditions();
        CurrentWeather current(const string& q);
        vector<Location> search(const string& q);

        virtual ~Apixu();

    private:
        const string apiKey;
        HTTP::HTTP* httpClient;

        const string API_URL = "https://api.apixu.com/v1/";
        const string API_FORMAT = "json";
        const string DOC_WEATHER_CONDITIONS_URL = "https://www.apixu.com/doc/Apixu_weather_conditions.json";
        const string USER_AGENT = "Apixu C++/0.1.0";

        string url(const string &method);
        string get(const string &url, const map<string, string> *params);
    };
}

#endif //APIXU_DEV_APIXU_H
