#include <LiquidCrystal_I2C.h>


class LcdDisplay {
  private:
    LiquidCrystal_I2C *mLcd;
  public:
    LcdDisplay(LiquidCrystal_I2C *lcd);
};

LcdDisplay::LcdDisplay(LiquidCrystal_I2C *lcd) {
  mLcd = lcd;
}



