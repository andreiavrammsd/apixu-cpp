#ifndef APIXU_CURRENTCONDITION_CPP
#define APIXU_CURRENTCONDITION_CPP


#include "../../include/nlohmann/json.hpp"

using namespace std;
using nlohmann::json;

namespace Apixu {
    namespace Response {
        class CurrentCondition {
        public:
            const string *getText() const {
                return text;
            }

            string *getIcon() const {
                return icon;
            }

            int *getCode() const {
                return code;
            }

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

#endif //APIXU_CURRENTCONDITION_CPP
