
#include "LcdDisplay.h"

LcdDisplay::LcdDisplay(bool useSerial) : mLcd(TYPE,COLS,ROWS) {
  mUseSerial = useSerial;
}

void LcdDisplay::init(){
  mLcd.begin();  
  }
void LcdDisplay::printMsg1(String msg1) {  
    // JJ
    // put code to print two lines in the LCD: msg1 and msg2  
  mLcd.setCursor(0,0);
  mLcd.print(msg1);
}

void LcdDisplay::printMsg2(String msg2){

  mLcd.setCursor(0,1);
  mLcd.print(msg2);
}


