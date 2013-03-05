set(CMAKE_TOOLCHAIN_FILE cmake/ArduinoToolchain.cmake) # Arduino Toolchain

cmake_minimum_required(VERSION 2.8)

project(Rover C CXX)

add_subdirectory(arduino)
add_subdirectory(attiny)
