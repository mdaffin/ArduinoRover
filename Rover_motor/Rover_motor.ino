#include <Arduino.h>
#include <Motor.h>

int m1 = 5;
int m2 = 6;
int led = 13;

void setup()
{
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(led, OUTPUT);
}

void loop()
{
  digitalWrite(led, HIGH);
  digitalWrite(m1, LOW);
  digitalWrite(m2, HIGH);
}
