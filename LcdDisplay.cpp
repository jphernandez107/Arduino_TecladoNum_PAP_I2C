
#include "LcdDisplay.h"

LcdDisplay::LcdDisplay(bool useSerial) : mLcd(TYPE,COLS,ROWS) {
  mUseSerial = useSerial;
}

void LcdDisplay::print(String msg1, String msg2) {
  if(mUseSerial) {
    Serial.print(msg1);
    Serial.print('\n');
    Serial.print(msg2);
    Serial.print('\n');
  } else {
    // JJ
    // put code to print two lines in the LCD: msg1 and msg2
  }
}


