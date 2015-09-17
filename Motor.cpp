#include "Motor.h"

Motor::Motor(LcdDisplay *lcdDisplay, OpticalSensor *sensor, int pinSteps, int pinReset, int pinDirection, int maxStepsPerSecond) {
  mSensor = sensor;
  mPinSteps = pinSteps;
  mPinReset = pinReset;
  mPinDir = pinDirection;
  mMaxStepsPerSecond = maxStepsPerSecond;
  mLcdDisplay = lcdDisplay;
  pinMode(mPinSteps, OUTPUT); 
  pinMode(mPinDir, OUTPUT); 
  pinMode(mPinReset, OUTPUT);  
}



void Motor::calibrate() {

  //Pasar a lcdDisplay
  mLcdDisplay->printMsg1("Calibrating       ");
  mLcdDisplay->printMsg2("Please Wait       ");

// hack debug testing:
  bool sensorFound = true;
//  bool sensorFound = mSensor->getStatus();
  while(!sensorFound) {    
    sensorFound = mSensor->getStatus();
    moveSteps(5, -1, 100);
  }
   mTotalStepCount = 0;
}

void Motor::moveTo(int absolutePosMM, int speed) {
    mLcdDisplay->printMsg1("Moving            ");
    mLcdDisplay->printMsg2("Warning!          ");

  //debug--------------------------------------
  Serial.println("moveTo:");
  Serial.println(absolutePosMM);
  //Serial.println();
  Serial.println(speed);

  
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
  // debug:---------------------------------------
  String one = "Moving ";
  String two = " final pos in steps: ";
  String three = "\n";
  String debugString = one + stepsToMove + two + mPosInSteps + three ;  
  Serial.print(debugString);

}

// speed is value between 1 and 100
void Motor::moveSteps(long relativeSteps, int dir, int speed) {

  //debug----------------------------------------
  Serial.println("moveSteps:");
  Serial.println(relativeSteps);
  Serial.println(dir);
  Serial.println(speed);
  
  // check if we need calibration
  //if (mTotalStepCount >= LNG_SETP_LIMIT) {
    //calibrate();
  //}
  

  digitalWrite(mPinReset, LOW);   //Mientras reset este en LOW el motor permanecerá apagado y no sufrirá. El chip apagará todos los puertos y no leerá comandos.
  delay(100);
  digitalWrite(mPinReset, HIGH);   //Cuando reset se encuentre en HIGH el motor arrancará y leerá los comandos enviados.
  if(dir > 0){
    digitalWrite(mPinDir, LOW);
  }else if(dir < 0){
    digitalWrite(mPinDir, HIGH);
    }
  

  for (long i = 0; i<relativeSteps; i++)       //Equivale al numero de vueltas (200 es 360º grados) o micropasos
  {
    
    if (dir > 0) {
      digitalWrite(mPinSteps, HIGH);
      digitalWrite(mPinSteps, LOW);
      mPosInSteps++;
    } else if(dir < 0){
      digitalWrite(mPinSteps, LOW);
      digitalWrite(mPinSteps, HIGH);
      mPosInSteps--;
    }
    
    long delayTime = (1000000/mMaxStepsPerSecond) * 100 / speed;
    delayMicroseconds(delayTime);     // Regula la velocidad, cuanto mas bajo mas velocidad.

  } 
  mTotalStepCount += abs(relativeSteps);
}

