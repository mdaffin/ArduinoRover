set(CMAKE_TOOLCHAIN_FILE cmake/cmake/ArduinoToolchain.cmake) # Arduino Toolchain

cmake_minimum_required(VERSION 2.8)
set(ARDUINO_C_FLAGS      "--std=gnu++11 -ffunction-sections -fdata-sections")
project(Rover C CXX)


message(STATUS "ARDUINO_CXX_FLAGS: " ${ARDUINO_CXX_FLAGS})

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/libraries)
register_hardware_platform(${CMAKE_SOURCE_DIR}/hardware/tiny/hardware/tiny)

generate_arduino_firmware(arduinoisp
    SKETCH ${ARDUINO_SDK_PATH}/examples/ArduinoISP
    BOARD uno
    PORT /dev/ttyACM0
)

generate_arduino_firmware(rover-attiny
    SKETCH ${CMAKE_SOURCE_DIR}/Rover
    BOARD attiny84at8
    PROGRAMMER arduinoisp
    PORT /dev/ttyACM0
)

