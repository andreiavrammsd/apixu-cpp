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
            std::shared_ptr<string> getText() const;

            std::shared_ptr<string> getIcon() const;

            std::shared_ptr<int> getCode() const;

            virtual ~CurrentCondition() = default;

        private:
            std::shared_ptr<string> text{};
            std::shared_ptr<string> icon{};
            std::shared_ptr<int> code{};

            friend void from_json(const json &j, CurrentCondition &c); // NOLINT
        };

        inline void from_json(const json &j, CurrentCondition &c) { // NOLINT
            c.text = std::make_shared<string>(j.at("text"));
            c.icon = std::make_shared<string>(j.at("icon"));
            c.code = std::make_shared<int>(j.at("code"));
        }
    }  // namespace Response
}  // namespace Apixu

#endif  // INCLUDE_APIXU_RESPONSE_CURRENTCONDITION_H_
