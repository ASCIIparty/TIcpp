cmake_minimum_required(VERSION 3.7)
project(TIcpp_ueb1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        TDate.cpp
        tdate.h
        TTime.cpp
        ttime.h
        Ueb1.cpp)

add_executable(TIcpp_ueb1 ${SOURCE_FILES})