// Copyright 2019 <Andrei Avram>
#ifndef INCLUDE_APIXU_APIXU_H_
#define INCLUDE_APIXU_APIXU_H_

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "Apixu/Http/http.h"
#include "Apixu/Response/Forecast/weather_forecast.h"
#include "Apixu/Response/condition.h"
#include "Apixu/Response/current_weather.h"
#include "Apixu/Response/location.h"
#include "Apixu/Response/weather_history.h"

namespace apixu {
class Apixu {
   public:
    explicit Apixu(const std::string& api_key);

    Apixu(const std::string& api_key, http::Http* http_client);

    std::vector<response::Condition> Conditions();

    response::CurrentWeather Current(const std::string& q);

    std::vector<response::Location> Search(const std::string& q);

    response::forecast::WeatherForecast Forecast(const std::string& q, int days,
                                                 const int* hour = nullptr);

    response::WeatherHistory History(const std::string& q,
                                     const std::string& since,
                                     std::string* until = nullptr);

    virtual ~Apixu();

   private:
    const std::string api_key_;
    http::Http* http_client_;

    const std::string api_url_ = "http://localhost:5000/";
    const std::string api_format_ = "json";
    const std::string doc_weather_conditions_url_ =
        "http://localhost:5000/conditions.json";
    const std::string user_agent_ = "Apixu C++/0.1.0";

    std::string url(const std::string& method);

    std::string get(const std::string& url,
                    std::map<std::string, std::string> params = {});
};
}  // namespace apixu

#endif  // INCLUDE_APIXU_APIXU_H_