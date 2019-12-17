// Copyright 2019 <Andrei Avram>
#ifndef INCLUDE_APIXU_APIXU_H_
#define INCLUDE_APIXU_APIXU_H_


#include <string>
#include <vector>
#include <map>
#include <memory>

#include "Apixu/Response/Condition.h"
#include "Apixu/Response/CurrentWeather.h"
#include "Apixu/Response/Location.h"
#include "Apixu/Response/Forecast/WeatherForecast.h"
#include "Apixu/Response/WeatherHistory.h"
#include "Apixu/Http/Http.h"

namespace Apixu {
    using std::string;
    using std::vector;
    using std::map;
    using Apixu::Response::Condition;
    using Apixu::Response::CurrentWeather;
    using Apixu::Response::Location;
    using Apixu::Response::Forecast::WeatherForecast;
    using Apixu::Response::WeatherHistory;

    class Apixu {
    public:
        explicit Apixu(string apiKey);

        Apixu(string apiKey, Http::Http *httpClient);

        vector<Condition> Conditions();

        CurrentWeather Current(const string &q);

        vector<Location> Search(const string &q);

        WeatherForecast Forecast(const string &q, int days, const int *hour = nullptr);

        WeatherHistory History(const string &q, const string &since, string *until = nullptr);

        virtual ~Apixu();

    private:
        string apiKey;
        Http::Http *httpClient;

        const string API_URL = "http://localhost:5000/";
        const string API_FORMAT = "json";
        const string DOC_WEATHER_CONDITIONS_URL = "http://localhost:5000/conditions.json";
        const string USER_AGENT = "Apixu C++/0.1.0";

        string url(const string &method);

        string get(const string &url, map<string, string> params = {});
    };
}  // namespace Apixu

#endif  // INCLUDE_APIXU_APIXU_H_
