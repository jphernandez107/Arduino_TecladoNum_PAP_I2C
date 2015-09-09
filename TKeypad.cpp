#include "TKeypad.h"
//Keypad keypad = Keypad;
TKeypad::TKeypad(LcdDisplay lcdDisplay) : mKeyPad(makeKeymap(teclas), pinFilas, pinColumnas, 4, 3 ) {
  mLcdDisplay = lcdDisplay;
  
}

String TKeypad::getInput() {
  String result = "";
  int count = 0;
  char lastChar = 'z';
  
  while(count < INPUT_CHAR_NUMBER + 1 && mLastChar != mEndChar ) {
    mLcdDisplay.print("Enter digits:", result);
    mLastChar = mKeyPad.getKey();
    result += mLastChar; 
  }

  mLastChar = 'z';
  return result;
}

