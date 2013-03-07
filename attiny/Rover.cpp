#include <Arduino.h>

void setup()
{
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, INPUT);
    pinMode(10, INPUT);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    Serial.begin(9600);
    delay(1000);
    digitalWrite(7, digitalRead(9));
    digitalWrite(8, digitalRead(10));
}

void loop()
{
    digitalWrite(7, digitalRead(9));
    digitalWrite(8, digitalRead(10));
    delay(10);
}
