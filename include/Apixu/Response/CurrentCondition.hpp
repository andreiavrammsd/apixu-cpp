#ifndef APIXU_RESPONSE_CURRENT_CONDITION_HPP_
#define APIXU_RESPONSE_CURRENT_CONDITION_HPP_


#include "nlohmann/json.hpp"

namespace Apixu {
    using std::string;
    using nlohmann::json;

    namespace Response {
        class CurrentCondition {
        public:
            const string *getText() const;

            string *getIcon() const;

            int *getCode() const;

            virtual ~CurrentCondition() = default;

        private:
            string *text{};
            string *icon{};
            int *code{};

            friend void from_json(const json &j, CurrentCondition &c);
        };

        inline void from_json(const json &j, CurrentCondition &c) {
            c.text = new string(j.at("text").get<string>());
            c.icon = new string(j.at("icon").get<string>());
            c.code = new int(j.at("code").get<int>());
        }
    }
}

#endif // APIXU_RESPONSE_CURRENT_CONDITION_HPP_
