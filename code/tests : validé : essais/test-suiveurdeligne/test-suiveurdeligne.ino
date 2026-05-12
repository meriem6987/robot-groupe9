#include <MeLineFollower.h>

MeLineFollower lineFollower(2);

#include <Wire.h>

#define LINE_FOLLOWER_ADDR 0x39

void setup() {
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  Wire.requestFrom(LINE_FOLLOWER_ADDR, 1);
  
  if (Wire.available()) {
    uint8_t etat = Wire.read();
    Serial.print("Etat : ");
    Serial.println(etat);
  }
  
  delay(200);
}