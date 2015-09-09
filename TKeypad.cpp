#include "LcdDisplay.cpp"
#include "Keypad.h"

#define INPUT_CHAR_NUMBER 3

class TKeypad{  
  private:
    char mLastChar;
    const char mEndChar = '#';
    LcdDisplay mLcdDisplay;
  
    char teclas[4][3] =
 {{'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}};
  byte pinFilas[4] = {8, 9, 10, 11}; //connect to the row pinouts of the keypad
  byte pinColumnas[3] = {5, 6, 7}; // connect to the column pinouts of the keypad
    Keypad mKeyPad;
  public:
    TKeypad(LcdDisplay);
    String getInput();
};
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

