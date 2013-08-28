set(CMAKE_TOOLCHAIN_FILE cmake/cmake/ArduinoToolchain.cmake)
cmake_minimum_required(VERSION 2.8)

# Enable c++11 standards
set(ARDUINO_C_FLAGS      "--std=gnu++11 -ffunction-sections -fdata-sections")

project(Rover C CXX)

# Add arduino libraries
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/libraries)

set(ARDUINO_DEFAULT_BOARD uno)
set(ARDUINO_DEFAULT_PORT /dev/ttyUSB0)
set(ARDUINO_DEFAULT_SERIAL picocom -l @SERIAL_PORT@)
#set(ARDUINO_DEFAULT_PROGRAMMER arduinoisp)

print_programmer_list()

# Firmware for the arduino uno to allow it to program the rover
set(arduinoisp_PROGRAMMER avrispmkii CACHE STRING "The programmer to use to program the ArduinoISP sketch")
set(arduinoisp_BOARD uno CACHE STRING "The board id of the board to upload the ArduinoISP sketch to")
generate_arduino_firmware(arduinoisp
    SKETCH ${ARDUINO_SDK_PATH}/examples/ArduinoISP
)

# Rover firmware for the rover
generate_arduino_firmware(rover
    SKETCH ${CMAKE_SOURCE_DIR}/Rover
)

generate_arduino_firmware(rover-motor
    SKETCH ${CMAKE_SOURCE_DIR}/Rover_motor
)
