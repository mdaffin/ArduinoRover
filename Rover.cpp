#include <Arduino.h>
#include <Servo.h>
#include <Wheel.h>
#include <AI.h>
#ifndef NOT_RANGE_FINDER
#include <SRF05.h>
#endif
#include <Bounce.h>
#include "Pins.h"

/* forward declerations */
void check_switches();
void check_bumpers();
void forward();
void backup();
void turn_random();

void check_switches()
{
    bumper_left.update();
    bumper_right.update();
    if (bumper_left.read() == HIGH) {
        AI::bumper_hit(AI::Left);
        return;
    }
    if (bumper_right.read() == HIGH) {
        AI::bumper_hit(AI::Right);
        return;
    }
    if (toggle.update()) {
        if (toggle.risingEdge()) {
            Wheel::toggle_running();
            AI::wonder();
        }
    }
    if (down.update()) {
        if (down.risingEdge()) {
            Wheel::forward();
        }
    }
    if (up.update()) {
        if (up.risingEdge()) {
            Wheel::reverse();
        }
    }
}

void check_bumpers()
{    
}

int green_state = HIGH;

void setup()
{
    // Setup colour leds
    pinMode(led_pin, OUTPUT);
    // Turn on colour leds to indicate loading started
    digitalWrite(led_pin, HIGH);
    
    // Setup other pins
    pinMode(bumper_left_pin, INPUT);
    pinMode(bumper_right_pin, INPUT);
    pinMode(toggle_pin, INPUT);
    pinMode(down_pin, INPUT);
    pinMode(up_pin, INPUT);
    
    // Setup communication and random numbers
    Serial.begin(9600);
    randomSeed(analogRead(5));
    
    // Initlise switches
    check_switches();
    
    // Setup wheels
    Wheel::add_left_wheel(left_wheel_pin);
    Wheel::add_right_wheel(right_wheel_pin);
    Wheel::add_led(wheel_led_pin);
    
    // Setup AI
    AI::init();
    
    // Turn off red and blue led to indicate setup has finished
    digitalWrite(led_pin, LOW);
}

void loop()
{
#ifndef NOT_RANGE_FINDER
    front_distance = front_rf.ping();
#ifdef DEBUG
    Serial.print("Front Distance: ");
    Serial.println(front_distance);
#endif
    
    if (front_distance > MAX_DISTANCE) {
        AI::edge_detected();
    }
#endif

#ifndef NOT_POTENTIOMETER
    int speed = analogRead(pot_pin)/2;
    Wheel::set_speed(speed);
#endif
#ifndef NOT_LDR
#ifdef DEBUG
    Serial.println(analogRead(ldr_pin));
#endif
#endif
    check_bumpers();
    check_switches();
    AI::advance();
    
    green_state = !green_state;
    digitalWrite(yellow_pin, green_state);
#ifdef DEBUG // Make it easier to read serial output
    delay(100);
#endif
}