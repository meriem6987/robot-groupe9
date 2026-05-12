#include <Wire.h>

void setup() {
  Serial.begin(9600);
  Wire.begin();
  
  Serial.println("Scan I2C...");
  
  for (byte addr = 1; addr < 127; addr++) {
    Wire.beginTransmission(addr);
    byte erreur = Wire.endTransmission();
    
    if (erreur == 0) {
      Serial.print("Appareil trouvé à l'adresse 0x");
      Serial.println(addr, HEX);
    }
  }
  Serial.println("Scan terminé.");
}

void loop() {}
