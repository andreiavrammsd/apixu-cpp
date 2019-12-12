cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 14)

# Tests
macro(package_add_test TESTNAME)
    add_executable(${TESTNAME} ${ARGN})
    target_link_libraries(${TESTNAME} gtest gmock gtest_main)
    add_test(NAME ${TESTNAME} COMMAND ${TESTNAME})
    set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

package_add_test(test_conditions
        ApixuConditionsTest.cpp
        ../src/Apixu.cpp
        ../src/Http/Http.cpp
        ../src/Time.cpp
        ../src/Exception/ApiException.cpp
        ../src/Exception/ApixuException.cpp
        ../src/Response/Condition.cpp
        ../src/Response/Location.cpp
        ../src/Response/Error.cpp)
target_link_libraries(test_conditions curl)

package_add_test(test_current
        ApixuCurrentTest.cpp
        ../src/Apixu.cpp
        ../src/Http/Http.cpp
        ../src/Time.cpp
        ../src/Exception/ApiException.cpp
        ../src/Exception/ApixuException.cpp
        ../src/Response/CurrentWeather.cpp
        ../src/Response/Location.cpp
        ../src/Response/Error.cpp)
target_link_libraries(test_current curl)

package_add_test(test_search
        ApixuSearchTest.cpp
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
target_link_libraries(test_search curl)

package_add_test(test_history
        ApixuHistoryTest.cpp
        ../src/Apixu.cpp
        ../src/Http/Http.cpp
        ../src/Time.cpp
        ../src/Exception/ApiException.cpp
        ../src/Exception/ApixuException.cpp
        ../src/Response/WeatherHistory.cpp
        ../src/Response/Location.cpp
        ../src/Response/Current.cpp
        ../src/Response/CurrentCondition.cpp
        ../src/Response/Error.cpp)
target_link_libraries(test_history curl)

package_add_test(test_forecast
        ApixuForecastTest.cpp
        ../src/Apixu.cpp
        ../src/Http/Http.cpp
        ../src/Time.cpp
        ../src/Exception/ApiException.cpp
        ../src/Exception/ApixuException.cpp
        ../src/Response/Forecast/WeatherForecast.cpp
        ../src/Response/Location.cpp
        ../src/Response/Error.cpp)
target_link_libraries(test_forecast curl)


# Dependencies
include(FetchContent)

# Testing framework
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/release-1.10.0.zip)
FetchContent_Populate(googletest)
include_directories(${googletest_SOURCE_DIR}/googletest/include/)
include_directories(${googletest_SOURCE_DIR}/googlemock/include/)
add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
