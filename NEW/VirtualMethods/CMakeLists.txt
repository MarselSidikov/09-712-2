cmake_minimum_required(VERSION 3.8)
project(VirtualMethods)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp TextFunction.h ToLowerCaseFunction.h AlphaBetOrDigitsExtractFunction.h MainTextProcessor.h ToUpperCaseFunction.h)
add_executable(VirtualMethods ${SOURCE_FILES})