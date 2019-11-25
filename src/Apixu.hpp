#ifndef APIXU_APIXU_HPP_
#define APIXU_APIXU_HPP_


#include <string>
#include <vector>
#include <map>
#include "Response/Condition.hpp"
#include "Response/CurrentWeather.hpp"
#include "Response/Location.hpp"
#include "Response/Forecast/WeatherForecast.hpp"
#include "Response/WeatherHistory.hpp"
#include "HTTP/HTTP.hpp"

using std::string;
using std::vector;
using std::map;
using Apixu::Response::Condition;
using Apixu::Response::CurrentWeather;
using Apixu::Response::Location;
using Apixu::Response::Forecast::WeatherForecast;
using Apixu::Response::WeatherHistory;
using Apixu::HTTP::HTTP;

namespace Apixu {
    class Apixu {
    public:
        explicit Apixu(string apiKey);
        Apixu(string apiKey, HTTP::HTTP *httpClient);

        vector<Condition> Conditions();

        CurrentWeather Current(const string &q);

        vector<Location> Search(const string &q);

        WeatherForecast Forecast(const string &q, int days, const int *hour = nullptr);

        WeatherHistory History(const string &q, const string &since, string *until = nullptr);

        virtual ~Apixu();

    private:
        string apiKey;
        HTTP::HTTP *httpClient;

        const string API_URL = "http://localhost:5000/";
        const string API_FORMAT = "json";
        const string DOC_WEATHER_CONDITIONS_URL = "http://localhost:5000/conditions.json";
        const string USER_AGENT = "Apixu C++/0.1.0";

        string url(const string &method);

        string get(const string &url, const map<string, string> *params);
    };
}

#endif // APIXU_APIXU_HPP_
