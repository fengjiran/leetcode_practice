cmake_minimum_required(VERSION 3.21)
project(leetcode_practice)

set(CMAKE_CXX_STANDARD 17)

find_package(glog REQUIRED)
find_package(GTest REQUIRED)

file(GLOB_RECURSE SRC_FILES
        ${PROJECT_SOURCE_DIR}/solutions/*.cpp
        ${PROJECT_SOURCE_DIR}/cpptest/*.cpp
        main.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILES})

include_directories(
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
        GTest::gtest_main
        glog::glog
        blas
        pthread
)