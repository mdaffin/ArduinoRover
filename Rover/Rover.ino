#include <Arduino.h>

#include <Servo.h> 
#include <Bounce.h>
#include <Timer.h>
#include <Rover.h>

Rover rover;

void setup()
{
    rover.setLeftWheel(9);
    rover.setRightWheel(10);
    rover.setLeftBumper(3);
    rover.setRightBumper(4);
    rover.setLED1(7);
    rover.setLED2(8);
    rover.setSwitch(2);
}

void loop()
{
    rover.update();
}
