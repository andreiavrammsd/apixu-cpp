// Copyright 2019 <Andrei Avram>
#include "Apixu/Apixu.h"

#include <map>
#include <string>
#include <utility>
#include <vector>

#include "Apixu/Exception/ApiException.h"
#include "Apixu/Response/Error.h"

namespace Apixu {
Apixu::Apixu(std::string apiKey) : apiKey(move(apiKey))
{
    httpClient = new Http::Client(USER_AGENT);
}

Apixu::Apixu(std::string apiKey, Http::Http *httpClient)
    : apiKey(move(apiKey)), httpClient(httpClient)
{
}

Apixu::~Apixu() { delete httpClient; }

std::vector<Response::Condition> Apixu::Conditions()
{
    try {
        return nlohmann::json::parse(get(DOC_WEATHER_CONDITIONS_URL));
    }
    catch (Exception::ApiException &e) {
        throw Exception::ApiException(e.what(), e.getCode());
    }
    catch (std::exception &e) {
        throw Exception::ApixuException(e.what());
    }
}

Response::CurrentWeather Apixu::Current(const std::string &q)
{
    std::map<std::string, std::string> params;
    params["key"] = apiKey;
    params["q"] = q;

    try {
        return nlohmann::json::parse(get(url("current"), params));
    }
    catch (Exception::ApiException &e) {
        throw Exception::ApiException(e.what(), e.getCode());
    }
    catch (std::exception &e) {
        throw Exception::ApixuException(e.what());
    }
}

std::vector<Response::Location> Apixu::Search(const std::string &q)
{
    std::map<std::string, std::string> params;
    params["key"] = apiKey;
    params["q"] = q;

    try {
        return nlohmann::json::parse(get(url("search"), params));
    }
    catch (Exception::ApiException &e) {
        throw Exception::ApiException(e.what(), e.getCode());
    }
    catch (std::exception &e) {
        throw Exception::ApixuException(e.what());
    }
}

Response::Forecast::WeatherForecast Apixu::Forecast(const std::string &q,
                                                    int days, const int *hour)
{
    std::map<std::string, std::string> params;
    params["key"] = apiKey;
    params["q"] = q;
    params["days"] = std::to_string(days);
    if (hour) {
        params["hour"] = std::to_string(*hour);
    }

    try {
        return nlohmann::json::parse(get(url("forecast"), params));
    }
    catch (Exception::ApiException &e) {
        throw Exception::ApiException(e.what(), e.getCode());
    }
    catch (std::exception &e) {
        throw Exception::ApixuException(e.what());
    }
}

Response::WeatherHistory Apixu::History(const std::string &q,
                                        const std::string &since,
                                        std::string *until)
{
    std::map<std::string, std::string> params;
    params["key"] = apiKey;
    params["q"] = q;
    params["dt"] = since;
    if (until) {
        params["end_dt"] = *until;
    }

    try {
        return nlohmann::json::parse(get(url("history"), params));
    }
    catch (Exception::ApiException &e) {
        throw Exception::ApiException(e.what(), e.getCode());
    }
    catch (std::exception &e) {
        throw Exception::ApixuException(e.what());
    }
}

std::string Apixu::url(const std::string &method)
{
    return API_URL + method + "." + API_FORMAT;
}

std::string Apixu::get(const std::string &url,
                       std::map<std::string, std::string> params)
{
    auto response = httpClient->get(url, std::move(params));
    int status = response->getStatus();
    std::string body = response->getBody();
    delete response;

    if (status >= Http::STATUS_INTERNAL_SERVER_ERROR) {
        throw Exception::ApixuException("Internal Server Error");
    }
    else if (status >= Http::STATUS_BAD_REQUEST) {
        Response::ErrorResponse errRes = nlohmann::json::parse(body);
        throw Exception::ApiException(errRes.getError().getMessage(),
                                      errRes.getError().getCode());
    }

    return body;
}
}  // namespace Apixu
