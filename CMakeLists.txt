cmake_minimum_required(VERSION 3.14)
project(apixu)

set(CMAKE_CXX_STANDARD 14)

add_executable(conditions examples/conditions.cpp src/Response/Condition.cpp src/Apixu.cpp src/Apixu.h src/Response/CurrentWeather.cpp src/Response/Location.cpp src/Response/Current.cpp src/Time.cpp src/Time.h src/Response/CurrentCondition.cpp src/Exception/ApixuException.cpp src/Exception/ApiException.cpp src/Response/Error.cpp src/HTTP/HTTP.cpp src/HTTP/HTTP.h src/HTTP/Exception.cpp)
add_executable(current examples/current.cpp src/Response/Condition.cpp src/Apixu.cpp src/Apixu.h src/Response/CurrentWeather.cpp src/Response/Location.cpp src/Response/Current.cpp src/Time.cpp src/Time.h src/Response/CurrentCondition.cpp src/Exception/ApixuException.cpp src/Exception/ApiException.cpp src/Response/Error.cpp src/HTTP/HTTP.cpp src/HTTP/HTTP.h src/HTTP/Exception.cpp)
add_executable(search examples/search.cpp src/Response/Condition.cpp src/Apixu.cpp src/Apixu.h src/Response/CurrentWeather.cpp src/Response/Location.cpp src/Response/Current.cpp src/Time.cpp src/Time.h src/Response/CurrentCondition.cpp src/Exception/ApixuException.cpp src/Exception/ApiException.cpp src/Response/Error.cpp src/HTTP/HTTP.cpp src/HTTP/HTTP.h src/HTTP/Exception.cpp)
add_library(apixu STATIC src/Response/Condition.cpp src/Apixu.cpp src/Apixu.h src/Response/CurrentWeather.cpp src/Response/Location.cpp src/Response/Current.cpp src/Time.cpp src/Time.h src/Response/CurrentCondition.cpp src/Exception/ApixuException.cpp src/Exception/ApiException.cpp src/Response/Error.cpp src/HTTP/HTTP.cpp src/HTTP/HTTP.h src/HTTP/Exception.cpp)

target_link_libraries(conditions curl)
target_link_libraries(current curl)
target_link_libraries(search curl)
target_link_libraries(apixu curl)

#add_definitions( -DCURL_STATICLIB )
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -lcurl")

#if(WIN32)
#    add_definitions(-DCURL_STATICLIB)
#    target_link_libraries(apixu ${CMAKE_SOURCE_DIR}/thirdparty/openssl/openssl.lib ${CMAKE_SOURCE_DIR}/thirdparty/curl/libcurl.lib)
#else()
#    target_link_libraries(apixu thirdparty/curl/libcurl.a)
#endif()
