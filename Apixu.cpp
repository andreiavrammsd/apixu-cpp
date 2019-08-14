#include <sstream>
#include <iostream>
#include "Apixu.h"
#include "include/nlohmann/json.hpp"

namespace Apixu {
    Apixu::Apixu(string apiKey) : apiKey(move(apiKey)) {}

    vector<Condition> Apixu::conditions() {
        return json::parse(get(DOC_WEATHER_CONDITIONS_URL));
    }

    CurrentWeather Apixu::current(const string& q) {
        map<string, string> params;
        params["q"] = q;
        return json::parse(get(url("current", params)));
    }

    string Apixu::url(const string& method, const map<string, string>& params) {
        ostringstream url;
        url << API_URL << method << "." << API_FORMAT << "?" << API_KEY_PARAM << "=" << apiKey << "&";

        for (auto iter = params.begin(); iter != params.end();) {
            url << iter->first << "=" << iter->second;
            if (next(iter) != params.end()) {
                url << "&";
            }
            ++iter;
        }

        return url.str();
    }

    string Apixu::get(const string &url) {
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

    size_t Apixu::writeCallback(void *contents, size_t size, size_t nmemb, void *userp) {
        ((std::string *) userp)->append((char *) contents, size * nmemb);
        return size * nmemb;
    }
}
