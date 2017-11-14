unsigned long time;


void setup() {

  Serial.begin(9600);

  Serial.println("Veuillez patienter");

  time = millis();

  // un petit réchauffement du convertisseur
  // analogique-numérique semble améliorer les résultats
  while((millis()-time)<1000){
    analogRead(0);
  }

  time = millis();

  // on affiche au moniteur série pendant 5 secondes
  while((millis()-time)< 5000){
    Serial.println(((1000.0*60.0)/(analogRead(0)))-100);
  }

}


void loop() {


}
