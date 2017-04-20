cmake_minimum_required(VERSION 3.7)
project(aufgabe1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        tdate.cpp
        tdate.h
        ttime.cpp
        ttime.h)

add_executable(aufgabe1 ${SOURCE_FILES})