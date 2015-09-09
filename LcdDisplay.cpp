#include <LiquidCrystal_I2C.h>

#define TYPE 0x27
#define COLS 16
#define ROWS 2

class LcdDisplay {
  private:
    LiquidCrystal_I2C mLcd;
  public:
    LcdDisplay();
};

LcdDisplay::LcdDisplay() : mLcd(TYPE,COLS,ROWS) {
}



