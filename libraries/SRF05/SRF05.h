#include <Arduino.h>

#ifndef SRF05_h
#define SRF05_h

class SRF05 {
public:
    SRF05(int pin);
    ~SRF05();
    
    int ping();

    boolean triggered();
    void set_limit(int limit);
    int limit();
    
private:
    int _pin;
    int _trigger_limit;
    int last_value;
};

#endif //SRF05_h
