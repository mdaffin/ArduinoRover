class Motor {
    public:
      Motor(enPin, pin1, pin2);
      init();
      setSpeed(int speed);
      stop();
      start();
      start(int speed);
    private:
      int _speed;
      int _enPin;
      int _pin1;
      int _pin2;
}
