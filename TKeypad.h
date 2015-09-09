#include "LcdDisplay.h"
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
