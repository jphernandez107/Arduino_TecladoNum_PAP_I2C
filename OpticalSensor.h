#include "arduino.h";


class OpticalSensor{
  	private:
      	int mPin;
      	bool mStatus = false;
  	public:
      	OpticalSensor(int);
      	bool getStatus();
};