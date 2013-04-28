#include <Arduino.h>

#include <Servo.h> 
#include <Bounce.h>
#include <Timer.h>
#include <Rover.h>

Rover rover;

void setup()
{
    rover.setLeftWheel(2);
    rover.setRightWheel(3);
    rover.setLeftBumper(9);
    rover.setRightBumper(10);
    rover.setLED1(8);
    rover.setLED2(7);
    rover.setSwitch(5);
}

void loop()
{
    rover.update();
}
