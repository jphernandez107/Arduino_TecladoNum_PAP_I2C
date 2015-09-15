#ifndef Motor_h
#define Motor_h
#include "OpticalSensor.h"


class Motor{
  private:
    const int INT_STEPS_PER_MM = 5;   // conversion from steps to mm ratio
    const int INT_STEPS_MAX = 2000;   // max steps supported by platform
    const long LNG_SETP_LIMIT = 10000;
    int mPinSteps;
    int mPinReset;
    int mPinDir;
    int mPosInSteps = 0;
    long mTotalStepCount = LNG_SETP_LIMIT;
    int mMaxStepsPerSecond = 1;
    OpticalSensor *mSensor;
    void calibrate();
    void moveSteps(long relativeSteps, int dir, int speed);
  public:
    Motor(OpticalSensor *sensor, int pinSteps, int pinReset, int pinDireccion, int maxStepsPerSecond);
    void moveTo(int mmToMove, int speed);
  };

#endif

