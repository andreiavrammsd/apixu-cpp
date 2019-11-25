cmake_minimum_required(VERSION 3.14)
project(apixu)

set(CMAKE_CXX_STANDARD 14)

file(GLOB source_files "src/*.cpp")

add_library(apixustatic STATIC ${source_files})
set_target_properties(apixustatic PROPERTIES OUTPUT_NAME apixu)

add_library(apixushared SHARED ${source_files})
set_target_properties(apixushared PROPERTIES OUTPUT_NAME apixu)

# -------------------------------------------------------------------
# Tests
macro(package_add_test TESTNAME)
    add_executable(${TESTNAME} ${ARGN})
    target_link_libraries(${TESTNAME} gtest gmock gtest_main)
    add_test(NAME ${TESTNAME} COMMAND ${TESTNAME})
    set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

package_add_test(conditions_test
        tests/ApixuConditionsTest.cpp
        src/Apixu.cpp
        src/HTTP/HTTP.cpp
        src/Time.cpp
        src/Exception/ApiException.cpp
        src/Response/Condition.cpp
        src/Response/Location.cpp)
target_link_libraries(conditions_test curl)


# -------------------------------------------------------------------
# Dependencies
include(FetchContent)

# Testing framework
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/release-1.10.0.zip)
FetchContent_Populate(googletest)
include_directories(${googletest_SOURCE_DIR}/googletest/include/)
include_directories(${googletest_SOURCE_DIR}/googlemock/include/)
add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

# JSON
FetchContent_Declare(nlohmann_json URL https://github.com/nlohmann/json/releases/download/v3.7.3/include.zip)
FetchContent_Populate(nlohmann_json)
include_directories(${nlohmann_json_SOURCE_DIR}/include/)


# -------------------------------------------------------------------
# Example applications
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
        src/Response/Forecast/WeatherForecast.cpp
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
        src/Response/WeatherHistory.cpp
        src/Response/Forecast/ForecastWeather.cpp
        src/Response/Forecast/ForecastDay.cpp
        src/Response/Forecast/Day.cpp
        src/Response/Forecast/Astro.cpp
        src/Response/Forecast/Hour.cpp)
target_link_libraries(history curl)
