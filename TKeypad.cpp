#include "TKeypad.h"

TKeypad::TKeypad(LcdDisplay *lcdDisplay, bool useSerial) : mKeypad((char*)teclas, pinFilas, pinColumnas, 4, 3 ) {
  mLcdDisplay = lcdDisplay;
  mUseSerial = useSerial;
}

String TKeypad::getInput() {
  String result = "";
  int count = 0;

  while (count < INPUT_CHAR_NUMBER + 1) {
    mLcdDisplay->print("Enter digits:", result);
    //Serial.println("Enter digits :" + result);
       mLastChar = mKeypad.getKey();
    if(mLastChar != NO_KEY){
   // if (mUseSerial) {
      //mLastChar = getKeyFromSerial();
   // } else {

      
  //  }
    // the last char should be ignored if
    if (mLastChar == CHAR_OK) {
      if (count >0) {
        // Last digit is ok and a number was entered...
        result += mLastChar;
        break;
      } else {
        //ignore an OK with no number
        mLcdDisplay->print("Enter digits:", "(At least 1 digit)");
      }
    } else if (mLastChar == CHAR_CLEAR){
      // reset everything...
      mLcdDisplay->print("", "Cleared");
      Serial.println("Cleared");
      result = "";
      count = 0;
      mLastChar = 'z';
    } else if(count == INPUT_CHAR_NUMBER) {
      // entered the max numbers already  and no OK given.. warn and ignore
       mLcdDisplay->print("", "Please enter OK or CLEAR");
    } else {
      result += mLastChar;
      count++;
    }
    

  }
  }

  // Reset last char to anything.
  mLastChar = 'z';
  return result;
}

/*char TKeypad::getKeyFromSerial() {
  char value = 'x';
  while (!Serial.available()) {
    delay(100);
  }

  value = Serial.read();
  return value;
}*/

