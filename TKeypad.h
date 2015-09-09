#ifndef TKeypad_h
#define TKeypad_h

#include "LcdDisplay.h"
#include "Arduino.h"
#include "Keypad.h"
#define INPUT_CHAR_NUMBER 3

class TKeypad{  
  private:
    LcdDisplay *mLcdDisplay;
    char mLastChar;
    char mEndChar = '#'; 
    Keypad *mKeypad;
  public:
    TKeypad(LcdDisplay *lcd, Keypad *keypad);
    String getInput();
};

#endif
