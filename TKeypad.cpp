#include "TKeypad.h"

TKeypad::TKeypad(LcdDisplay *lcdDisplay, bool useSerial) : mKeypad((char*)teclas, pinFilas, pinColumnas, 4, 3 ) {
  mLcdDisplay = lcdDisplay;
  mUseSerial = useSerial;
}

String TKeypad::getInput() {
  String result = "";
  int count = 0;

  while (count < INPUT_CHAR_NUMBER + 1) {
    mLcdDisplay->printMsg1("Enter digits:");
    mLcdDisplay->printMsg2(result + "           ");
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
        mLcdDisplay->printMsg1("Enter digits:       ");
        mLcdDisplay->printMsg2("At least 1 digit");
      }
    } else if (mLastChar == CHAR_CLEAR){
      // reset everything...
      mLcdDisplay->printMsg2("Cleared      ");
      result = "";
      count = 0;
      mLastChar = 'z';
      delay(1000);
    } else if(count == INPUT_CHAR_NUMBER) {
      // entered the max numbers already  and no OK given.. warn and ignore
       mLcdDisplay->printMsg2("Enter OK or CLEAR");
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


