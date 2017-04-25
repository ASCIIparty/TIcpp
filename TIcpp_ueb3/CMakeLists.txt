cmake_minimum_required(VERSION 3.7)
project(TIcpp_ueb3)

set(CMAKE_CXX_STANDARD 11)

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
        ttime.h)

add_executable(TIcpp_ueb2 ${SOURCE_FILES})