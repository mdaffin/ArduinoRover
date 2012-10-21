#include <Arduino.h>
#include <Servo.h>
#include <Wheel.h>
#include <Bounce.h>
#include "Pins.h"
#include "Debug.h"

void setup() {

    Pins::init();
    Serial.begin(9600);
}

void loop() {
    left_edge.update();
    right_edge.update();
    Serial.print("left: ");
    Serial.println(bumper_left.read());
    Serial.print("right: ");
    Serial.println(bumper_right.read());
    delay(100);
}