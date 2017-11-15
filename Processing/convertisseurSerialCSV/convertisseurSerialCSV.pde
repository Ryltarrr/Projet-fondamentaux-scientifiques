//From Arduino to Processing to Txt or cvs etc.
//import
import processing.serial.*;
//declare
PrintWriter output;
Serial udSerial;
boolean passed = false;

void setup() {
  // change the number between brackets according to the used
  // COM port https://processing.org/reference/libraries/serial/Serial.html
  udSerial = new Serial(this, Serial.list()[0], 19200);
  output = createWriter ("../../traitement-des-donnees/Battements.csv");
  output.print("000;000");
}

void draw() {
  if (!passed) {
   passed = true;
  } else {
    if (udSerial.available() > 0) {
      String SenVal = udSerial.readString();
      if (SenVal != null) {
        output.print(SenVal);
      }
    }
  }    
}

void keyPressed(){
  output.flush();
  output.close();
  exit(); 
}