#include <Arduino.h>
#include <Wire.h>

#define peri_addr 9  

int analogPin = A1;
int valMap = 0;

void setup() {
  // Debute la communication I2C comme un Controleur
  Wire.begin(); 
}
void loop() {

  delay(50);

  // Mapper la  val entre 1-255 car codé sur 1 octet
  valMap = map(analogRead(analogPin), 0, 1023, 255, 0);

  // Envoie de la vitesse au péripherique
  Wire.beginTransmission(peri_addr); // transmettre au peripherique d'adresse #9
  Wire.write(valMap);              // envoie de la valeur du mapping
  Wire.endTransmission();    // Arret d'envoie

}