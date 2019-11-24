cmake_minimum_required(VERSION 3.14)
project(apixu)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

file(GLOB source_files "src/*.cpp")

add_library(apixustatic STATIC ${source_files})
set_target_properties(apixustatic PROPERTIES OUTPUT_NAME apixu)

add_library(apixushared SHARED ${source_files})
set_target_properties(apixushared PROPERTIES OUTPUT_NAME apixu)

add_executable(conditions
        examples/conditions.cpp
        src/Apixu.cpp
        src/HTTP/HTTP.cpp
        src/Time.cpp
        src/Exception/ApiException.cpp
        src/Response/Condition.cpp
        src/Response/Location.cpp)
target_link_libraries(conditions curl)

add_executable(current
        examples/current.cpp
        src/Apixu.cpp
        src/HTTP/HTTP.cpp
        src/Time.cpp
        src/Exception/ApiException.cpp
        src/Response/CurrentWeather.cpp
        src/Response/Location.cpp
        src/Response/Current.cpp
        src/Response/CurrentCondition.cpp)
target_link_libraries(current curl)

add_executable(search
        examples/search.cpp
        src/Apixu.cpp
        src/HTTP/HTTP.cpp
        src/Time.cpp
        src/Response/Location.cpp)
target_link_libraries(search curl)

add_executable(forecast
        examples/forecast.cpp
        src/Apixu.cpp
        src/HTTP/HTTP.cpp
        src/Time.cpp
        src/Response/Forecast/Forecast.cpp
        src/Response/Forecast/ForecastDay.cpp
        src/Response/Forecast/ForecastWeather.cpp
        src/Response/Forecast/Astro.cpp
        src/Response/Forecast/Day.cpp
        src/Response/Location.cpp
        src/Response/Current.cpp
        src/Response/CurrentCondition.cpp
        src/Response/Forecast/Hour.cpp)
target_link_libraries(forecast curl)

add_executable(history
        examples/history.cpp
        src/Apixu.cpp
        src/HTTP/HTTP.cpp
        src/Time.cpp
        src/Response/Location.cpp
        src/Response/History.cpp
        src/Response/Forecast/ForecastWeather.cpp
        src/Response/Forecast/ForecastDay.cpp
        src/Response/Forecast/Day.cpp
        src/Response/Forecast/Astro.cpp
        src/Response/Forecast/Hour.cpp)
target_link_libraries(history curl)
