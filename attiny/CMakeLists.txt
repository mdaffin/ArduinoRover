project(ArduinoRover C CXX)
register_hardware_platform(${CMAKE_SOURCE_DIR}/submodules/attiny/hardware/tiny)

if(CMAKE_BUILD_TYPE MATCHES "[Dd][Ee][Bb][Uu][Gg]")
	message("Debug mode enabled")
    add_definitions( -DDEBUG )
endif()

generate_arduino_firmware(rover-attiny
    SRCS Rover.cpp
    BOARD attiny84at8
    PROGRAMMER arduinoisp
    PORT /dev/ttyACM0
)

