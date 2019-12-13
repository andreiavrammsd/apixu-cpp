// Copyright 2019 <Andrei Avram>
#ifndef INCLUDE_APIXU_RESPONSE_CURRENTCONDITION_H_
#define INCLUDE_APIXU_RESPONSE_CURRENTCONDITION_H_

#include <string>

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

            friend void from_json(const json &j, CurrentCondition &c); // NOLINT
        };

        inline void from_json(const json &j, CurrentCondition &c) { // NOLINT
            c.text = new string(j.at("text"));
            c.icon = new string(j.at("icon"));
            c.code = new int(j.at("code"));
        }
    }  // namespace Response
}  // namespace Apixu

#endif  // INCLUDE_APIXU_RESPONSE_CURRENTCONDITION_H_
