ArduinoISP
==========
If you are using the arduino uno or similar as the programmer you must first upload the ArduinoISP sketch to the arduino to do this run the following:

 mkdir build
 cd build
 cmake ..
 make arduinoisp-upload

Burn via ArduinoISP
===================
To build and upload the sketch run the following:

 mkdir build
 cd build
 cmake ..
 make rover-burn

Options
=======
To override the default setings add it to the cmake command:

 cmake .. -DARDUINO_DEFAULT_PORT=/dev/ttyUSB0

Common option:
 
 ARDUINO_DEFAULT_PORT        The port of the programmer
 ARDUINO_DEFAULT_BOARD       The board id of the rover
 ARDUINO_DEFAULT_SERIAL      The program use for serial communication
 ARDUINO_DEFAULT_PROGRAMMER  The programmer to use to program the rover
 arduinoisp_PROGRAMMER       The programmer to use to program the ArduinoISP sketch
 arduinoisp_BOARD            The board id of the board to upload the ArduinoISP sketch to

