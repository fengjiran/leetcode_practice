cmake_minimum_required(VERSION 3.23)
project(leetcode_practice)

set(CMAKE_CXX_STANDARD 17)

IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
    message(STATUS "Current Platform: Linux ")
    set(GTEST_INCLUDE /home/richard/project/googletest/googletest/include)
    set(GTEST_LIB /home/richard/project/googletest/build/lib/libgtest.a)
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    message(STATUS "Current Platform: MacOS")
    set(GTEST_INCLUDE /Users/richard/Desktop/googletest/googletest/include)
    set(GTEST_LIB /Users/richard/Desktop/googletest/build/lib/libgtest.a)
ELSE ()
    message(STATUS "Other Platform: ${CMAKE_SYSTEM_NAME}")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")

file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/solutions/*.cpp main.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILES})

include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${GTEST_INCLUDE}
)

target_link_libraries(${PROJECT_NAME} ${GTEST_LIB} pthread)