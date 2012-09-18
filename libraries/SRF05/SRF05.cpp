#include <Arduino.h>
#include "SRF05.h"

SRF05::SRF05(int pin) : _pin(pin)
{
}

SRF05::~SRF05() {}

int SRF05::ping()
{
    return ping(_pin);
}

int SRF05::ping(int pin)
{
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
    delayMicroseconds(2);
    digitalWrite(pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(pin, LOW);
    
    pinMode(pin, INPUT);
    return pulseIn(pin, HIGH)/58;
}