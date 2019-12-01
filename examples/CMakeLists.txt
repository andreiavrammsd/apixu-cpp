cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 14)

add_executable(example_conditions
        conditions.cpp
        ../src/Apixu.cpp
        ../src/Http/Http.cpp
        ../src/Time.cpp
        ../src/Exception/ApiException.cpp
        ../src/Exception/ApixuException.cpp
        ../src/Response/Condition.cpp
        ../src/Response/Location.cpp
        ../src/Response/Error.cpp)
target_link_libraries(example_conditions curl)

add_executable(example_current
        current.cpp
        ../src/Apixu.cpp
        ../src/Http/Http.cpp
        ../src/Time.cpp
        ../src/Exception/ApiException.cpp
        ../src/Exception/ApixuException.cpp
        ../src/Response/CurrentWeather.cpp
        ../src/Response/Location.cpp
        ../src/Response/Current.cpp
        ../src/Response/CurrentCondition.cpp
        ../src/Response/Error.cpp)
target_link_libraries(example_current curl)

add_executable(example_search
        search.cpp
        ../src/Apixu.cpp
        ../src/Http/Http.cpp
        ../src/Time.cpp
        ../src/Exception/ApiException.cpp
        ../src/Exception/ApixuException.cpp
        ../src/Response/Location.cpp
        ../src/Response/Error.cpp)
target_link_libraries(example_search curl)

add_executable(example_forecast
        forecast.cpp
        ../src/Apixu.cpp
        ../src/Http/Http.cpp
        ../src/Time.cpp
        ../src/Exception/ApiException.cpp
        ../src/Exception/ApixuException.cpp
        ../src/Response/Forecast/WeatherForecast.cpp
        ../src/Response/Forecast/ForecastDay.cpp
        ../src/Response/Forecast/ForecastWeather.cpp
        ../src/Response/Forecast/Astro.cpp
        ../src/Response/Forecast/Day.cpp
        ../src/Response/Location.cpp
        ../src/Response/Current.cpp
        ../src/Response/CurrentCondition.cpp
        ../src/Response/Forecast/Hour.cpp
        ../src/Response/Error.cpp)
target_link_libraries(example_forecast curl)

add_executable(example_history
        history.cpp
        ../src/Apixu.cpp
        ../src/Http/Http.cpp
        ../src/Time.cpp
        ../src/Exception/ApiException.cpp
        ../src/Exception/ApixuException.cpp
        ../src/Response/Location.cpp
        ../src/Response/WeatherHistory.cpp
        ../src/Response/Forecast/ForecastWeather.cpp
        ../src/Response/Forecast/ForecastDay.cpp
        ../src/Response/Forecast/Day.cpp
        ../src/Response/Forecast/Astro.cpp
        ../src/Response/Forecast/Hour.cpp
        ../src/Response/Error.cpp)
target_link_libraries(example_history curl)
