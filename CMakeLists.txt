cmake_minimum_required(VERSION 3.6)
project(AmericanFlatVolTree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp clsAmericanFlatVolTree)
add_executable(AmericanFlatVolTree ${SOURCE_FILES})