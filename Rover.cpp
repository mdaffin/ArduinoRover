#ifndef NOT_RANGE_FINDER
#include "libraries/SRF05/SRF05.h"
#endif
#include <Servo.h>
#include "libraries/Wheel/Wheel.h"
#include "libraries/AI/AI.h"
#include "libraries/Bounce/Bounce.h"

/* Digital Pins*/
const int green_pin = 2;
const int blue_pin = 3;
const int red_pin = 4;
const int left_wheel_pin = 5;
const int right_wheel_pin = 6;
#ifndef NOT_RANGE_FINDER
const int range_finder_pin = 7;
#endif
const int bumper_left_pin = 8;
const int bumper_right_pin = 9;
const int up_pin = 10;
const int toggle_pin = 11;
const int down_pin = 12;
const int wheel_led_pin = 13;

/* Analog Pins */
#ifndef NOT_POTENTIOMETER
const int pot_pin = 0;
#endif
#ifndef NOT_LDR
const int ldr_pin = 1;
#endif

/* Switches */
Bounce bumper_left(bumper_left_pin, 5);
Bounce bumper_right(bumper_right_pin, 5);
Bounce toggle(toggle_pin, 5);
Bounce down(down_pin, 5);
Bounce up(up_pin, 5);

/* Range finder */
#ifndef NOT_RANGE_FINDER
const int MAX_DISTANCE = 5;
SRF05 front_rf(range_finder_pin);
int front_distance;
#endif

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
    if (bumper_left.risingEdge()) {
        AI::bumper_hit(AI::Left);
        return;
    }
    if (bumper_right.risingEdge()) {
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
    pinMode(red_pin, OUTPUT);
    pinMode(green_pin, OUTPUT);
    pinMode(blue_pin, OUTPUT);
    // Turn on colour leds to indicate loading started
    digitalWrite(red_pin, HIGH);
    digitalWrite(blue_pin, HIGH);
    digitalWrite(green_pin, HIGH);
    
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
    digitalWrite(red_pin, LOW);
    digitalWrite(blue_pin, LOW);
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
    digitalWrite(green_pin, green_state);
#ifdef DEBUG // Make it easier to read serial output
    delay(100);
#endif
}