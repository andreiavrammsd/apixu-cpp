cmake_minimum_required(VERSION 3.14)
project(apixu_dev)

#add_definitions( -DCURL_STATICLIB )

set(CMAKE_CXX_STANDARD 14)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -lcurl")

add_executable(apixu_dev main.cpp Response/Condition.cpp Apixu.cpp Apixu.h Response/CurrentWeather.cpp Response/Location.cpp Response/Current.cpp Time.cpp Time.h Response/CurrentCondition.cpp Exception/ApixuException.cpp Exception/ApiException.cpp Response/Error.cpp HTTP/HTTP.cpp HTTP/HTTP.h HTTP/Exception.cpp)

target_link_libraries(apixu_dev curl)

#if(WIN32)
#    add_definitions(-DCURL_STATICLIB)
#    target_link_libraries(apixu_dev ${CMAKE_SOURCE_DIR}/thirdparty/openssl/openssl.lib ${CMAKE_SOURCE_DIR}/thirdparty/curl/libcurl.lib)
#else()
#    target_link_libraries(apixu_dev thirdparty/curl/libcurl.a)
#endif()
