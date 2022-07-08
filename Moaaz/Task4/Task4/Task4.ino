#include "LiquidCrystal.h"

String key = "9110";

int Digit_1 = 0;
int Digit_2 = 0;
int Digit_3 = 0;
int Digit_4 = 0;
LiquidCrystal lcd( 8,  9,  4,  5,  6,  7);

void setup() {
  pinMode(out,OUTPUT);
  
 lcd.begin(16, 2);
 
 lcd.setCursor(0,0);
 lcd.print("Find Key");
 lcd.setCursor(0,1);
 lcd.print("Current = ");
 
 digitalWrite(out,LOW);
}
void loop() {
 int x;
 x = analogRead (0);
 
 lcd.setCursor(10,1);
 
 if (x < 60) {
    Digit_1 + = 1;
   lcd.print (String(Digit_1) +String(Digit_2)+String(Digit_3)+String(Digit_4) );
 }
 else if (x < 200) {
      Digit_2 + = 1;
   lcd.print (String(Digit_1) +String(Digit_2)+String(Digit_3)+String(Digit_4) );
 }
 else if (x < 400){
      Digit_3 + = 1;
   lcd.print (String(Digit_1) +String(Digit_2)+String(Digit_3)+String(Digit_4) );
 }
 else if (x < 600){
      Digit_4 + = 1;
   lcd.print (String(Digit_1) +String(Digit_2)+String(Digit_3)+String(Digit_4) );
 }
 else if (x < 800){
      ///Correct
      if (String(Digit_1) +String(Digit_2)+String(Digit_3)+String(Digit_4) == key) {
        
        digitalWrite(out,HIGH);
        
        }else {
          ///Reset
          int Digit_1 = 0;
          int Digit_2 = 0;
          int Digit_3 = 0;
          int Digit_4 = 0;
          }
        
  
 }
 
} 
