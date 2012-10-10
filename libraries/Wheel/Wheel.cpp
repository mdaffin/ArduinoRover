#include "Wheel.h"

/* Static member variable definitions */
int Wheel::_max_speed = 500;
int Wheel::_min_speed = -500;
boolean Wheel::_running = false;
Wheel* Wheel::_left_wheel = 0;
Wheel* Wheel::_right_wheel = 0;
int Wheel::_led_pin = -1;
int Wheel::_reversed = 1;

/* Static public functions */
void Wheel::start()
{
    _running = true;
    update();
    digitalWrite(_led_pin, HIGH);
}

void Wheel::stop()
{
    _running = false;
    update();
    digitalWrite(_led_pin, LOW);
}

void Wheel::toggle_running()
{
    if (_running) {
        stop();
    }
    else {
        start();
    }
}

boolean Wheel::is_running()
{
    return _running;
}

void Wheel::add_led(int pin)
{
    _led_pin = pin;
    pinMode(_led_pin, OUTPUT);
    digitalWrite(_led_pin, HIGH);
    delay(200);
    digitalWrite(_led_pin, LOW);
}

void Wheel::flash_led()
{
    if (_led_pin) {
        if (_running) {
            digitalWrite(_led_pin, LOW);
            delay(50);
        }
        digitalWrite(_led_pin, HIGH);
        if (!_running) {
            delay(50);
            digitalWrite(_led_pin, LOW);
        }
    }
}

void Wheel::update()
{
    if (_left_wheel)
        _left_wheel->_update();
    if (_right_wheel)
        _right_wheel->_update();
}

void Wheel::forward()
{
    forward(true);
}

void Wheel::forward(boolean stright)
{
    _reversed = 1;
    if (stright) {
        _left_wheel->set_turn_factor(1);
        _right_wheel->set_turn_factor(1);
    }
}

void Wheel::reverse()
{
    reverse(true);
}

void Wheel::reverse(boolean stright)
{
    _reversed = -1;
    if (stright) {
        _left_wheel->set_turn_factor(1);
        _right_wheel->set_turn_factor(1);
    }
}
    
void Wheel::set_speed(int value)
{
    _left_wheel->set_wheel_speed(value);
    _right_wheel->set_wheel_speed(value);
}

void Wheel::increase_speed(int value)
{
    _left_wheel->set_wheel_speed(_left_wheel->wheel_speed() + value);
    _right_wheel->set_wheel_speed(_right_wheel->wheel_speed() + value);
}

void Wheel::turn_left(float factor)
{
    if (factor > 1)
        factor = 1;
    if (factor < -1)
        factor = -1;
    _left_wheel->set_turn_factor(1);
    _right_wheel->set_turn_factor(factor);
}

void Wheel::turn_right(float factor)
{
    if (factor > 1)
        factor = 1;
    if (factor < -1)
        factor = -1;
    _right_wheel->set_turn_factor(1);
    _left_wheel->set_turn_factor(factor);
}

void Wheel::add_left_wheel(int pin)
{
    _left_wheel = new Wheel(pin, true);
}

void Wheel::add_right_wheel(int pin)
{
    _right_wheel = new Wheel(pin, false);
}

/* Instance member functions */
Wheel::Wheel(int servo_pin, boolean reverse) : _center(1500), _turn_factor(1.)
{
    _wheel.attach(servo_pin);
    if (reverse) 
        _mounted_backwords = -1;
    else
        _mounted_backwords = 1;
    set_wheel_speed(100);
}

Wheel::~Wheel()
{
    _wheel.detach();
}

void Wheel::set_wheel_speed(int value)
{
    if (value > _max_speed) {
        value = _max_speed;
    } else if (value < _min_speed) {
        value = _min_speed;
    }
    _wheel_speed = value;
}

void Wheel::set_center(int value)
{
    _center = value;
}

int Wheel::wheel_speed()
{
    return _wheel_speed;
}

void Wheel::set_turn_factor(float factor)
{
    if (factor > 1)
        factor = 1;
    if (factor < -1)
        factor = -1;
    _turn_factor = factor;
}

void Wheel::_update()
{
    if (!_running) {
        _wheel.writeMicroseconds(_center);
    }
    else {
        int target = _wheel_speed * _turn_factor * _mounted_backwords * _reversed;
        target += _center;
        _wheel.writeMicroseconds(target);
    }
}
