#include <Rover.h>

Rover::Rover() : _led1(-1), _led2(-1), _running(false), _emergency(false), _speed(0), _turnFactor(0), _timerid(-1) {}

void Rover::setLeftWheel(int pin) { 
    _leftWheelPin = pin;
}

void Rover::setRightWheel(int pin) {
    _rightWheelPin = pin;
}

void Rover::setLeftBumper(int pin) { _leftBumper.attach(pin, 5); }
void Rover::setRightBumper(int pin) { _rightBumper.attach(pin, 5); }

void Rover::setLED1(int pin) {
    _led1 = pin;
    pinMode(_led1, OUTPUT);
    digitalWrite(_led1, HIGH);
}

void Rover::setLED2(int pin) {
    _led2 = pin;
    pinMode(_led2, OUTPUT);
    digitalWrite(_led2, HIGH);
}

void Rover::setSwitch(int pin) { _switch.attach(pin, 5); }
void Rover::turnLED1(bool on) { digitalWrite(_led1, !on); }
void Rover::turnLED2(bool on) { digitalWrite(_led2, !on); }
bool Rover::isRunning() { return _running; }

void Rover::start(int speed) {
    if (_emergency) return;
    _leftWheel.attach(_leftWheelPin);
    _rightWheel.attach(_rightWheelPin);
    turnLED1(HIGH);
    _speed = speed;
    _turnFactor = 0;
    _running = true;
}

void Rover::stop() {
    if (_emergency) return;
    _leftWheel.write(_centerSpeed);
    _rightWheel.write(_centerSpeed);
    delay(100);
    _leftWheel.detach();
    _rightWheel.detach();
    turnLED1(LOW);
    _speed = 0;
    _turnFactor = 0;
    _running = false;
}

void Rover::emergency() {
    _leftWheel.detach();
    _rightWheel.detach();
    _emergency = true;
    _running = false;
    turnLED1(LOW);
}

void Rover::setSpeed(int speed) { _speed = speed; }
int Rover::speed() { return _speed; }
void Rover::increaseSpeed(int speed) { _speed += speed; }
void Rover::decreaseSpeed(int speed) { _speed -= speed; }
void Rover::setTurnFactor(float factor) { _turnFactor = factor; }
float Rover::turnFactor() { return _turnFactor; }

void Rover::update() {
    if (_emergency) {
        LED2(HIGH);
        delay(500);
        LED2(LOW);
        delay(500);
        return;
    }
    
    _switch.update();
    if (_switch.fallingEdge()) {
        if (isRunning()) {
            stop();
        } else {
            start(50);
        }
    }
    _leftBumper.update();
    _rightBumper.update();
    if (_leftBumper.read() == LOW) {
        emergency();
    } else if (_rightBumper.read() == LOW) {
        emergency();
    }
    if (_leftWheel.attached() ) {
        _leftWheel.write(_centerSpeed - speed());
    }
    if (_rightWheel.attached()) {
        _rightWheel.write(_centerSpeed + speed());
    }
    _timer.update();
}
