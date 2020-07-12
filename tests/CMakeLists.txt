cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 14)

# Add a test
macro(package_add_test TESTNAME)
    add_executable(${TESTNAME} ${ARGN})
    target_link_libraries(${TESTNAME} curl gtest gmock gtest_main)
    add_test(NAME ${TESTNAME} COMMAND ${TESTNAME})
    set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

# Test files
set(TEST_FILES
        ApixuConditionsTest.cpp
        ApixuCurrentTest.cpp
        ApixuForecastTest.cpp
        ApixuHistoryTest.cpp
        ApixuSearchTest.cpp)

# Sources
set(SOURCE_FILES
        ../src/Http/Exception.cpp
        ../src/Http/Http.cpp
        ../src/Apixu.cpp
        ../src/Time.cpp
        )

package_add_test(test ${TEST_FILES} ${SOURCE_FILES})

package_add_test(test_conditions
        ApixuConditionsTest.cpp
        ../src/Apixu.cpp
        ../src/Http/Http.cpp
        ../src/Time.cpp
        )

package_add_test(test_current
        ApixuCurrentTest.cpp
        ../src/Apixu.cpp
        ../src/Http/Http.cpp
        ../src/Time.cpp
        )

package_add_test(test_search
        ApixuSearchTest.cpp
        ../src/Apixu.cpp
        ../src/Http/Http.cpp
        ../src/Time.cpp
        )

package_add_test(test_history
        ApixuHistoryTest.cpp
        ../src/Apixu.cpp
        ../src/Http/Http.cpp
        ../src/Time.cpp
        )

package_add_test(test_forecast
        ApixuForecastTest.cpp
        ../src/Apixu.cpp
        ../src/Http/Http.cpp
        ../src/Time.cpp
        )

# Dependencies
include(FetchContent)

# Testing framework
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/release-1.10.0.zip)
FetchContent_Populate(googletest)
include_directories(${googletest_SOURCE_DIR}/googletest/include/)
include_directories(${googletest_SOURCE_DIR}/googlemock/include/)
add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

# Coverage
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
