cmake_minimum_required(VERSION 3.5)

project(technological_algorithm LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(./src)
add_executable(technological_algorithm src/main.cpp src/compute.cpp src/parse.cpp)
