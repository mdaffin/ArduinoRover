ArduinoISP
==========
If you are using the arduino uno or similar as the programmer you must first upload the ArduinoISP sketch to the arduino to do this run the following:

 mkdir build
 cd build
 cmake ..
 make arduinoisp-upload

Build
=====
To build and upload the sketch run the following:

 mkdir build
 cd build
 cmake ..
 make rover-upload
 make rover-burn

Known issues
============
Sometimes uploading seams to up load a blank sketch, if this happens just run `make rover-burn` and that should fix the issue.

