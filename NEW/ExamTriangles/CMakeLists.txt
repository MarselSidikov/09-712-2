cmake_minimum_required(VERSION 3.8)
project(ExamTaskLast)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Triangle.cpp Triangle.h RightAngleTriangle.cpp RightAngleTriangle.h)
add_executable(ExamTaskLast ${SOURCE_FILES})