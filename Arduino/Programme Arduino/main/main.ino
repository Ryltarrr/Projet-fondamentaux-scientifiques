#include <LiquidCrystal.h> 


LiquidCrystal lcd(8,9,4,5,6,7); //entrée pour l'écran LCD
 
int keypad_pin = A0; //entrée analogique pour le clavier
int keypad_value = 0;
int keypad_value_old = 0;
 
char btn_push;
 
byte mainMenuPage = 1;
byte mainMenuPageOld = 1;
byte mainMenuTotal = 17; // nombre de Menu
 
byte coeur[8] = {  // Caractère personalisé d'un coeur
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

const int L1 = 30;   //le port 30 de la carte arduino est desormais L1
const int L2 = 31;   //le port 31 de la carte arduino est desormais L2
const int L3 = 32;   //le port 32 de la carte arduino est desormais L3 
const int L4 = 33;   //le port 33 de la carte arduino est desormais L4 
const int L5 = 34;   //le port 34 de la carte arduino est desormais L5 
const int L6 = 35;   //le port 35 de la carte arduino est desormais L6 
const int L7 = 36;   //le port 36 de la carte arduino est desormais L7 
const int L8 = 37;   //le port 37 de la carte arduino est desormais L8 
const int L9 = 38;   //le port 38 de la carte arduino est desormais L9 
const int L10 = 39;  //le port 39 de la carte arduino est desormais L10 

const float pouls = 60;  //le pouls est égale a 60

float attente = 60/pouls*1000; //relation du pouls

void setup() {

pinMode(L1,OUTPUT);   //L1 est une sortie
pinMode(L2,OUTPUT);   //L2 est une sortie
pinMode(L3,OUTPUT);   //L3 est une sortie
pinMode(L4,OUTPUT);   //L4 est une sortie
pinMode(L5,OUTPUT);   //L5 est une sortie
pinMode(L6,OUTPUT);   //L6 est une sortie
pinMode(L7,OUTPUT);   //L7 est une sortie
pinMode(L8,OUTPUT);   //L8 est une sortie
pinMode(L9,OUTPUT);   //L9 est une sortie
pinMode(L10,OUTPUT);  //L10 est une sortie

    lcd.begin(16,2);  //LCD est composé de 2 lignes de 16 caractères
    lcd.createChar(0, coeur); //Affichage du coeur dans LCD
    MainMenuDisplay();
    delay(1000);//pause de 1s

}




void loop()
{
    btn_push = ReadKeypad();
   
    MainMenuBtn();
   
    if(btn_push == 'S')//sélection menu
    {
        WaitBtnRelease();
        switch (mainMenuPage) //différent menu
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
 
}
void CoeurAllume() // Premier menu pour le coeur allumé
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
   
digitalWrite(L1,HIGH);  //Led allumé
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
digitalWrite(L1,LOW); //Led éteinte
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

void UnsurDeux()  //deuxieme  menu pour les Led allumé UnsurDeux
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
  

}
void UnsurTrois() //troisieme menu avec Led UN sur TROIS
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
   

       
    
}
void Chenille() //4eme menu avec Led chenille
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

void ChenilleDeux() //5eme menu avec Led Deux chenille
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

void Battement() // 6eme Menu avec Led en forme de battement
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


}



void CoeurBrise() // 7eme menu avec led en forme coeur brisé
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
}
void  LED1() //8eme Menu avec la led 1
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

  void  LED2() //9eme Menu avec la led 2
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
  void  LED3() //10eme Menu avec la led 3
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
void  LED4()  //11 eme Menu avec la led 4
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
  void  LED5() // 12eme Menu avec la led 5
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
void  LED6() //13eme Menu avec la led 6
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
  void  LED7() //14eme Menu avec la led 7
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
void  LED8() //15eme Menu avec la led 8
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
  void  LED9() //16eme Menu avec la led 9
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
void  LED10() //17eme Menu avec la led 10
{  while(pouls!=1) { 
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
    return 'R';  //  droite
  else if(keypad_value < 200)
    return 'U'; // vers le haut
  else if(keypad_value < 500)
    return 'D'; //vers le bas
  else if(keypad_value < 600)
    return 'L'; // gauche
  else if(keypad_value < 800)
    return 'S'; // selecte
  else
    return 'N'; // return non
 
}
 
void WaitBtnRelease()
{
    while( analogRead(keypad_pin) < 800){}
}
