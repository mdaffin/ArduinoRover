#include <Arduino.h>
#include <Servo.h>
#include <Bounce.h>
#include <Wheel.h>
#define NOT_LDR
#define NOT_RANGE_FINDER
#include "Pins.h"

void setup()
{
    Serial.begin(9600);
    pinMode(red_pin, OUTPUT);
    pinMode(yellow_pin, OUTPUT);
    pinMode(blue_pin, OUTPUT);
    
    Wheel::add_left_wheel(left_wheel_pin);
    Wheel::add_right_wheel(right_wheel_pin);
    Wheel::add_led(wheel_led_pin);
    Wheel::set_speed(0);
}

void loop()
{
    bumper_left.update();
    bumper_right.update();
    toggle.update();
    up.update();
    down.update();
    if (bumper_left.read() == HIGH || bumper_right.read() == HIGH) {
        digitalWrite(wheel_led_pin, HIGH);
    } else {
        digitalWrite(wheel_led_pin, LOW);
    }
    if (toggle.read() == HIGH) {
        digitalWrite(blue_pin, HIGH);
    } else {
        digitalWrite(blue_pin, LOW);
    }
    if (up.read() == HIGH) {
        digitalWrite(yellow_pin, HIGH);
    } else {
        digitalWrite(yellow_pin, LOW);
    }
    if (down.read() == HIGH) {
        digitalWrite(red_pin, HIGH);
    } else {
        digitalWrite(red_pin, LOW);
    }
    if (toggle.risingEdge()) {
        Wheel::set_speed(0);
        Wheel::toggle_running();
    }
    if (up.risingEdge()) {
        Wheel::increase_speed(10);
    }
    if (down.risingEdge()) {
        Wheel::increase_speed(-10);
    }
    Wheel::update();
}
