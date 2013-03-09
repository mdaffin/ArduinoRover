project(ArduinoRover C CXX)

if(CMAKE_BUILD_TYPE MATCHES "[Dd][Ee][Bb][Uu][Gg]")
	message("Debug mode enabled")
    add_definitions( -DDEBUG )
endif()

generate_arduino_firmware(arduinoisp
    SKETCH ${ARDUINO_SDK_PATH}/examples/ArduinoISP
    BOARD uno
    PORT /dev/ttyACM0
)

generate_arduino_firmware(rover-attiny
    SRCS Rover.cpp
    BOARD attiny84at8
    PROGRAMMER arduinoisp
    PORT /dev/ttyACM0
)

generate_arduino_firmware(test
    SRCS Test.cpp
    BOARD attiny84at8
    PROGRAMMER arduinoisp
    PORT /dev/ttyACM0
)

