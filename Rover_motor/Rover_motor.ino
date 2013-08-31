#include <Arduino.h>
#include <Motor.h>

int m1 = 6;
int m2 = 7;
int m3 = 8;
int led = 13;
Motor motor(6,7,8);

void setup()
{
  motor.init();
  pinMode(led, OUTPUT);
}

int speed = 0;

void loop()
{
  digitalWrite(led, LOW);
  motor.setSpeed(speed++);
  if (speed >= 255) speed = -255;
  delay(100);
}
