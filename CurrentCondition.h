#ifndef APIXU_DEV_CURRENTCONDITION_H
#define APIXU_DEV_CURRENTCONDITION_H


#include "include/nlohmann/json.hpp"

using namespace std;
using nlohmann::json;

namespace Apixu {
    class CurrentCondition {
    public:
        const string* getText() const;

        string* getIcon() const;

        int* getCode() const;

    private:
        string* text{};
        string* icon{};
        int* code{};

        friend void from_json(const json &j, CurrentCondition &c);
    };

    inline void from_json(const json &j, CurrentCondition &c) {
        c.text = new string(j.at("text").get<string>());
        c.icon = new string(j.at("icon").get<string>());
        c.code = new int(j.at("code").get<int>());
    }
}

#endif //APIXU_DEV_CURRENTCONDITION_H
