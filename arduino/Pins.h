#ifndef Pins_h
#define Pins_h
#include <Arduino.h>
#include <Bounce.h>
#include <Wheel.h>

namespace Pins
{
    /* Digital Pins*/
    const int button_pin = 2;
    const int left_bumper_pin = 3;
    const int right_bumper_pin = 4;
    const int left_wheel_pin = 5;
    const int right_wheel_pin = 6;
    const int left_edge_pin = 7;
    const int right_edge_pin = 8;
    const int led_pin = 12;
    const int wheel_led_pin = 13;

    /* Analog Pins */
    #ifndef NOT_POTENTIOMETER
    const int pot_pin = 0;
    #endif
    /* Initlizes the pins */
    void init() {
        // Setup colour leds
        pinMode(led_pin, OUTPUT);
        // Turn on colour leds to indicate loading started
        digitalWrite(led_pin, HIGH);

        // Setup other pins
        pinMode(left_bumper_pin, INPUT);
        pinMode(right_bumper_pin, INPUT);
        pinMode(left_edge_pin, INPUT);
        pinMode(right_edge_pin, INPUT);
        pinMode(button_pin, INPUT);

        // Setup wheels
        Wheel::add_left_wheel(left_wheel_pin);
        Wheel::add_right_wheel(right_wheel_pin);
        Wheel::add_led(wheel_led_pin);
    }
}


    /* Switches */
    Bounce bumper_left(Pins::left_bumper_pin, 5);
    Bounce bumper_right(Pins::right_bumper_pin, 5);
    Bounce button(Pins::button_pin, 5);
    Bounce left_edge(Pins::left_edge_pin, 5);
    Bounce right_edge(Pins::right_edge_pin, 5);

#endif //Pins_h