#include <LiquidCrystal.h>


LiquidCrystal lcd(8,9,4,5,6,7);  

unsigned long time;
 
int keypad_pin = A0;
int keypad_value = 0;
int keypad_value_old = 0;
int n;

long int pulse;

char btn_push;
 
byte mainMenuPage = 1;
byte mainMenuPageOld = 1;
byte mainMenuTotal = 17;
 
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

float pouls;
float attente = 60/pouls*1000;

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
    lcd.createChar(0, coeur);
    MainMenuDisplay();
    delay(1000);

  n=0;
  pulse=0;
  pouls=0;
  Serial.begin(9600);

  Serial.println("Veuillez patienter");

  time = millis();

  //préchauffage pour que les résultats soit plus juste
  while((millis()-time)<5000){
    analogRead(0);
  }

  time = millis();

  //on affiche au moniteur série pendant 5 secondes
  while((millis()-time)< 10000){
    if ((millis()-time)%100 == 0)
      //calcule de la moyenne du pouls partie 1
      pulse=pulse+(((1000.0*60.0)/(analogRead(0)))-100);
      n=n+1;
      //sortie sur port série pour le processing
      Serial.print(millis()-time);
      Serial.print(';');
      Serial.println(((1000.0*60.0)/(analogRead(0)))-100);
   
  }
  //attribution à la variable pouls la moyenne du pouls
 pouls = pulse / n;

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
            UnsurDeux();
            break;
            case 3:
            UnsurTrois();
            break;
            case 4:
            Chenille();
            break;
            case 5:
            ChenilleDeux();
            break;  
            case 6:
            Battement();
            break;
            
            case 7:
            CoeurBrise();
            break;
            
            case 8:
            LED1();
            break;
            
            case 9:
            LED2();
            break;
            
            case 10:
            LED3();
            break;
            
            case 11:
            LED4();
            break;
            
            case 12:
            LED5();
            break;  
            
            case 13:
            LED6();
            break;
            
            case 14:
            LED7();
            break;
            
            case 15:
            LED8();
            break;  
            
            case 16:
            LED9();
            break;
            
            case 17:
            LED10();
            break;


            

        
           
        }
 
          MainMenuDisplay();
          WaitBtnRelease();
    }
   

 
    delay(10);
 
}//--------------- End of loop() loop ---------------------
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
digitalWrite(48,HIGH);
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
digitalWrite(48,LOW);
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
delay(1000);
}

void UnsurDeux()
{  
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Votre pouls est");
    lcd.setCursor(4,1);
    lcd.print(pouls);
    lcd.setCursor(7,1);
    lcd.print("bpm");
    lcd.setCursor(10,1);
    lcd.write(byte(0));

while (pouls<250){    
digitalWrite(L1,HIGH);

digitalWrite(L3,HIGH);

digitalWrite(L5,HIGH);

digitalWrite(L7,HIGH);

digitalWrite(L9,HIGH);

delay(attente);
digitalWrite(L1,LOW);

digitalWrite(L3,LOW);

digitalWrite(L5,LOW);

digitalWrite(L7,LOW);

digitalWrite(L9,LOW);

digitalWrite(L2,HIGH);

digitalWrite(L4,HIGH);

digitalWrite(L6,HIGH);

digitalWrite(L8,HIGH);

digitalWrite(L10,HIGH);
delay(attente);

digitalWrite(L2,LOW);

digitalWrite(L4,LOW);

digitalWrite(L6,LOW);

digitalWrite(L8,LOW);

digitalWrite(L10,LOW);
   
}
  
    while(ReadKeypad()!= 'L')
    {
        //Insert Task for Menu B here
       
    }
}
void UnsurTrois()
{  
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Votre pouls est");
    lcd.setCursor(4,1);
    lcd.print(pouls);
    lcd.setCursor(7,1);
    lcd.print("bpm");
    lcd.setCursor(10,1);
    lcd.write(byte(0));

  while (pouls<250){    
digitalWrite(L3,HIGH);
digitalWrite(L8,HIGH);
delay(attente);
digitalWrite(L3,LOW);
digitalWrite(L8,LOW);

digitalWrite(L4,HIGH);
digitalWrite(L9,HIGH);
delay(attente);
digitalWrite(L4,LOW);
digitalWrite(L9,LOW);

digitalWrite(L5,HIGH);
digitalWrite(L10,HIGH);
delay(attente);
digitalWrite(L5,LOW);
digitalWrite(L10,LOW);

digitalWrite(L6,HIGH);
digitalWrite(L1,HIGH);
delay(attente);
digitalWrite(L6,LOW);
digitalWrite(L1,LOW);

digitalWrite(L7,HIGH);
digitalWrite(L2,HIGH);
delay(attente);
digitalWrite(L7,LOW);
digitalWrite(L2,LOW);



  }
   
    while(ReadKeypad()!= 'L')
    {
        //Insert Task for Menu C here
       
    }
}
void Chenille()
{  
        lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Votre pouls est");
    lcd.setCursor(4,1);
    lcd.print(pouls);
    lcd.setCursor(7,1);
    lcd.print("bpm");
    lcd.setCursor(10,1);
    lcd.write(byte(0));

  while (pouls<250){    
digitalWrite(L1,HIGH);
delay(attente);
digitalWrite(L1,LOW);
digitalWrite(L2,HIGH);
delay(attente);
digitalWrite(L2,LOW);
digitalWrite(L3,HIGH);
delay(attente);
digitalWrite(L3,LOW);
digitalWrite(L4,HIGH);
delay(attente);
digitalWrite(L4,LOW);
digitalWrite(L5,HIGH);
delay(attente);
digitalWrite(L5,LOW);
digitalWrite(L6,HIGH);
delay(attente);
digitalWrite(L6,LOW);
digitalWrite(L7,HIGH);
delay(attente);
digitalWrite(L7,LOW);
digitalWrite(L8,HIGH);
delay(attente);
digitalWrite(L8,LOW);
digitalWrite(L9,HIGH);
delay(attente);
digitalWrite(L9,LOW);
digitalWrite(L10,HIGH);
delay(attente);
digitalWrite(L10,LOW);

  }
}

