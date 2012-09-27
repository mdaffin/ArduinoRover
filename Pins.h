#ifndef Pins_h
#define Pins_h
#include <Bounce.h>
#ifndef NOT_RANGE_FINDER
#include <SRF05.h>
#endif

/* Digital Pins*/
const int wheel_led_pin = 13;
const int led_pin = 12;
const int left_wheel_pin = 5;
const int right_wheel_pin = 6;
const int bumper_left_pin = 8;
const int bumper_right_pin = 9;
const int up_pin = 2;
const int toggle_pin = 3;
const int down_pin = 4;

/* Analog Pins */
#ifndef NOT_POTENTIOMETER
const int pot_pin = 0;
#endif
#ifndef NOT_LDR
const int ldr_pin = 1;
#endif

/* Switches */
Bounce bumper_left(bumper_left_pin, 5);
Bounce bumper_right(bumper_right_pin, 5);
Bounce toggle(toggle_pin, 5);
Bounce down(down_pin, 5);
Bounce up(up_pin, 5);

/* Range finder */
#ifndef NOT_RANGE_FINDER
const int range_finder_pin = 7;
const int MAX_DISTANCE = 6;
SRF05 front_rf(range_finder_pin);
int front_distance;
#endif
#endif //Pins_h