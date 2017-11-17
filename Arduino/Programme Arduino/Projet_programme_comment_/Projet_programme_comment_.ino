#include <LiquidCrystal.h>


LiquidCrystal lcd(8,9,4,5,6,7);   //entrée pour l'écran LCD

unsigned long time;
 
int keypad_pin = A0; //entrée analogique pour le clavier
int keypad_value = 0;
int keypad_value_old = 0;
int n;

long int pulse;

char btn_push;
 
byte mainMenuPage = 1;
byte mainMenuPageOld = 1;
byte mainMenuTotal = 17; // nombre de Menu
 
 
byte coeur[8] = { // Caractère personalisé d'un coeur
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

float pouls;
float attente;

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
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Patientez ...");
    lcd.setCursor(1,1);
    lcd.print("Prise du pouls");
    lcd.setCursor(1,2);




  n=0;
  pulse=0;
  pouls=0;
  Serial.begin(9600); //console a 9600 baud

  time = millis();

  //préchauffage pour que les résultats soit plus juste
  while((millis()-time)<5000){
    analogRead(10); // entrée analogique A 10
  }

  time = millis();

  //on affiche au moniteur série pendant 5 secondes
  while((millis()-time)< 10000){
    if ((millis()-time)%100 == 0)
      //calcule de la moyenne du pouls partie 1
      pulse=pulse+(((1000.0*60.0)/(analogRead(10)))-100);
      n=n+1;
      //sortie sur port série pour le processing
      Serial.print(millis()-time);
      Serial.print(';');
      Serial.println(((1000.0*60.0)/(analogRead(10)))-100);
      delay (100);
   
  }
  //attribution à la variable pouls la moyenne du pouls
  pouls = pulse / n;
  attente = (60/pouls)*1000;

lcd.begin(16,2);  //Initialize a 2x16 type LCD
lcd.createChar(0, coeur);
MainMenuDisplay();
delay(1000); // pause de 1s
}




void loop()
{
    btn_push = ReadKeypad();
   
    MainMenuBtn();
   
    if(btn_push == 'S') // entrée dans le menu (Selection)
    {
        WaitBtnRelease();
        switch (mainMenuPage) // different progamme du menu
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
void CoeurAllume() //1er programme
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
digitalWrite(L2,HIGH); // LED allumé
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
digitalWrite(L1,LOW); // LED éteinte
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

void UnsurDeux() // programme 2
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
void UnsurTrois() // programme 3
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
void Chenille() // programme 4
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

void ChenilleDeux() // programme 5
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

void Battement() // programme 6
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



void CoeurBrise() // programme 7
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
void  LED1() // programme 8
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

  void  LED2() // programme 9
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
  void  LED3() // programme 10
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
void  LED4() //programme 11
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
  void  LED5() //programme  12
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
void  LED6() //programme  13
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
  void  LED7() // Programme 14
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
void  LED8() // programme 15
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
  void  LED9() // programme 16
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
void  LED10() // programme 17
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
    switch (mainMenuPage) //les different programme du menu
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
    if(btn_push == 'R') // droite
    {
        mainMenuPage++;
        if(mainMenuPage > mainMenuTotal)
          mainMenuPage = 1;
    }
    else if(btn_push == 'D') //en bas
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
