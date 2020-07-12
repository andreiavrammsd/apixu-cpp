cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 14)

add_executable(example_conditions
        conditions.cpp
        ../src/Apixu.cpp
        ../src/Http/Http.cpp
        ../src/Time.cpp
        )
target_link_libraries(example_conditions curl)

add_executable(example_current
        current.cpp
        ../src/Apixu.cpp
        ../src/Http/Http.cpp
        ../src/Time.cpp
        )
target_link_libraries(example_current curl)

add_executable(example_search
        search.cpp
        ../src/Apixu.cpp
        ../src/Http/Http.cpp
        ../src/Time.cpp
        )
target_link_libraries(example_search curl)

add_executable(example_forecast
        forecast.cpp
        ../src/Apixu.cpp
        ../src/Http/Http.cpp
        ../src/Time.cpp
        )
target_link_libraries(example_forecast curl)

add_executable(example_history
        history.cpp
        ../src/Apixu.cpp
        ../src/Http/Http.cpp
        ../src/Time.cpp
        )
target_link_libraries(example_history curl)
