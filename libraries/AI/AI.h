#include <Arduino.h>
#ifndef AI_h
#define AI_h

namespace AI {
    enum Direction { Left, Right };
    enum Mode { Backup, Wonder, Spiral, Stop };

    void init();
    void advance();
    void bumper_hit(Direction direction);
    void edge_detected(Direction direction);
    void wonder();
    void spiral();
    void stop();
    
};

#endif //AI_h