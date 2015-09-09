#ifndef OpticalSensor_h
#define OpticalSensor_h


#include "Arduino.h"


class OpticalSensor{
  	private:
      	int mPin;
      	bool mStatus = false;
  	public:
      	OpticalSensor(int);
      	bool getStatus();
};

#endif
