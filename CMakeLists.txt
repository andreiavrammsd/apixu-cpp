cmake_minimum_required(VERSION 3.14)
project(apixu)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)

file(GLOB source_files "src/*.cpp")

add_library(lib_apixustatic STATIC ${source_files})
set_target_properties(lib_apixustatic PROPERTIES OUTPUT_NAME apixu)

add_library(lib_shared SHARED ${source_files})
set_target_properties(lib_shared PROPERTIES OUTPUT_NAME apixu)

# -------------------------------------------------------------------
# Tests
macro(package_add_test TESTNAME)
    add_executable(${TESTNAME} ${ARGN})
    target_link_libraries(${TESTNAME} gtest gmock gtest_main)
    add_test(NAME ${TESTNAME} COMMAND ${TESTNAME})
    set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

package_add_test(test_conditions
        tests/ApixuConditionsTest.cpp
        src/Apixu.cpp
        src/Http/Http.cpp
        src/Time.cpp
        src/Exception/ApiException.cpp
        src/Exception/ApixuException.cpp
        src/Response/Condition.cpp
        src/Response/Location.cpp
        src/Response/Error.cpp)
target_link_libraries(test_conditions curl)

package_add_test(test_current
        tests/ApixuCurrentTest.cpp
        src/Apixu.cpp
        src/Http/Http.cpp
        src/Time.cpp
        src/Exception/ApiException.cpp
        src/Exception/ApixuException.cpp
        src/Response/CurrentWeather.cpp
        src/Response/Location.cpp
        src/Response/Current.cpp
        src/Response/CurrentCondition.cpp
        src/Response/Error.cpp)
target_link_libraries(test_current curl)


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
add_executable(example_conditions
        examples/conditions.cpp
        src/Apixu.cpp
        src/Http/Http.cpp
        src/Time.cpp
        src/Exception/ApiException.cpp
        src/Exception/ApixuException.cpp
        src/Response/Condition.cpp
        src/Response/Location.cpp
        src/Response/Error.cpp)
target_link_libraries(example_conditions curl)

add_executable(example_current
        examples/current.cpp
        src/Apixu.cpp
        src/Http/Http.cpp
        src/Time.cpp
        src/Exception/ApiException.cpp
        src/Exception/ApixuException.cpp
        src/Response/CurrentWeather.cpp
        src/Response/Location.cpp
        src/Response/Current.cpp
        src/Response/CurrentCondition.cpp
        src/Response/Error.cpp)
target_link_libraries(example_current curl)

add_executable(example_search
        examples/search.cpp
        src/Apixu.cpp
        src/Http/Http.cpp
        src/Time.cpp
        src/Exception/ApiException.cpp
        src/Exception/ApixuException.cpp
        src/Response/Location.cpp
        src/Response/Error.cpp)
target_link_libraries(example_search curl)

add_executable(example_forecast
        examples/forecast.cpp
        src/Apixu.cpp
        src/Http/Http.cpp
        src/Time.cpp
        src/Exception/ApiException.cpp
        src/Exception/ApixuException.cpp
        src/Response/Forecast/WeatherForecast.cpp
        src/Response/Forecast/ForecastDay.cpp
        src/Response/Forecast/ForecastWeather.cpp
        src/Response/Forecast/Astro.cpp
        src/Response/Forecast/Day.cpp
        src/Response/Location.cpp
        src/Response/Current.cpp
        src/Response/CurrentCondition.cpp
        src/Response/Forecast/Hour.cpp
        src/Response/Error.cpp)
target_link_libraries(example_forecast curl)

add_executable(example_history
        examples/history.cpp
        src/Apixu.cpp
        src/Http/Http.cpp
        src/Time.cpp
        src/Exception/ApiException.cpp
        src/Exception/ApixuException.cpp
        src/Response/Location.cpp
        src/Response/WeatherHistory.cpp
        src/Response/Forecast/ForecastWeather.cpp
        src/Response/Forecast/ForecastDay.cpp
        src/Response/Forecast/Day.cpp
        src/Response/Forecast/Astro.cpp
        src/Response/Forecast/Hour.cpp
        src/Response/Error.cpp)
target_link_libraries(example_history curl)
