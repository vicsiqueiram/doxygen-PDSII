cmake_minimum_required(VERSION 3.10.2)
set (CMAKE_CXX_STANDARD 17)
project(PDS-II-TP)

include_directories(include)

file(GLOB SOURCES "src/*.cpp" "src/*/*.cpp")

add_executable(PDS-II-TP ${SOURCES})
