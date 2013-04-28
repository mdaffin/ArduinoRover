set(CMAKE_TOOLCHAIN_FILE cmake/cmake/ArduinoToolchain.cmake)
cmake_minimum_required(VERSION 2.8)

# Enable c++11 standards
set(ARDUINO_C_FLAGS      "--std=gnu++11 -ffunction-sections -fdata-sections")

project(Rover C CXX)

# Add arduino libraries
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/libraries)
# Add the arduino-tiny platform
register_hardware_platform(${CMAKE_SOURCE_DIR}/hardware/tiny/hardware/tiny)

# Firmware for the arduino uno to allow it to program the attiny
generate_arduino_firmware(arduinoisp
    SKETCH ${ARDUINO_SDK_PATH}/examples/ArduinoISP
    BOARD uno
    PORT /dev/ttyACM0
)

# Rover firmware for the attiny
generate_arduino_firmware(rover
    SKETCH ${CMAKE_SOURCE_DIR}/Rover
    BOARD attiny84at8
    # Change the programmer setting if you are not using the arduino as the
    # upload the firmware to the attiny
    PROGRAMMER arduinoisp
    PORT /dev/ttyACM0
)

