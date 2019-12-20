// Copyright 2019 <Andrei Avram>
#include "Apixu/Response/Forecast/Astro.h"

#include <string>

namespace Apixu {
    namespace Response {
        namespace Forecast {
            const std::string &Astro::getSunrise() const {
                return sunrise;
            }

            const std::string &Astro::getSunset() const {
                return sunset;
            }

            const std::string &Astro::getMoonrise() const {
                return moonrise;
            }

            const std::string &Astro::getMoonset() const {
                return moonset;
            }

            const std::string &Astro::getMoonPhase() const {
                return moonPhase;
            }

            const std::string &Astro::getMoonIllumination() const {
                return moonIllumination;
            }
        }  // namespace Forecast
    }  // namespace Response
}  // namespace Apixu
