cmake_minimum_required(VERSION 3.14)
project(apixu VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)

# Sources
set(SOURCE_FILES
        src/Http/exception.cpp
        src/Http/http.cpp
        src/apixu.cpp
        src/time.cpp
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
