
#ifndef LcdDisplay_h
#define LcdDisplay_h

#include <LiquidCrystal_I2C.h>
#include "Arduino.h"
#include <Wire.h>


#define TYPE 0x27
#define COLS 16
#define ROWS 2

class LcdDisplay {
  private:
    LiquidCrystal_I2C mLcd;
    bool mUseSerial = false;
    
  public:
    LcdDisplay(bool useSerial);
    void printMsg1(String msg1);
    void printMsg2(String msg2);
    void init();
};


#endif
