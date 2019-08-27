#include <iostream>
#include <vector>
#include "../src/Apixu.h"
#include "../src/Response/Location.cpp"
#include "../src/Exception/ApiException.cpp"

using namespace Apixu::Exception;
using namespace Apixu::Response;

int main() {
    const char *apiKey = getenv("APIXUKEY");
    if (!apiKey) {
        cout << "APIXUKEY not set";
        return 1;
    }

    auto apixu = new Apixu::Apixu(apiKey);

    CurrentWeather currentWeather;
    try {
        currentWeather = apixu->current("Paris");
    } catch (ApiException &e) {
        cout << "ApiException: " << e.what() << " (code: " << e.getCode() << ")";
        return 1;
    } catch (ApixuException &e) {
        cout << "ApixuException: " << e.what();
        return 1;
    }

    cout << "location" << endl;

    const Location& location = currentWeather.getLocation();

    cout << "\tname = " << location.getName() << endl;
    cout << "\tregion = " << location.getRegion() << endl;
    cout << "\tcountry = " << location.getCountry() << endl;
    cout << "\tlat = " << location.getLat() << endl;
    cout << "\tlon = " << location.getLon() << endl;
    cout << "\ttimezone = " << *location.getTimezone() << endl;
    cout << "\tlocaltime epoch = " << *location.getLocaltimeEpoch() << endl;

    auto localtime = location.getLocaltime();
    cout << "\tlocaltime:" << endl;
    cout << "\t\tyear = " << localtime.tm_year << ", month = " << localtime.tm_mon
        << ", day = " << localtime.tm_mday << endl;
    cout << "\t\thour = " << localtime.tm_hour << ", minute = " << localtime.tm_min << endl;

    cout << endl << "current weather" << endl;

    const Current& current = currentWeather.getCurrent();

    cout << "\tlast updated epoch = " << *current.getLastUpdatedEpoch() << endl;

    auto lastUpdated = current.getLastUpdated();
    cout << "\tlast updated:" << endl;
    cout << "\t\tyear = " << lastUpdated.tm_year << ", month = " << lastUpdated.tm_mon
         << ", day = " << lastUpdated.tm_mday << endl;
    cout << "\t\thour = " << lastUpdated.tm_hour << ", minute = " << lastUpdated.tm_min << endl;

        cout << "\ttemp C = " << *current.getTempC() << endl;
    cout << "\ttemp F = " << *current.getTempF() << endl;
    cout << "\tis day = " << *current.isDay() << endl;

    cout << "\tcondition " << endl;
    cout << "\t\ttext = " << *current.getCondition().getText() << endl;
    cout << "\t\ticon = " << *current.getCondition().getIcon() << endl;
    cout << "\t\tcode = " << *current.getCondition().getCode() << endl;

    cout << "\twind MPH = " << *current.getWindMph() << endl;
    cout << "\twind KPH = " << *current.getWindKph() << endl;
    cout << "\twind degree = " << *current.getWindDegree() << endl;
    cout << "\twind direction = " << *current.getWindDir() << endl;
    cout << "\tpressure MB = " << *current.getPressureMb() << endl;
    cout << "\tpressure IN = " << *current.getPressureIn() << endl;
    cout << "\tprecip MM = " << *current.getPrecipMm() << endl;
    cout << "\tprecip IN = " << *current.getPrecipIn() << endl;
    cout << "\thumidity = " << *current.getHumidity() << endl;
    cout << "\tcloud = " << *current.getCloud() << endl;
    cout << "\tfeels like C = " << *current.getFeelslikeC() << endl;
    cout << "\tfeels like F = " << *current.getFeelslikeF() << endl;
    cout << "\tvis KM = " << *current.getVisKm() << endl;
    cout << "\tvis Miles = " << *current.getVisMiles() << endl;
    cout << "\tUV = " << *current.getUv() << endl;
    cout << "\tgust MPH = " << *current.getGustMph() << endl;
    cout << "\tgust KPH = " << *current.getGustKph() << endl;

    delete apixu;

    return 0;
}
