#ifndef APIXU_CONDITION_CPP
#define APIXU_CONDITION_CPP

#include "../../include/nlohmann/json.hpp"

using namespace std;
using nlohmann::json;

namespace Apixu {
    namespace Response {
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
    }
}

#endif //APIXU_CONDITION_CPP
