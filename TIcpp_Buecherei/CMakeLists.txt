cmake_minimum_required(VERSION 3.7)
project(TIcpp_Buecherei)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp TAddress.cpp TAddress.h TDate.cpp TDate.h TTime.cpp TTime.h TLocation.cpp TLocation.h TPerson.cpp TPerson.h TMedium.cpp TMedium.h TLibrary.cpp TLibrary.h TLibraryPool.cpp TLibraryPool.h TLoan.cpp TLoan.h)
add_executable(TIcpp_Buecherei ${SOURCE_FILES})