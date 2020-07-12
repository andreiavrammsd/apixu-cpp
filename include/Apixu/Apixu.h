// Copyright 2019 <Andrei Avram>
#ifndef INCLUDE_APIXU_APIXU_H_
#define INCLUDE_APIXU_APIXU_H_

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "Apixu/Http/Http.h"
#include "Apixu/Response/Condition.h"
#include "Apixu/Response/CurrentWeather.h"
#include "Apixu/Response/Forecast/WeatherForecast.h"
#include "Apixu/Response/Location.h"
#include "Apixu/Response/WeatherHistory.h"

namespace Apixu {
class Apixu {
   public:
    explicit Apixu(std::string apiKey);

    Apixu(std::string apiKey, Http::Http *httpClient);

    std::vector<Response::Condition> Conditions();

    Response::CurrentWeather Current(const std::string &q);

    std::vector<Response::Location> Search(const std::string &q);

    Response::Forecast::WeatherForecast Forecast(const std::string &q, int days,
                                                 const int *hour = nullptr);

    Response::WeatherHistory History(const std::string &q,
                                     const std::string &since,
                                     std::string *until = nullptr);

    virtual ~Apixu();

   private:
    std::string apiKey;
    Http::Http *httpClient;

    const std::string API_URL = "http://localhost:5000/";
    const std::string API_FORMAT = "json";
    const std::string DOC_WEATHER_CONDITIONS_URL =
        "http://localhost:5000/conditions.json";
    const std::string USER_AGENT = "Apixu C++/0.1.0";

    std::string url(const std::string &method);

    std::string get(const std::string &url,
                    std::map<std::string, std::string> params = {});
};
}  // namespace Apixu

#endif  // INCLUDE_APIXU_APIXU_H_
