unsigned long time;
long int pulse;
int n;
int pouls;


void setup() {
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


void loop() {


}
