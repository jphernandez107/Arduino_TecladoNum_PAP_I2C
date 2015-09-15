#include "Motor.h"

Motor::Motor(OpticalSensor *sensor) {
  mSensor = sensor;
}



void Motor::calibrate() {
  Serial.write("Calibrating");

  bool sensorFound = mSensor->getStatus();
  while(!sensorFound) {
    moveSteps(-1);
    sensorFound = mSensor->getStatus();
  }

  if (mPosInSteps > 0) {
    
  }
  

   mTotalStepCount = 0;
}

void Motor::moveTo(long absolutePosMM) {
  boolean result = false;
  long desiredPosInSteps = absolutePosMM * INT_STEPS_PER_MM;
  int finalStepsToMove = 0;
  if (desiredPosInSteps > INT_STEPS_MAX) {
    desiredPosInSteps = INT_STEPS_MAX;
  }
  
  moveSteps(desiredPosInSteps - mPosInSteps);
  // debug:
  String one = "Moving ";
  String two = " final pos in steps: ";
  String three = "\n";
  String debugString = one + finalStepsToMove + two + mPosInSteps + three ;
  
  Serial.print(debugString);
}

void Motor::moveSteps(long relativeSteps) {
  
  // check if we need calibration
  if (mTotalStepCount >= LNG_SETP_LIMIT) {
    calibrate();
  }
  
  // send command to pololu to move steps:
  // JJ

  // update absoluteSteps
  mPosInSteps += relativeSteps;
  
  // update steps count for calibration:"
  if (relativeSteps > 0) {
    mTotalStepCount += relativeSteps;
  } else {
    mTotalStepCount -= relativeSteps;
  }
}

