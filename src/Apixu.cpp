#include "Apixu/Apixu.h"

#include "Apixu/Exception/ApiException.h"
#include "Apixu/Response/Error.h"

using Apixu::Exception::ApixuException;
using Apixu::Exception::ApiException;
using Apixu::Http::STATUS_INTERNAL_SERVER_ERROR;
using Apixu::Http::STATUS_BAD_REQUEST;
using Apixu::Response::ErrorResponse;

namespace Apixu {
    using std::exception;
    using std::to_string;

    Apixu::Apixu(string apiKey) : apiKey(move(apiKey)) {
        httpClient = std::make_unique<Http::Client>(Http::Client(USER_AGENT));
    }

    Apixu::Apixu(string apiKey, Http::Http *httpClient) : apiKey(move(apiKey)), httpClient(httpClient) {
    }

    vector<Condition> Apixu::Conditions() {
        try {
            return json::parse(get(DOC_WEATHER_CONDITIONS_URL));
        } catch (ApiException &e) {
            throw ApiException(e.what(), e.getCode());
        } catch (exception &e) {
            throw ApixuException(e.what());
        }
    }

    CurrentWeather Apixu::Current(const string &q) {
        map<string, string> params;
        params["key"] = apiKey;
        params["q"] = q;

        try {
            return json::parse(get(url("current"), params));
        } catch (ApiException &e) {
            throw ApiException(e.what(), e.getCode());
        } catch (exception &e) {
            throw ApixuException(e.what());
        }
    }

    vector<Location> Apixu::Search(const string &q) {
        map<string, string> params;
        params["key"] = apiKey;
        params["q"] = q;

        try {
            return json::parse(get(url("search"), params));
        } catch (ApiException &e) {
            throw ApiException(e.what(), e.getCode());
        } catch (exception &e) {
            throw ApixuException(e.what());
        }
    }

    WeatherForecast Apixu::Forecast(const string &q, int days, const int *hour) {
        map<string, string> params;
        params["key"] = apiKey;
        params["q"] = q;
        params["days"] = to_string(days);
        if (hour) {
            params["hour"] = to_string(*hour);
        }

        try {
            return json::parse(get(url("forecast"), params));
        } catch (ApiException &e) {
            throw ApiException(e.what(), e.getCode());
        } catch (exception &e) {
            throw ApixuException(e.what());
        }
    }

    WeatherHistory Apixu::History(const string &q, const string &since, string *until) {
        map<string, string> params;
        params["key"] = apiKey;
        params["q"] = q;
        params["dt"] = since;
        if (until) {
            params["end_dt"] = *until;
        }

        try {
            return json::parse(get(url("history"), params));
        } catch (ApiException &e) {
            throw ApiException(e.what(), e.getCode());
        } catch (exception &e) {
            throw ApixuException(e.what());
        }
    }

    string Apixu::url(const string &method) {
        return API_URL + method + "." + API_FORMAT;
    }

    string Apixu::get(const string &url, map<string, string> params) {
        auto response = httpClient->get(url, std::move(params));
        int status = response->getStatus();
        string body = response->getBody();
        delete response;

        if (status >= STATUS_INTERNAL_SERVER_ERROR) {
            throw ApixuException("Internal Server Error");
        } else if (status >= STATUS_BAD_REQUEST) {
            ErrorResponse errRes = json::parse(body);
            throw ApiException(errRes.getError().getMessage(), errRes.getError().getCode());
        }

        return body;
    }
}
