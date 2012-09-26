#include <Arduino.h>
#include "SRF05.h"

SRF05::SRF05(int pin) : _pin(pin)
{
}

SRF05::~SRF05() {}

int SRF05::ping()
{
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, LOW);
    delayMicroseconds(2);
    digitalWrite(_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_pin, LOW);
    
    pinMode(_pin, INPUT);
    return pulseIn(_pin, HIGH)/58;
}