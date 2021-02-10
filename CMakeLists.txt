cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_STANDARD 14)

project(CovidPatientsManagement)

add_executable(CovidPatientsManagement src/main.cpp src/Date.cpp src/Patient.cpp)
