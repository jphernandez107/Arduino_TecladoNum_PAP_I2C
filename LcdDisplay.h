
#ifndef LcdDisplay_h
#define LcdDisplay_h

#include <LiquidCrystal_I2C.h>
#include "Arduino.h"


#define TYPE 0x27
#define COLS 16
#define ROWS 2

class LcdDisplay {
  private:
    LiquidCrystal_I2C mLcd;
    bool mUseSerial = false;
  public:
    LcdDisplay(bool useSerial);
    void print(String msg1, String msg2);
};


#endif
