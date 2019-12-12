#include <iostream>
#include <vector>
#include "Apixu/Apixu.h"
#include "Apixu/Exception/ApiException.h"
#include <iomanip>
#include <ctime>

using Apixu::Exception::ApiException;
using Apixu::Exception::ApixuException;
using Apixu::Response::Forecast::ForecastWeather;
using std::cout;
using std::endl;

int main() {
    const char *apiKey = getenv("APIXUKEY");
    if (!apiKey) {
        cout << "APIXUKEY not set";
        return 1;
    }

    auto apixu = new Apixu::Apixu(apiKey);

    class WeatherHistory history;
    try {
        auto t = std::time(nullptr);
        auto tm = *std::localtime(&t);

        std::ostringstream since;
        since << std::put_time(&tm, "%Y-%m-%d");

        history = apixu->History("Prague", since.str());
    } catch (ApiException &e) {
        cout << "ApiException: " << e.what() << " (code: " << e.getCode() << ")";
        return 1;
    } catch (ApixuException &e) {
        cout << "ApixuException: " << e.what();
        return 1;
    }

    cout << "location" << endl;

    const Location &location = history.getLocation();

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

    cout << endl << "forecast weather" << endl;

    const ForecastWeather &forecast = history.getForecast();

    for (const auto &f : forecast.getForecastDay()) {
        cout << "\tdate = " << f.getDate() << endl;
        cout << "\tdate epoch = " << f.getDateEpoch() << endl;

        cout << "\tday" << endl;
        cout << "\t\tmax temp C = " << f.getDay().getMaxTempCelsius() << endl;
        cout << "\t\tmax temp F = " << f.getDay().getMaxTempFahrenheit() << endl;

        cout << "\tastro" << endl;
        cout << "\t\tsunrise = " << f.getAstro().getSunrise() << endl;
        cout << "\t\tsunset = " << f.getAstro().getSunset() << endl;

        cout << "\thour" << endl;
        for (const auto &h : f.getHour()) {
            cout << "\t\ttime epoch = " << h.getTimeEpoch() << endl;
            cout << "\t\ttime = " << h.getTime() << endl;
            cout << "\t\ttemp C = " << h.getTempC() << endl;
            cout << "\t\ttemp F = " << h.getTempF() << endl;
            cout << endl;
        }
    }

    delete apixu;

    return 0;
}
