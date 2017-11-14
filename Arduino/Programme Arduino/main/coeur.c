/*
#include <LiquidCrystal.h>
#include "param.h" 

LiquidCrystal lcd(8,9,4,5,6,7);  
 
int keypad_pin = A0;
int keypad_value = 0;
int keypad_value_old = 0;
 
char btn_push;
 
byte mainMenuPage = 1;
byte mainMenuPageOld = 1;
byte mainMenuTotal = 4;
 
byte coeur[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

const int L1 = 30;
const int L2 = 31;
const int L3 = 32;
const int L4 = 33;
const int L5 = 34;
const int L6 = 35;
const int L7 = 36;
const int L8 = 37;
const int L9 = 38;
const int L10 = 39;

const float pouls = 249;

float attente = 60/pouls*1000;


void CoeurAllume()
{ 
  while(pouls!=1) { 
  if (pouls<250){ 
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Votre pouls est");
    lcd.setCursor(4,1);
    lcd.print(pouls);
    lcd.setCursor(7,1);
    lcd.print("bpm");
    lcd.setCursor(10,1);
    lcd.write(byte(0));
   
digitalWrite(L1,HIGH);
digitalWrite(L2,HIGH);
digitalWrite(L3,HIGH);
digitalWrite(L4,HIGH);
digitalWrite(L5,HIGH);
digitalWrite(L6,HIGH);
digitalWrite(L7,HIGH);
digitalWrite(L8,HIGH);
digitalWrite(L9,HIGH);
digitalWrite(L10,HIGH);
delay(attente/2);
digitalWrite(L1,LOW);
digitalWrite(L2,LOW);
digitalWrite(L3,LOW);
digitalWrite(L4,LOW);
digitalWrite(L5,LOW);
digitalWrite(L6,LOW);
digitalWrite(L7,LOW);
digitalWrite(L8,LOW);
digitalWrite(L9,LOW);
digitalWrite(L10,LOW);
delay(attente/2);
  }
  else
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Mettez le doigt");
    lcd.setCursor(1,1);
    lcd.print("dans la pince");
delay(2000);
    
  }
}
}
    

 */
  

