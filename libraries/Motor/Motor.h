class Motor {
    public:
      Motor(int enPin, int pin1, int pin2);
      void init();
      void setSpeed(int speed);
      void stop();
    private:
      int _enPin;
      int _pin1;
      int _pin2;
};
