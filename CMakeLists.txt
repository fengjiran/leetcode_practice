cmake_minimum_required(VERSION 3.21)
project(leetcode_practice)

set(CMAKE_CXX_STANDARD 17)

IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
    message(STATUS "Current Platform: Linux ")
    #    set(GTEST_INCLUDE /home/richard/project/googletest/googletest/include)
    #    set(GTEST_LIB /home/richard/project/googletest/build/lib/libgtest.a)
    #    set(ARMADILLO_INCLUDE /home/richard/project/armadillo-12.8.1/include)
    #    set(ARMADILLO_LIB /home/richard/project/armadillo-12.8.1/build/libarmadillo.so)
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    message(STATUS "Current Platform: MacOS")
    #    set(GTEST_INCLUDE /Users/richard/Desktop/googletest/googletest/include)
    #    set(GTEST_LIB /Users/richard/Desktop/googletest/build/lib/libgtest.a)
    #    set(ARMADILLO_INCLUDE /Users/richard/Desktop/armadillo-12.8.1/include)
#        set(ARMADILLO_LIB /Users/richard/Desktop/armadillo-12.8.1/build/libarmadillo.dylib)
ELSE ()
    message(STATUS "Other Platform: ${CMAKE_SYSTEM_NAME}")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")

find_package(glog REQUIRED)
find_package(GTest REQUIRED)
find_package(Armadillo REQUIRED)


file(GLOB_RECURSE SRC_FILES
        ${PROJECT_SOURCE_DIR}/solutions/*.cpp
        ${PROJECT_SOURCE_DIR}/cpptest/*.cpp
        main.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILES})

include_directories(
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
#        GTest::gtest
        GTest::gtest_main
        glog::glog
        blas
        pthread
        ${ARMADILLO_LIBRARY}
)