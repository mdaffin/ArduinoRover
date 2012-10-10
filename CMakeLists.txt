set(CMAKE_TOOLCHAIN_FILE cmake/ArduinoToolchain.cmake) # Arduino Toolchain

cmake_minimum_required(VERSION 2.8)

project(Rover C CXX)

if(CMAKE_BUILD_TYPE MATCHES "[Dd][Ee][Bb][Uu][Gg]")
	message("Debug mode enabled")
    add_definitions( -DDEBUG )
endif()
if (NOT_LDR)
    message("Not compiling ldr support")
    add_definitions( -DNOT_LDR )
endif()
if (NOT_RANGE_FINDER)
    message("Not compiling range finder support")
    add_definitions( -DNOT_RANGE_FINDER )
endif()
if (NOT_POTENTIOMETER)
    message("Not compiling potentiometer support")
    add_definitions( -DNOT_POTENTIOMETER )
endif()


set(ARDUINO_DEFAULT_BOARD pro5v328) # Default Board ID, when not specified
set(ARDUINO_DEFAULT_PORT /dev/ttyUSB0) # Default Port, when not specified

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
generate_arduino_firmware(rover SRCS Rover.cpp)
generate_arduino_firmware(playground SRCS Playground.cpp)
generate_arduino_firmware(calibrate SRCS Wheel-Calibrate.cpp)
