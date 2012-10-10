#include "Arduino.h"
#include "Servo.h"
#ifndef Wheels_h
#define Wheels_h

class Wheel
{
public:
    static void start();
    static void stop();
    static void update();
    static void forward();
    static void forward(boolean stright);
    static void set_speed(int value);
    static void reverse();
    static void reverse(boolean stright);
    static void increase_speed(int value);
    static void turn_left(float factor);
    static void turn_right(float factor);
    static void toggle_running();
    static boolean is_running();
    static void add_left_wheel(int pin);
    static void add_right_wheel(int pin);
    static void add_led(int pin);
    static void flash_led();
    int wheel_speed();
    void set_turn_factor(float factor);
    void set_wheel_speed(int value);
    void set_center(int value);
    
private:
    Wheel(int servo_pin, boolean reverse = false);
    ~Wheel();
    void _update();
    
    int _mounted_backwords;
    int _wheel_speed;
    int _center;
    Servo _wheel;
    float _turn_factor;
    
    static int _reversed;
    static int _max_speed;
    static int _min_speed;
    static boolean _running;
    static Wheel* _left_wheel;
    static Wheel* _right_wheel;
    static int _led_pin;
    
};

#endif //Wheels_h
