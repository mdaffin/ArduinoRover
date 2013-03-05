#include <Arduino.h>
#include <Servo.h>
#include <Wheel.h>
#include <AI.h>
#include <Bounce.h>
#include "Pins.h"
#include "Debug.h"

/* forward declerations */
boolean check_switches();
boolean check_bumpers();
boolean check_edges();

boolean check_switches()
{
    if (button.update()) {
        if (button.risingEdge()) {
            Wheel::toggle_running();
            if (Wheel::is_running())
                AI::wonder();
            else
                AI::stop();
        }
    }
}

boolean check_bumpers()
{
    bumper_left.update();
    bumper_right.update();
    if (bumper_left.read() == HIGH) {
        AI::bumper_hit(AI::Left);
        return true;
    }
    if (bumper_right.read() == HIGH) {
        AI::bumper_hit(AI::Right);
        return true;
    }
    return false;
}

boolean check_edges()
{
    left_edge.update();
    right_edge.update();
    if (left_edge.read() == HIGH) {
        AI::edge_detected(AI::Left);
        debug_print("Left edge hit");
        return true;
    }
    if (right_edge.read() == HIGH) {
        AI::edge_detected(AI::Right);
        debug_print("Right edge hit");
        return true;
    }
    return false;
}

void setup()
{
    Pins::init();

    // Setup communication and random numbers
    Serial.begin(9600);
    randomSeed(analogRead(5));

    // Setup AI
    AI::init();

    // Turn off red and blue led to indicate setup has finished
    digitalWrite(Pins::led_pin, LOW);
}

void loop()
{
#ifndef NOT_POTENTIOMETER
    int speed = analogRead(Pins::pot_pin)/2;
    Wheel::set_speed(speed);
#endif
    if (!check_switches()) {

    }
    if (!check_edges()) {

    }
    if (!check_bumpers()) {

    }
    AI::advance();

#ifdef DEBUG
    delay(100); // Make it easier to read serial output
#endif
}