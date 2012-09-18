#include <Arduino.h>

#ifndef SRF05_h
#define SRF05_h

class SRF05 {
public:
    SRF05(int pin);
    ~SRF05();
    
    int ping();
    static int ping(int pin);
    
private:
    int _pin;
};

#endif //SRF05_h
