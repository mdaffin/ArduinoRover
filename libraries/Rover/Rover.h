#ifndef Rover_h
#define Rover_h

#include <Servo.h>
#include <Bounce.h>

class Rover
{
    public:
        setLeftWheel(int pin);
        setRightWheel(int pin);
        setLeftBumper(int pin);
        setRightBumper(int pin);
        
    private:
        Servo leftWheel;
        Servo rightWheel;
        Bounce leftBumper;
        Bounce rightBumper;
}

#endif
