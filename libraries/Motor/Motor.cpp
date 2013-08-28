#include <Arduino.h>
#include <Motor.h>

Motor::Motor(enPin, pin1, pin2) : _enPin(enPin), _pin1(pin1), _pin2,(pin2), _speed(1) {}

Motor::init() {
  pinMode(_enPin, OUTPUT);
  pinMode(_pin1, OUTPUT);
  pinMode(_pin2, OUTPUT);
  stop();
}

Motor::setSpeed(int speed) {
  _speed = speed;
  bool reversed = false;
  if (speed < 0) {
    reversed = true;
    speed = -speed;
  } 
  digitalWrite(_pin1, !reversed);
  digitalWrite(_pin2, reversed);
}

Motor::stop() {
  digitalWrite(_pin1, LOW);
  digitalWrite(_pin2, LOW);
}

Motor::start() {
  setSpeed(_speed);
}

Motor::start(int speed) {
  setSpeed(speed);
}

