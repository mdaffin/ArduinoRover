set(CMAKE_TOOLCHAIN_FILE cmake/ArduinoToolchain.cmake) # Arduino Toolchain

cmake_minimum_required(VERSION 2.8)

project(Rover C CXX)

if( CMAKE_BUILD_TYPE MATCHES "[Dd][Ee][Bb][Uu][Gg]" )
    ADD_DEFINITIONS( -DDEBUG )
endif()


set(ARDUINO_DEFAULT_BOARD uno) # Default Board ID, when not specified
set(ARDUINO_DEFAULT_PORT /dev/ttyACM0) # Default Port, when not specified

#====================================================================#
# Libraries
#====================================================================#
#generate_arduino_library(blink_lib
#    SRCS blink_lib.cpp
#    HDRS blink_lib.h
#    BOARD uno)


#====================================================================#
# Firmware
#====================================================================#
generate_arduino_firmware(rover
    SRCS Rover.cpp
    #    LIBS blink_lib
    BOARD uno)

