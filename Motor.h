#ifndef Motor_h
#define Motor_h
#include "OpticalSensor.h"


class Motor{
  private:
    const int INT_STEPS_PER_MM = 5;   // conversion from steps to mm ratio
    const int INT_STEPS_MAX = 2000;   // max steps supported by platform
    const long LNG_SETP_LIMIT = 10000;
    int mPosInSteps = 0;
    long mTotalStepCount = LNG_SETP_LIMIT;
    OpticalSensor *mSensor;
    void calibrate();
    void moveSteps(long relativeSteps);
  public:
    Motor(OpticalSensor *sensor);
    void moveTo(long mmToMove);
  };

#endif

