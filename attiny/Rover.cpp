#include <Arduino.h>

void setup()
{
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, INPUT);
    pinMode(10, INPUT);
    digitalwrite(7, LOW);
    digitalwrite(8, LOW);
    Serial.begin(9600);
    delay(100);
    digitalwrite(7, digitalread(9));
    digitalwrite(8, digitalread(10));
}

void loop()
{
    digitalWrite(7 digitalRead(9));
    digitalWrite(8 digitalRead(10));
    delay(10);
}
