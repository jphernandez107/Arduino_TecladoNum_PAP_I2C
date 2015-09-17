#ifndef Motor_h
#define Motor_h
#include "OpticalSensor.h"
#include "LcdDisplay.h"


class Motor{
  private:
    const int INT_STEPS_PER_MM = 1;   // conversion from steps to mm ratio
    const int INT_STEPS_MAX = 2000;   // max steps supported by platform
    const long LNG_SETP_LIMIT = 10000;
    int mPinSteps;
    int mPinReset;
    int mPinDir;
    int mPosInSteps = 0;
    long mTotalStepCount = LNG_SETP_LIMIT;
    int mMaxStepsPerSecond = 1000;
    OpticalSensor *mSensor;
    void moveSteps(long relativeSteps, int dir, int speed);
    LcdDisplay *mLcdDisplay;
  public:
    Motor(LcdDisplay *lcd, OpticalSensor *sensor, int pinSteps, int pinReset, int pinDireccion, int maxStepsPerSecond);
    void moveTo(int mmToMove, int speed);    
    void calibrate();
  };

#endif

