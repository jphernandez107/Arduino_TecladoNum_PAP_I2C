<<<<<<< HEAD
=======
#ifndef LcdDisplay_h
#define LcdDisplay_h
>>>>>>> origin/master

#include <LiquidCrystal_I2C.h>


#define TYPE 0x27
#define COLS 16
#define ROWS 2

class LcdDisplay {
  private:
    LiquidCrystal_I2C mLcd;
  public:
    LcdDisplay();
    void print(String msg1, String msg2);
};
<<<<<<< HEAD
=======

#endif
>>>>>>> origin/master
