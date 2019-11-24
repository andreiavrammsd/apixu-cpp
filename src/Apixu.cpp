#include "Apixu.hpp"
#include "Exception/ApiException.cpp"
#include "Response/Error.cpp"

using Apixu::Exception::ApixuException;
using Apixu::Exception::ApiException;
using Apixu::HTTP::STATUS_INTERNAL_SERVER_ERROR;
using Apixu::HTTP::STATUS_BAD_REQUEST;
using Apixu::Response::ErrorResponse;

namespace Apixu {
    using std::exception;
    using std::to_string;

    Apixu::Apixu(string apiKey) : apiKey(move(apiKey)) {
        httpClient = new HTTP::Client(USER_AGENT);
    }

    Apixu::~Apixu() {
        delete httpClient;
    }

    vector<Condition> Apixu::conditions() {
        try {
            return json::parse(get(DOC_WEATHER_CONDITIONS_URL, nullptr));
        } catch (ApiException &e) {
            throw ApiException(e.what(), e.getCode());
        } catch (exception &e) {
            throw ApixuException(e.what());
        }
    }

    CurrentWeather Apixu::current(const string& q) {
        map<string, string> params;
        params["key"] = apiKey;
        params["q"] = q;

        try {
            return json::parse(get(url("current"), &params));
        } catch (ApiException &e) {
            throw ApiException(e.what(), e.getCode());
        } catch (exception &e) {
            throw ApixuException(e.what());
        }
    }

    vector<Location> Apixu::search(const string &q) {
        map<string, string> params;
        params["key"] = apiKey;
        params["q"] = q;

        try {
            return json::parse(get(url("search"), &params));
        } catch (ApiException &e) {
            throw ApiException(e.what(), e.getCode());
        } catch (exception &e) {
            throw ApixuException(e.what());
        }
    }

    Forecast Apixu::forecast(const string &q, int days, const int *hour) {
        map<string, string> params;
        params["key"] = apiKey;
        params["q"] = q;
        params["days"] = to_string(days);
        if (hour) {
            params["hour"] = to_string(*hour);
        }

        try {
            return json::parse(get(url("forecast"), &params));
        } catch (ApiException &e) {
            throw ApiException(e.what(), e.getCode());
        } catch (exception &e) {
            throw ApixuException(e.what());
        }
    }

    History Apixu::history(const string &q, const string& since, string *until) {
        map<string, string> params;
        params["key"] = apiKey;
        params["q"] = q;
        params["dt"] = since;
        if (until) {
            params["end_dt"] = *until;
        }

        try {
            return json::parse(get(url("history"), &params));
        } catch (ApiException &e) {
            throw ApiException(e.what(), e.getCode());
        } catch (exception &e) {
            throw ApixuException(e.what());
        }
    }

    string Apixu::url(const string& method) {
        return API_URL + method + "." + API_FORMAT;
    }

    string Apixu::get(const string &url, const map<string, string>* params) {
        auto response = httpClient->get(url, params);
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
