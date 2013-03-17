#include <Arduino.h>

void setup()
{
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, INPUT);
    pinMode(10, INPUT);
    pinMode(5, INPUT);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    delay(1000);
    digitalWrite(7, digitalRead(9));
    digitalWrite(8, digitalRead(10));
}

void loop()
{
    digitalWrite(7, digitalRead(9) && digitalRead(5));
    digitalWrite(8, digitalRead(10) && digitalRead(5));
    delay(10);
}
