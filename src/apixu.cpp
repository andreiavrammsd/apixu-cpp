// Copyright 2020 <Andrei Avram>
#include "Apixu/apixu.h"

#include <map>
#include <string>
#include <utility>
#include <vector>

#include "Apixu/Exception/api_exception.h"
#include "Apixu/Response/error.h"

namespace apixu {
Apixu::Apixu(const std::string& api_key) : api_key_(api_key)
{
    http_client_ = std::make_unique<http::Client>(user_agent_);
}

Apixu::Apixu(const std::string& api_key, std::unique_ptr<http::Http> http_client)
    : api_key_(api_key), http_client_(std::move(http_client))
{
    if (http_client_ == nullptr) {
        throw std::invalid_argument{"http client is null"};
    }
}

std::vector<response::Condition> Apixu::Conditions() const
{
    try {
        return nlohmann::json::parse(get(doc_weather_conditions_url_));
    }
    catch (exception::ApiException& e) {
        throw exception::ApiException(e.what(), e.getCode());
    }
    catch (std::exception& e) {
        throw exception::ApixuException(e.what());
    }
}

response::CurrentWeather Apixu::Current(const std::string& q) const
{
    std::map<std::string, std::string> params;
    params["key"] = api_key_;
    params["q"] = q;

    try {
        return nlohmann::json::parse(get(url("current"), params));
    }
    catch (exception::ApiException& e) {
        throw exception::ApiException(e.what(), e.getCode());
    }
    catch (std::exception& e) {
        throw exception::ApixuException(e.what());
    }
}

std::vector<response::Location> Apixu::Search(const std::string& q) const
{
    std::map<std::string, std::string> params;
    params["key"] = api_key_;
    params["q"] = q;

    try {
        return nlohmann::json::parse(get(url("search"), params));
    }
    catch (exception::ApiException& e) {
        throw exception::ApiException(e.what(), e.getCode());
    }
    catch (std::exception& e) {
        throw exception::ApixuException(e.what());
    }
}

response::forecast::WeatherForecast Apixu::Forecast(const std::string& q, const int days, const int* hour) const
{
    std::map<std::string, std::string> params;
    params["key"] = api_key_;
    params["q"] = q;
    params["days"] = std::to_string(days);
    if (hour != nullptr) {
        params["hour"] = std::to_string(*hour);
    }

    try {
        return nlohmann::json::parse(get(url("forecast"), params));
    }
    catch (exception::ApiException& e) {
        throw exception::ApiException(e.what(), e.getCode());
    }
    catch (std::exception& e) {
        throw exception::ApixuException(e.what());
    }
}

response::WeatherHistory Apixu::History(const std::string& q, const std::string& since, std::string* until) const
{
    std::map<std::string, std::string> params;
    params["key"] = api_key_;
    params["q"] = q;
    params["dt"] = since;
    if (until != nullptr) {
        params["end_dt"] = *until;
    }

    try {
        return nlohmann::json::parse(get(url("history"), params));
    }
    catch (exception::ApiException& e) {
        throw exception::ApiException(e.what(), e.getCode());
    }
    catch (std::exception& e) {
        throw exception::ApixuException(e.what());
    }
}

std::string Apixu::url(const std::string& method) const { return api_url_ + method + "." + api_format_; }

std::string Apixu::get(const std::string& url, const http::Parameters& params) const
{
    auto response = http_client_->Get(url, params);

    if (response.status >= http::Status::InternalServerError) {
        throw exception::ApixuException("Internal Server Error");
    }
    else if (response.status >= http::Status::BadRequest) {
        response::ErrorResponse errRes = nlohmann::json::parse(response.body);
        throw exception::ApiException(errRes.error.message, errRes.error.code);
    }

    return response.body;
}
}  // namespace apixu
