cmake_minimum_required(VERSION 3.18)
set( PROJECT "botnet")
project(${PROJECT} LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(botnet PUBLIC ./include)
file(GLOB SOURCES "./src/*.cpp")

add_executable(main main.cpp ${SOURCES} )
