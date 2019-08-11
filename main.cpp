#include <iostream>
#include <vector>
#include <curl/curl.h>
#include "include/nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

class Condition {
public:
    int getCode() const {
        return code;
    }

    const string &getDay() const {
        return day;
    }

    const string &getNight() const {
        return night;
    }

    int getIcon() const {
        return icon;
    }

    friend void from_json(const json& j, Condition& c);

private:
    int code{};
    string day;
    string night;
    int icon{};
};

inline void from_json(const json & j, Condition& c) {
    c.code = j.at("code").get<int>();
    c.day = j.at("day").get<string>();
    c.night = j.at("night").get<string>();
    c.icon = j.at("icon").get<int>();
}

class Apixu {
public:
    explicit Apixu(const string &apiKey): apiKey(apiKey) {
    }

    vector<Condition> conditions() {
        vector<Condition> conditions = json::parse(get(docWeatherConditionsURL));
        return conditions;
    }
private:
    const string &apiKey;
    const string docWeatherConditionsURL = "https://www.apixu.com/doc/Apixu_weather_conditions.json";

    static string get(const string& url) {
        auto curl = curl_easy_init();
        CURLcode res;
        string readBuffer;
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        cout << "result " << res << endl;
        curl_easy_cleanup(curl);
        return readBuffer;
    }

    static size_t writeCallback(void *contents, size_t size, size_t nmemb, void *userp) {
        ((std::string*)userp)->append((char*)contents, size * nmemb);
        return size * nmemb;
    }
};

int main() {
    char* apiKey = getenv("APIXUKEY");
    if (apiKey == nullptr) {
        throw "APIXUKEY not set";
    }

    const string k = string(apiKey);
    auto apixu = new Apixu(k);
    auto conditions = apixu->conditions();

    for (const auto& c : conditions) {
        cout << "condition" << endl;
        cout << "\tcode: " << c.getCode() << endl;
        cout << "\tday: " << c.getDay() << endl;
        cout << "\tnight: " << c.getNight() << endl;
        cout << "\ticon: " << c.getIcon() << endl << endl;
    }

    cout << "Hello, World!" << endl;
    return 0;
}
