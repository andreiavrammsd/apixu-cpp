#include "Apixu/Response/Forecast/Astro.h"

namespace Apixu {
    namespace Response {
        namespace Forecast {
            const string &Astro::getSunrise() const {
                return sunrise;
            }

            const string &Astro::getSunset() const {
                return sunset;
            }

            const string &Astro::getMoonrise() const {
                return moonrise;
            }

            const string &Astro::getMoonset() const {
                return moonset;
            }

            const string &Astro::getMoonPhase() const {
                return moonPhase;
            }

            const string &Astro::getMoonIllumination() const {
                return moonIllumination;
            }
        }
    }
}
