#include <Arduino.h>

#include <Servo.h> 
#include <Rover.h>

Rover rover;

void setup()
{
    rover.setLeftWheel(2);
    rover.setRightWheel(3);
    rover.setLeftBumper(9);
    rover.setRightBumper(10);

    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
}

void loop()
{
    
}