void ChenilleDeux()
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
   

delay(attente);
digitalWrite(L1,LOW);
digitalWrite(L3,HIGH);
delay(attente);
digitalWrite(L2,LOW);
digitalWrite(L4,HIGH);
delay(attente);
digitalWrite(L3,LOW);
digitalWrite(L5,HIGH);
delay(attente);
digitalWrite(L4,LOW);
digitalWrite(L6,HIGH);
delay(attente);
digitalWrite(L5,LOW);
digitalWrite(L7,HIGH);
delay(attente);
digitalWrite(L6,LOW);
digitalWrite(L8,HIGH);
delay(attente);
digitalWrite(L7,LOW);
digitalWrite(L9,HIGH);
delay(attente);
digitalWrite(L8,LOW);
digitalWrite(L10,HIGH);
delay(attente);
digitalWrite(L9,LOW);
digitalWrite(L1,HIGH);
delay(attente);
digitalWrite(L10,LOW);
digitalWrite(L2,HIGH);


  }
  else
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Mettez le doigt");
    lcd.setCursor(1,1);
    lcd.print("dans la pince");
    digitalWrite(48,HIGH);
delay(2000);
    
  }
}
delay(1000);
}

void Battement()
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
digitalWrite(48,HIGH);
delay(150);
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
delay(150);
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
digitalWrite(48,LOW);
delay(attente-300);
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



  }
  else
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Mettez le doigt");
    lcd.setCursor(1,1);
    lcd.print("dans la pince");
    digitalWrite(48,HIGH);
delay(2000);
    
  }
}
delay(1000);
}



void CoeurBrise()
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
digitalWrite(L4,LOW);
digitalWrite(L5,LOW);
digitalWrite(L6,LOW);
digitalWrite(L7,LOW);
digitalWrite(L8,HIGH);
digitalWrite(L9,HIGH);
digitalWrite(L10,HIGH);

delay(attente);
digitalWrite(L1,LOW);
digitalWrite(L2,LOW);
digitalWrite(L3,HIGH);
digitalWrite(L4,HIGH);
digitalWrite(L5,HIGH);
digitalWrite(L6,HIGH);
digitalWrite(L7,HIGH);
digitalWrite(L8,HIGH);
digitalWrite(L9,LOW);
digitalWrite(L10,LOW);
delay(attente);

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
delay(1000);
}
void  LED1()
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
delay(attente);
digitalWrite(L1,LOW);
delay(attente);

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

  void  LED2()
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

   
digitalWrite(L2,HIGH);
delay(attente);
digitalWrite(L2,LOW);
delay(attente);
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
  void  LED3()
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

   
digitalWrite(L3,HIGH);
delay(attente);
digitalWrite(L3,LOW);
delay(attente);
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
void  LED4()
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

   
digitalWrite(L4,HIGH);
delay(attente);
digitalWrite(L4,LOW);
delay(attente);
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
  void  LED5()
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

   
digitalWrite(L5,HIGH);
delay(attente);
digitalWrite(L5,LOW);
delay(attente);
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
void  LED6()
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

   
digitalWrite(L6,HIGH);
delay(attente);
digitalWrite(L6,LOW);
delay(attente);

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
  void  LED7()
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

   
digitalWrite(L7,HIGH);
delay(attente);
digitalWrite(L7,LOW);
delay(attente);
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
void  LED8()
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

   
digitalWrite(L8,HIGH);
delay(attente);
digitalWrite(L8,LOW);
delay(attente);
  }
  }
}
  void  LED9()
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

   
digitalWrite(L9,HIGH);
delay(attente);
digitalWrite(L9,LOW);
delay(attente);
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
void  LED10()
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

   
digitalWrite(L10,HIGH);
delay(attente);
digitalWrite(L10,LOW);
delay(attente);
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
          lcd.print("2. UnsurDeux");
          break;
        case 3:
          lcd.print("3. UnsurTrois");
          break;
        case 4:
          lcd.print("4. Chenille");
          break;
        case 5 :
        lcd.print("5. ChenilleDeux");
         break;   
        case 6:
          lcd.print("6. Battement");
          break;  
        case 7 :
        lcd.print("7. CoeurBrise");
         break;
          case 8:
          lcd.print("8.LED1");
          break;
        case 9:
          lcd.print("9. LED2");
          break;
        case 10:
          lcd.print("10. LED3");
          break;
        case 11:
          lcd.print("11. LED4");
          break;
        case 12 :
        lcd.print("12. LED5");
         break;   
        case 13:
          lcd.print("13. LED6");
          break;  
        case 14:
        lcd.print("14. LED7");
         break;

        case 15:
          lcd.print("15. LED8");
         break;   
        case 16:
          lcd.print("16. LED9");
          break;  
        case 17 :
        lcd.print("17. LED10");
         break;
         
    }
}
 
void MainMenuBtn()
{
    WaitBtnRelease();
    if(btn_push == 'R')
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
  else if(keypad_value < 500)
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
