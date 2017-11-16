unsigned long time;
int n,i;


void setup() {
  n=10000;
  Serial.begin(9600);

  Serial.println("Veuillez patienter");

  time = millis();

  // un petit réchauffement du convertisseur
  // analogique-numérique semble améliorer les résultats
  while((millis()-time)<1){
    analogRead(0);
  }

  time = millis();


  // on affiche au moniteur série pendant 5 secondes
  for (i=0;i<n;i++){
    Serial.println(((1000.0*60.0)/(analogRead(0)))-100);
    delay(1);
  }

}


void loop() {


}
