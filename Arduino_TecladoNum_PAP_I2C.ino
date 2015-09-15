#include <LiquidCrystal_I2C.h>
#include "Keypad.h"
#include "OpticalSensor.h"
#include "Motor.h"
#include "LcdDisplay.h"
#include "TKeypad.h"
#include <Wire.h>

#define PIN_SENSOR1 0
#define PIN_MOTOR_STEPS 2
#define PIN_MOTOR_RESET 4
#define PIN_MOTOR_DIR 3
#define MOTOR_MAX_STEPS_PER_SECOND 200
#define DEBUG_FLAG 1

OpticalSensor sensor1(PIN_SENSOR1);
Motor motor1(&sensor1, PIN_MOTOR_STEPS, PIN_MOTOR_RESET, PIN_MOTOR_DIR, MOTOR_MAX_STEPS_PER_SECOND);
LcdDisplay *lcdDisplay = new LcdDisplay(true);
TKeypad tKeypad(lcdDisplay, true);


void setup() {
// debug
Serial.begin(9600);
}

void loop() {

   String input = tKeypad.getInput();
   // move motor:
   int inputAsInt = input.toInt();
   motor1.moveTo(inputAsInt, 100);

}
//
//LiquidCrystal_I2C lcd(0x27,16,2);
//
////LcdDisplay LcdDisplay(&lcd);
//
//// keypad type definition
//const byte filas = 4; //four rows
//const byte columnas = 3; //three columns
//char teclas[filas][columnas] =
// {{'1','2','3'},
//  {'4','5','6'},
//  {'7','8','9'},
//  {'*','0','#'}};
// 
//byte pinFilas[filas] = {8, 9, 10, 11}; //connect to the row pinouts of the keypad
//byte pinColumnas[columnas] = {5, 6, 7}; // connect to the column pinouts of the keypad
// 
// 
//Keypad keypad = Keypad( makeKeymap(teclas), pinFilas, pinColumnas, filas, columnas );
//
//char ingreso[3]={'0','0','0'};
//int ingresoNum[3]={0,0,0};
//int z=0;
//
//char tecla;
//int numero;
//String string;
//int numeror;
//int dig = 3;
//
////---------------------------------------------------------------//
//#define VELOCIDADX 6500 
//#define VELOCIDADY 3000
//
//int stepsX = 2;
//int direccionX = 3;
//int reset = 4;
//int pasosX;
//
//int pasosXMax = 400;
//int pasoActual= 0;
//int pasoAnterior ;
//
//// the setup routine runs once when you press reset:
//void setup() {                
//  // initialize the digital pin as an output.
//  lcd.begin();
//  
//  pinMode(stepsX, OUTPUT); 
//  pinMode(direccionX, OUTPUT); 
//  pinMode(reset, OUTPUT);
//
//  lcd.setCursor(0,0);
//  lcd.print("SISTEMA AUTOMATI");
//  lcd.setCursor(0,1);
//  lcd.print("CO DE CORTES");
//  lcd.cursor();
//  lcd.blink();
//  
//}
//void checkIngreso(){
//  for(int i=0;i<dig;i++){
//    string += ingresoNum[i];
//    }
//    numeror = string.toInt();
//    int rec, rec2;
//
//    rec2 = numeror/2;
//    rec = rec2 - pasoActual;
//    if(rec > 0){
//      if(rec2 <= pasosXMax){
//        pasoActual = rec2;
//        pasosX = abs(rec);
//        lcd.clear();
//        lcd.setCursor(0,1);
//        lcd.print("Pasos: ");
//        lcd.print(rec);
//        lcd.setCursor(0,0);
//        lcd.print("Dist: ");
//        lcd.print(numeror);
//        lcd.print("cm");
//        
//        
//        digitalWrite(reset, LOW);    //Mientras reset este en LOW el motor permanecerá apagado y no sufrirá. El chip apagará todos los puertos y no leerá comandos.
//        delay(100);
//        digitalWrite(reset, HIGH);   //Cuando reset se encuentre en HIGH el motor arrancará y leerá los comandos enviados.
//        digitalWrite(direccionX, HIGH);
//    
//        for (int i = 0; i<=pasosX; i++)       //Equivale al numero de vueltas (200 es 360º grados) o micropasos
//        {          
//          digitalWrite(stepsX, HIGH);
//          digitalWrite(stepsX, LOW);
//          delayMicroseconds(VELOCIDADX);     // Regula la velocidad, cuanto mas bajo mas velocidad.
//      
//        }
//        rec = 0;
//        }
//    }
//   
//    if(rec < 0){
//      if(rec2 >= 0){
//        pasoActual = rec2;
//        pasosX = abs(rec);
//        lcd.clear();
//        lcd.setCursor(0,1);
//        lcd.print("Pasos: ");
//        lcd.print(rec);
//        lcd.setCursor(0,0);
//        lcd.print("Dist: ");
//        lcd.print(numeror);
//        lcd.print("cm");
//        
//        
//        digitalWrite(reset, LOW);   //Mientras reset este en LOW el motor permanecerá apagado y no sufrirá. El chip apagará todos los puertos y no leerá comandos.
//        delay(100);
//        digitalWrite(reset, HIGH);   //Cuando reset se encuentre en HIGH el motor arrancará y leerá los comandos enviados.
//        digitalWrite(direccionX, LOW);
//      
//        for (int i = 0; i<=pasosX; i++)       //Equivale al numero de vueltas (200 es 360º grados) o micropasos
//        {      
//          digitalWrite(stepsX, LOW);   // LOW to HIGH hace que el motor avance ya que da la orden
//          digitalWrite(stepsX, HIGH);    // al A4988 de avanzar una vez por cada pulso de energia.
//          delayMicroseconds(VELOCIDADX);         // Regula la velocidad, cuanto mas bajo mas velocidad.
//        }
//        rec = 0;    
//      }
//    }
//    pasoAnterior = pasoActual;
//  
//
//      digitalWrite(reset, HIGH);
//      delay(100);    
//  }
//
//void readKeypad()
//{
//  tecla = keypad.getKey();
//  if (tecla != NO_KEY)
//  {
//    numero = tecla - 48;
//    ingresoNum[z]=numero;
//    
//    /*lcd.clear();
//    lcd.print("Dist: ");
//    lcd.print(numero);
//    lcd.print("cm");*/
//    z++;
//    if(z == dig){
//      z=0;
//      checkIngreso();
//      string = "";
//      }
//     else if(z < dig){
//      
//      //lcd.clear();
//      lcd.setCursor(0,0);
//      lcd.print("Dist: ");
//      lcd.setCursor(z+5,0);
//      lcd.print(tecla);
//      lcd.print("cm       ");
//      lcd.setCursor(0,1);
//      lcd.print("                ");
//      }
//    switch(tecla)
//    {
//    case '*':
//      z=0;
//      lcd.clear();
//      lcd.print("Intente de nuevo");
//      break;
//    case '#':
//      z=0;
//      delay(100);
//      checkIngreso();
//      string = "";
//      break;
//    }
//  }
//}
//
//// the loop routine runs over and over again forever:
//void loop() {
//    readKeypad();    
//}
//
//
//

