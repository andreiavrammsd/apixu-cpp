#ifndef APIXU_DEV_CONDITION_H
#define APIXU_DEV_CONDITION_H

#include "include/nlohmann/json.hpp"

using namespace std;
using nlohmann::json;

class Condition {
public:
    int getCode() const;

    const string &getDay() const;

    const string &getNight() const;

    int getIcon() const;

private:
    int code{};
    string day{};
    string night{};
    int icon{};

    friend void from_json(const json &j, Condition &c);
};

inline void from_json(const json &j, Condition &c) {
    c.code = j.at("code").get<int>();
    c.day = j.at("day").get<string>();
    c.night = j.at("night").get<string>();
    c.icon = j.at("icon").get<int>();
}

#endif //APIXU_DEV_CONDITION_H
