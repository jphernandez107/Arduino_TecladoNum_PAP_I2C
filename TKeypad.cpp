#include "TKeypad.h"

TKeypad::TKeypad(LcdDisplay *lcdDisplay, Keypad *keypad) {
  mLcdDisplay = lcdDisplay;
  mKeypad = keypad;
  
}

String TKeypad::getInput() {
  String result = "";
  int count = 0;
  char lastChar = 'z';
  
  while(count < INPUT_CHAR_NUMBER + 1 && mLastChar != mEndChar ) {
    mLcdDisplay->print("Enter digits:", result);
    mLastChar = mKeypad->getKey();
    result += mLastChar; 
  }

  mLastChar = 'z';
  return result;
}

