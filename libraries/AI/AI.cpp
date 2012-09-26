#include "AI.h"
#include <Wheel.h>
/* Global varibles */
unsigned int _stage = 0;
long _stage_time = 0;
unsigned long _last_time = 0;
AI::Mode _mode = AI::Stop;
int _data = 0;

/* Forward declerations */
void advance_wander();
void advance_backup();

/* Private functions */
void advance_wander()
{
    _stage = 0;
    switch (_stage) {
        case 0:
            _stage_time = 999999;
            Wheel::forward();
            Serial.println("AI::Wondering");
            break;
    }
}

void advance_backup()
{
    switch (_stage) {
        case 0:
            _stage_time = random(400, 1500);
            Wheel::forward();
            Wheel::reverse();
#ifdef DEBUG
            Serial.println("AI::Backing up");
#endif
            break;
        case 1:
            _stage_time = random(200,2000);
            if (_data == AI::Left)
                Wheel::turn_right(-1);
            else
                Wheel::turn_left(-1);
#ifdef DEBUG
                Serial.println("AI::Turning right");
#endif
                break;
        case 2:
            AI::wonder();
    }
}

/* Public functions */
void AI::init()
{
}

void AI::advance()
{
    unsigned long current_time = millis();
    _stage_time -= (current_time - _last_time);
    if (_stage_time <= 0) {
        if (_mode == AI::Wonder) {
            advance_wander();
        } else if (_mode == AI::Backup) {
            advance_backup();
        } else {
	  stop();
	}
        _stage++;
    }
    Wheel::update();
    _last_time = current_time;
}

void AI::bumper_hit(AI::Direction direction)
{
    _mode = AI::Backup;
    _stage = 0;
    _stage_time = 0;
    _data = direction;
#ifdef DEBUG
    Serial.println("AI::bumper_hit");
#endif
}

void AI::edge_detected()
{
    _mode = AI::Backup;
    _stage = 0;
    _stage_time = 0;
#ifdef DEBUG
    Serial.println("AI::edge_detected");
#endif
}

void AI::wonder()
{
    _mode = AI::Wonder;
    _stage = 0;
    _stage_time = 0;
#ifdef DEBUG
    Serial.println("AI::wonder");
#endif
}

void AI::stop()
{
    _mode = AI::Stop;
    _stage = 0;
    _stage_time = 0;
    Wheel::stop();
#ifdef DEBUG
    Serial.println("AI::Stop");
#endif
}