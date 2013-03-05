project(ArduinoRover C CXX)

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
generate_arduino_firmware(rover-uno 
    SRCS Rover.cpp 
    BOARD uno 
    PORT /dev/ttyACM0
)

generate_arduino_firmware(rover-promini 
    SRCS Rover.cpp 
    BOARD pro5v328
    PORT /dev/ttyUSB0
)

generate_arduino_firmware(calibrate-uno
    SRCS Wheel-Calibrate.cpp
    BOARD uno 
    PORT /dev/ttyACM0
)

generate_arduino_firmware(calibrate-promini 
    SRCS Wheel-Calibrate.cpp
    BOARD pro5v328
    PORT /dev/ttyUSB0
)
