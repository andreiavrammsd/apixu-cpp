#ifndef APIXU_RESPONSE_CONDITION_H_
#define APIXU_RESPONSE_CONDITION_H_


#include <string>
#include "nlohmann/json.hpp"

namespace Apixu {
    namespace Response {
        using std::string;
        using nlohmann::json;

        class Condition {
        public:
            int getCode() const;

            const string &getDay() const;

            const string &getNight() const;

            int getIcon() const;

            virtual ~Condition() = default;

        private:
            int code{};
            string day{};
            string night{};
            int icon{};

            friend void from_json(const json &j, Condition &c);
        };

        inline void from_json(const json &j, Condition &c) {
            c.code = j.at("code");
            c.day = j.at("day");
            c.night = j.at("night");
            c.icon = j.at("icon");
        }
    }
}

#endif // APIXU_RESPONSE_CONDITION_H_
