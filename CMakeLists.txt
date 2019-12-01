cmake_minimum_required(VERSION 3.14)
project(apixu)
set(CMAKE_CXX_STANDARD 14)

# Sources
set(SOURCE_FILES
        src/Http/Exception.cpp
        src/Http/Http.cpp
        src/Apixu.cpp
        src/Exception/ApixuException.cpp
        src/Exception/ApiException.cpp
        src/Time.cpp
        src/Response/Condition.cpp
        src/Response/Current.cpp
        src/Response/Error.cpp
        src/Response/WeatherHistory.cpp
        src/Response/CurrentWeather.cpp
        src/Response/Forecast/WeatherForecast.cpp
        src/Response/Forecast/ForecastDay.cpp
        src/Response/Forecast/Day.cpp
        src/Response/Forecast/ForecastWeather.cpp
        src/Response/Forecast/Hour.cpp
        src/Response/Forecast/Astro.cpp
        src/Response/Location.cpp
        src/Response/CurrentCondition.cpp
)

# Include directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)

# Static library
add_library(lib_static STATIC ${SOURCE_FILES})
set_target_properties(lib_static PROPERTIES OUTPUT_NAME apixu)
install(TARGETS lib_static DESTINATION static/opt/apixu/lib)
install(DIRECTORY include DESTINATION static/opt/apixu)

# Shared library
add_library(lib_shared SHARED ${SOURCE_FILES})
set_target_properties(lib_shared PROPERTIES OUTPUT_NAME apixu)
install(TARGETS lib_shared DESTINATION shared/opt/apixu/lib)
install(DIRECTORY include DESTINATION shared/opt/apixu)

add_subdirectory(tests)
add_subdirectory(examples)
