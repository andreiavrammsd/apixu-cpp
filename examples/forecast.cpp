#include <iostream>
#include <vector>
#include "../src/Apixu.hpp"
#include "../src/Exception/ApiException.cpp"

using namespace Apixu::Exception;
using namespace Apixu::Response;
using namespace Apixu::Response::Forecast;
using std::cout;
using std::endl;

int main() {
    const char *apiKey = getenv("APIXUKEY");
    if (!apiKey) {
        cout << "APIXUKEY not set";
        return 1;
    }

    auto apixu = new Apixu::Apixu(apiKey);

    class WeatherForecast forecast;
    try {
        int h = 12;
        forecast = apixu->Forecast("Paris", 2, &h);
    } catch (ApiException &e) {
        cout << "ApiException: " << e.what() << " (code: " << e.getCode() << ")";
        return 1;
    } catch (ApixuException &e) {
        cout << "ApixuException: " << e.what();
        return 1;
    }

    cout << "location" << endl;

    const Location& location = forecast.getLocation();

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

    const Current& current = forecast.getCurrent();

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

    cout << endl << "day forecast" << endl;

    vector<ForecastDay> days = forecast.getForecast().getForecastDay();
    for (auto const& day : days) {
        cout << "\tdate = " << day.getDate() << endl;
        cout << "\tdate epoch = " << day.getDateEpoch() << endl;


        const Day& d = day.getDay();
        cout << "\tday" << endl;
        cout << "\t\tmax temp C = " << d.getMaxTempCelsius() << endl;
        cout << "\t\tmax temp F = " << d.getMaxTempFahrenheit() << endl;
        cout << "\t\tmin temp C = " << d.getMinTempCelsius() << endl;
        cout << "\t\tmin temp F = " << d.getMinTempFahrenheit() << endl;
        cout << "\t\tavg temp C = " << d.getAvgTempCelsius() << endl;
        cout << "\t\tavg temp F = " << d.getAvgTempFahrenheit() << endl;
        cout << "\t\tmax wind MPH = " << d.getMaxWindMph() << endl;
        cout << "\t\tmax wind KMH = " << d.getMaxWindKph() << endl;
        cout << "\t\ttotal precip MM = " << d.getTotalPrecipMm() << endl;
        cout << "\t\ttotal precip IN = " << d.getTotalPrecipIn() << endl;
        cout << "\t\tavg vis KM = " << d.getAvgVisKm() << endl;
        cout << "\t\tavg vis Miles = " << d.getAvgVisMiles() << endl;
        cout << "\t\tavg humidity = " << d.getAvgHumidity() << endl;
        cout << "\t\tcondition " << endl;
        cout << "\t\t\ttext = " << *d.getCondition().getText() << endl;
        cout << "\t\t\ticon = " << *d.getCondition().getIcon() << endl;
        cout << "\t\t\tcode = " << *d.getCondition().getCode() << endl;
        cout << "\t\tuv = " << d.getUv() << endl;

        const Astro& a = day.getAstro();
        cout << "\tastro" << endl;;
        cout << "\t\tsunrise = " << a.getSunrise() << endl;
        cout << "\t\tsunset = " << a.getSunset() << endl;
        cout << "\t\tmoonrise = " << a.getMoonrise() << endl;
        cout << "\t\tmoonset = " << a.getMoonset() << endl;
        cout << "\t\tmoon phase = " << a.getMoonPhase() << endl;
        cout << "\t\tmoon illumination = " << a.getMoonIllumination() << endl;

        const vector<Hour>& hour = day.getHour();
        for (auto const& h : hour) {
            cout << "\thour" << endl;;
            cout << "\t\ttime epoch = " << h.getTimeEpoch() << endl;
            cout << "\t\ttime = " << h.getTime() << endl;
            cout << "\t\ttemp C = " << h.getTempC() << endl;
            cout << "\t\ttemp f = " << h.getTempF() << endl;
            cout << "\t\tday = " << h.isDay() << endl;
            cout << "\t\tcondition " << endl;
            cout << "\t\t\ttext = " << h.getCondition().getText() << endl;
            cout << "\t\t\ticon = " << h.getCondition().getIcon() << endl;
            cout << "\t\t\tcode = " << h.getCondition().getCode() << endl;
            cout << "\t\twind MPH = " << h.getWindMph() << endl;
            cout << "\t\twind KPH = " << h.getWindKph() << endl;
            cout << "\t\twind degree = " << h.getWindDegree() << endl;
            cout << "\t\twind direction = " << h.getWindDir() << endl;
            cout << "\t\tpressure MB = " << h.getPressureMb() << endl;
            cout << "\t\tpressure IN = " << h.getPressureIn() << endl;
            cout << "\t\tprecip MM = " << h.getPrecipMm() << endl;
            cout << "\t\tprecip IN = " << h.getPrecipIn() << endl;
            cout << "\t\thumidity = " << h.getHumidity() << endl;
            cout << "\t\tcloud = " << h.getCloud() << endl;
            cout << "\t\tfeels like C = " << h.getFeelsLikeC() << endl;
            cout << "\t\tfeels like F = " << h.getFeelsLikeF() << endl;
            cout << "\t\twind chill C = " << h.getWindChillC() << endl;
            cout << "\t\twind chill F = " << h.getWindChillF() << endl;
            cout << "\t\theat index C = " << h.getHeatIndexC() << endl;
            cout << "\t\theat index F = " << h.getHeatIndexF() << endl;
            cout << "\t\tdew point C = " << h.getDewPointC() << endl;
            cout << "\t\tdew point F = " << h.getDewPointF() << endl;
            cout << "\t\twill it rain? = " << h.willItRain() << endl;
            cout << "\t\tchance of rain = " << h.getChanceOfRain() << endl;
            cout << "\t\twill it snow? = " << h.willItSnow() << endl;
            cout << "\t\tchance of snow = " << h.getChanceOfSnow() << endl;
            cout << "\t\tvis KM = " << h.getVisKm() << endl;
            cout << "\t\tvis Miles = " << h.getVisMiles() << endl;
            cout << "\t\tgust MPH = " << h.getGustMph() << endl;
            cout << "\t\tgust KPH = " << h.getGustKph() << endl;
            cout << endl;
        }

        cout << endl;
    }

    delete apixu;

    return 0;
}
