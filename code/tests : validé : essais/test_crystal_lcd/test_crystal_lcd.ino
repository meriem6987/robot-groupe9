#include <Wire.h>
#include <rgb_lcd.h>

rgb_lcd lcd;

void setup() {
  lcd.begin(16, 2);
  lcd.setRGB(255, 255, 255);  // backlight blanc
  
  lcd.setCursor(0, 0);
  lcd.print("Distance:");
  lcd.setCursor(0, 1);
  lcd.print("-- cm");
}

void loop() {
}