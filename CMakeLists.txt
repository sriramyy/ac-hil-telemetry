cmake_minimum_required(VERSION 3.29)
project(ac_hil_telemetry)

set(CMAKE_CXX_STANDARD 20)

add_executable(ac_hil_telemetry main.cpp
        Vehicle.h
        Vehicle.cpp
        TrackSession.cpp
        TrackSession.h)
