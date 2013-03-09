set(CMAKE_TOOLCHAIN_FILE submodules/cmake/cmake/ArduinoToolchain.cmake) # Arduino Toolchain

cmake_minimum_required(VERSION 2.8)

project(Rover C CXX)

register_hardware_platform(${CMAKE_SOURCE_DIR}/submodules/attiny/hardware/tiny)

add_subdirectory(arduino)
add_subdirectory(attiny)
