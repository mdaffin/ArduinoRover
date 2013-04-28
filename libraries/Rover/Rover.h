#ifndef Rover_h
#define Rover_h

#include <Arduino.h>
#include <Servo.h>
#include <Bounce.h>
#include <Timer.h>

class Rover
{
    public:
        Rover();
        void setLeftWheel(int pin);
        void setRightWheel(int pin);
        void setLeftBumper(int pin);
        void setRightBumper(int pin);
        void setLED1(int pin);
        void setLED2(int pin);
        void setSwitch(int pin);

        void turnLED1(bool on);
        void turnLED2(bool on);
        bool isRunning();
        void start(int speed = 50);
        void stop();
        void emergency();
        void setSpeed(int speed);
        int speed();
        void increaseSpeed(int speed);
        void decreaseSpeed(int speed);
        void setTurnFactor(float factor);
        float turnFactor();
        void update();
        
    private:
        Servo _leftWheel;
        Servo _rightWheel;
        int _leftWheelPin;
        int _rightWheelPin;
        Bounce _leftBumper;
        Bounce _rightBumper;
        Bounce _switch;
        int _led1;
        int _led2;
        bool _running;
        bool _emergency;
        int _speed;
        float _turnFactor;
        Timer _timer;
        int _timerid;
        int _centerSpeed = 90;
};

#endif
