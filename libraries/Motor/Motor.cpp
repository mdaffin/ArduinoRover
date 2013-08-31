#include <Arduino.h>
#include <Motor.h>

Motor::Motor(int enPin, int pin1, int pin2) : _enPin(enPin), _pin1(pin1), _pin2(pin2) {}

void Motor::init() {
  pinMode(_enPin, OUTPUT);
  pinMode(_pin1, OUTPUT);
  pinMode(_pin2, OUTPUT);
  stop();
}

void Motor::setSpeed(int speed) {
  bool reversed = false;
  if (speed < 0) {
    reversed = true;
    speed = -speed;
  } 
  digitalWrite(_pin1, !reversed);
  digitalWrite(_pin2, reversed);
  analogWrite(_enPin, speed);
}

void Motor::stop() {
  digitalWrite(_pin1, LOW);
  digitalWrite(_pin2, LOW);
}

