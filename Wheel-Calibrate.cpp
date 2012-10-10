#include <Arduino.h>
#include <Servo.h>
#include <Bounce.h>
#include <Wheel.h>
#define NOT_LDR
#define NOT_RANGE_FINDER
#include "Pins.h"

int state = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(Pins::led_pin, OUTPUT);
    
    Wheel::add_left_wheel(Pins::left_wheel_pin);
    Wheel::add_right_wheel(Pins::right_wheel_pin);
    Wheel::add_led(Pins::wheel_led_pin);
    Wheel::set_speed(0);
}

void loop()
{
    ;
    Wheel::set_speed(analogRead(Pins::pot_pin));
    button.update();
    if (button.risingEdge()) {
        switch(state) {
            case 0:
                Wheel::forward();
                Wheel::start();
                state = 1;
                break;
            case 1:
                Wheel::reverse();
                Wheel::start();
                state = 2;
                break;
            case 2:
                Wheel::stop();
                state = 0;
                break;
        }
    }
    Wheel::update();
}
