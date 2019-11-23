cmake_minimum_required(VERSION 3.6.0)
project(jsc)

include_directories(src/main/cpp/jsc)

add_subdirectory(src/main/cpp/jsc)
add_subdirectory(src/main/cpp/bridge)