cmake_minimum_required(VERSION 3.29)
project(CO650_TASK1)

set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(CO650_TASK1 main.cpp ${SOURCES})