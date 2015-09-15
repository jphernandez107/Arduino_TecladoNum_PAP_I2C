#include "Motor.h"

Motor::Motor(OpticalSensor *sensor, int pinSteps, int pinReset, int pinDirection, int maxStepsPerSecond) {
  mSensor = sensor;
  mPinSteps = pinSteps;
  mPinReset = pinReset;
  mPinDir = pinDirection;
  mMaxStepsPerSecond = maxStepsPerSecond;
  pinMode(mPinSteps, OUTPUT); 
  pinMode(mPinDir, OUTPUT); 
  pinMode(mPinReset, OUTPUT);  
}



void Motor::calibrate() {
  Serial.write("Calibrating");

// hack debug testing:
bool sensorFound = true;
//  bool sensorFound = mSensor->getStatus();
  while(!sensorFound) {
    moveSteps(1, 1, 1);
    sensorFound = mSensor->getStatus();
  }
   mTotalStepCount = 0;
}

void Motor::moveTo(int absolutePosMM, int speed) {
  boolean result = false;
  long desiredPosInSteps = absolutePosMM * INT_STEPS_PER_MM;
  
  if (desiredPosInSteps > INT_STEPS_MAX) {
    desiredPosInSteps = INT_STEPS_MAX;
  }

  long stepsToMove = abs(desiredPosInSteps - mPosInSteps);
  int dir = 1;
  if (desiredPosInSteps - mPosInSteps < 0) {
    dir = -1;
  }
  moveSteps(stepsToMove, dir, speed);
  // debug:
  String one = "Moving ";
  String two = " final pos in steps: ";
  String three = "\n";
  String debugString = one + stepsToMove + two + mPosInSteps + three ;
  
  Serial.print(debugString);
}

// speed is value between 1 and 100
void Motor::moveSteps(long relativeSteps, int dir, int speed) {
  
  // check if we need calibration
  if (mTotalStepCount >= LNG_SETP_LIMIT) {
    calibrate();
  }
  

  digitalWrite(mPinReset, LOW);   //Mientras reset este en LOW el motor permanecerá apagado y no sufrirá. El chip apagará todos los puertos y no leerá comandos.
  delay(100);
  digitalWrite(mPinReset, HIGH);   //Cuando reset se encuentre en HIGH el motor arrancará y leerá los comandos enviados.
  digitalWrite(mPinDir, LOW);

  for (long i = 0; i<=relativeSteps; i++)       //Equivale al numero de vueltas (200 es 360º grados) o micropasos
  {
    //debug
    Serial.print("Moving step ");
    Serial.print(mPosInSteps);
    Serial.print("\n");
    if (dir > 0) {
      digitalWrite(mPinSteps, HIGH);
      digitalWrite(mPinSteps, LOW);
      mPosInSteps++;
    } else {
      digitalWrite(mPinSteps, LOW);
      digitalWrite(mPinSteps, HIGH);
      mPosInSteps--;
    }
    
    long delayTime = (1000000/mMaxStepsPerSecond) * 100 / speed;
    delayMicroseconds(delayTime);     // Regula la velocidad, cuanto mas bajo mas velocidad.

  }

  // update absoluteSteps
  mPosInSteps += relativeSteps;
  
  // update steps count for calibration:"
  
  mTotalStepCount += abs(relativeSteps);
}

