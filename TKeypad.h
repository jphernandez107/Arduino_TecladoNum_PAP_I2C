#ifndef TKeypad_h
#define TKeypad_h

#include "LcdDisplay.h"
#include "Arduino.h"
#include "Keypad.h"
#include "ctype.h"
#define INPUT_CHAR_NUMBER 3

class TKeypad{  
  private:
      char teclas[4][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}, {'*','0','#'}};
      byte pinFilas[4] = {8, 9, 10, 11}; //connect to the row pinouts of the keypad
      byte pinColumnas[3] = {5, 6, 7}; // connect to the column pinouts of the keypad
  
      LcdDisplay *mLcdDisplay;
      char mLastChar;
      const char CHAR_OK = '#'; 
      const char CHAR_CLEAR = '*';
      Keypad mKeypad;
      bool mUseSerial = false;
      //char getKeyFromSerial();
  public:
    TKeypad(LcdDisplay *lcd, boolean useSerial);
    String getInput();
};

#endif
