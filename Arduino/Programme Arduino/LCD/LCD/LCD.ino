/*#include "param.h" */
#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,4,5,6,7);  
 
int keypad_pin = A0;
int keypad_value = 0;
int keypad_value_old = 0;
 
char btn_push;
 
byte mainMenuPage = 1;
byte mainMenuPageOld = 1;
byte mainMenuTotal = 4;
 


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





void setup() {

pinMode(L1,OUTPUT);
pinMode(L2,OUTPUT);
pinMode(L3,OUTPUT);
pinMode(L4,OUTPUT);
pinMode(L5,OUTPUT);
pinMode(L6,OUTPUT);
pinMode(L7,OUTPUT);
pinMode(L8,OUTPUT);
pinMode(L9,OUTPUT);
pinMode(L10,OUTPUT);

    lcd.begin(16,2);  //Initialize a 2x16 type LCD
 
    MainMenuDisplay();
    delay(1000);
}




void loop()
{
    btn_push = ReadKeypad();
   
    MainMenuBtn();
   
    if(btn_push == 'S')//enter selected menu
    {
        WaitBtnRelease();
        switch (mainMenuPage)
        {
            case 1:
              CoeurAllume();
              break;
            case 2:
              MenuB();
              break;
            case 3:
              MenuC();
              break;
            case 4:
              MenuD();
              break;
        }
 
          MainMenuDisplay();
          WaitBtnRelease();
    }
   
 
 
    delay(10);
 
}//--------------- End of loop() loop ---------------------
void CoeurAllume()
{  
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Inside Menu A");
   
    while(ReadKeypad()!= 'L')
    {
        //Insert Task for Menu A here
       
    }
}
void MenuB()
{  
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Inside Menu B");
   
    while(ReadKeypad()!= 'L')
    {
        //Insert Task for Menu B here
       
    }
}
void MenuC()
{  
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Inside Menu C");
   
    while(ReadKeypad()!= 'L')
    {
        //Insert Task for Menu C here
       
    }
}
void MenuD()
{  
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Inside Menu D");
   
    while(ReadKeypad()!= 'L')
    {
        //Insert Task for Menu D here
       
    }
}
 
void MainMenuDisplay()
{
    lcd.clear();
    lcd.setCursor(0,0);
    switch (mainMenuPage)
    {
        case 1:
          lcd.print("1. CoeurAllume");
          break;
        case 2:
          lcd.print("2. Menu B");
          break;
        case 3:
          lcd.print("3. Menu C");
          break;
        case 4:
          lcd.print("4. Menu D");
          break;
    }
}
 
void MainMenuBtn()
{
    WaitBtnRelease();
    if(btn_push == 'U')
    {
        mainMenuPage++;
        if(mainMenuPage > mainMenuTotal)
          mainMenuPage = 1;
    }
    else if(btn_push == 'D')
    {
        mainMenuPage--;
        if(mainMenuPage == 0)
          mainMenuPage = mainMenuTotal;    
    }
   
    if(mainMenuPage != mainMenuPageOld) //only update display when page change
    {
        MainMenuDisplay();
        mainMenuPageOld = mainMenuPage;
    }
}
 
char ReadKeypad()
{
  /* Keypad button analog Value
  no button pressed 1023
  select  741
  left    503
  down    326
  up      142
  right   0
  */
  keypad_value = analogRead(keypad_pin);
 
  if(keypad_value < 100)
    return 'R';
  else if(keypad_value < 200)
    return 'U';
  else if(keypad_value < 400)
    return 'D';
  else if(keypad_value < 600)
    return 'L';
  else if(keypad_value < 800)
    return 'S';
  else
    return 'N';
 
}
 
void WaitBtnRelease()
{
    while( analogRead(keypad_pin) < 800){}
}


/*
switch () {
  case 0;
  CoeurAllume();
  break;

  case 1;
  UnsurDeux();
  break;
 
  case 2;
  UnsurTrois();
  break;
  case 3;
  Chenille();
  break;
  case 4;
  ChoisirUn();
  break;
}

*/








