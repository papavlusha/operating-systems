cmake_minimum_required(VERSION 3.25)
project(OS_lab1)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

set(CMAKE_CXX_STANDARD 17)

add_executable(Creator src/Creator.cpp)
add_executable(Reporter src/Reporter.cpp)

file(MAKE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/objects")

set_target_properties(Creator PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/objects"
        )
set_target_properties(Reporter PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/objects"
        )
file(MAKE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/reports")

add_executable(OS_lab1 src/main.cpp )
add_executable(tests src/tests.cpp)


target_link_libraries(tests gtest_main)






