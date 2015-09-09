class OpticalSensor{
  private:
      int mPin;
      bool mStatus = false;
    public:
      OpticalSensor(int);
      bool getStatus();
};

OpticalSensor::OpticalSensor(int pin) {
  mPin = pin;
}

bool OpticalSensor::getStatus() {
  // TODO: analog read, store status in variable mStatus...
  
  return mStatus;
}
  
  
