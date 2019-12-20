// Copyright 2019 <Andrei Avram>
#ifndef INCLUDE_APIXU_RESPONSE_CURRENTCONDITION_H_
#define INCLUDE_APIXU_RESPONSE_CURRENTCONDITION_H_

#include <string>
#include <memory>

#include "nlohmann/json.hpp"

namespace Apixu {
    namespace Response {
        class CurrentCondition {
        public:
            std::shared_ptr<std::string> getText() const;

            std::shared_ptr<std::string> getIcon() const;

            std::shared_ptr<int> getCode() const;

            virtual ~CurrentCondition() = default;

        private:
            std::shared_ptr<std::string> text{};
            std::shared_ptr<std::string> icon{};
            std::shared_ptr<int> code{};

            friend void from_json(const nlohmann::json &j, CurrentCondition &c); // NOLINT
        };

        inline void from_json(const nlohmann::json &j, CurrentCondition &c) { // NOLINT
            c.text = std::make_shared<std::string>(j.at("text"));
            c.icon = std::make_shared<std::string>(j.at("icon"));
            c.code = std::make_shared<int>(j.at("code"));
        }
    }  // namespace Response
}  // namespace Apixu

#endif  // INCLUDE_APIXU_RESPONSE_CURRENTCONDITION_H_
