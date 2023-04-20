cmake_minimum_required(VERSION 3.24)
project(OS_LAB2)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)
set(CMAKE_C_STANDARD 11)

file(MAKE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src")
file(MAKE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include")
file(MAKE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/tests")

add_executable(Main src/main.cpp src/min_max.cpp include/min_max.h src/average.cpp include/average.h )
add_executable(Test tests/test.cpp)

target_link_libraries(Test gtest_main)