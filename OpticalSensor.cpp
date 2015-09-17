#include "OpticalSensor.h"

OpticalSensor::OpticalSensor(int pin) {
  	mPin = pin;
}

bool OpticalSensor::getStatus() {
  // TODO: analog read, store status in variable mStatus...

	int sensorValue = analogRead(mPin);
	float voltage = sensorValue * (5.0 / 1023.0);

	if((voltage >= 0.21) && (voltage <= 7.0)){
    	mStatus == true;
    }
  	else{
    	mStatus == false;
    }
  
  	return mStatus;
}
  
  
