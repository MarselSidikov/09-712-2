cmake_minimum_required(VERSION 3.8)
project(Exam2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp LinkedList.cpp LinkedList.h IStack.h IList.h StackListImpl.cpp StackListImpl.h ArrayList.cpp ArrayList.h)
add_executable(Exam2 ${SOURCE_FILES})