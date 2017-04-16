cmake_minimum_required(VERSION 3.5)
project(TIcpp_ueb2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    TAddress.cpp
    taddress.h
    TDate.cpp
    tdate.h
    TLocation.cpp
    tlocation.h
    TPerson.cpp
    tperson.h
    TTime.cpp
    ttime.h
    Ueb2.cpp)

add_executable(TIcpp_ueb2 ${SOURCE_FILES})