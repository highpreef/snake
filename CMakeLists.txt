cmake_minimum_required(VERSION 3.23)
project(snake)

set(CMAKE_CXX_STANDARD 17)

add_executable(snake main.cpp GameFpsController.h Point.h Snake.h Utils.h)