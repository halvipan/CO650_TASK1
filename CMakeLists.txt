cmake_minimum_required(VERSION 3.29)
project(CO650_TASK1)

set(CMAKE_CXX_STANDARD 20)

add_executable(CO650_TASK1 main.cpp
        src/GameComponent.cpp
        include/GameComponent.h
)
