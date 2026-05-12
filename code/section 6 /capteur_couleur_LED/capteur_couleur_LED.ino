#include <Wire.h>
#include <Adafruit_TCS34725.h>
#include <Adafruit_NeoPixel.h>

#define PIN 6
#define NUMPIXELS 30

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.show();
  tcs.begin();
}

void loop() {
  uint16_t r, g, b, c;
  tcs.getRawData(&r, &g, &b, &c);

  Serial.print("R:"); Serial.print(r);
  Serial.print(" G:"); Serial.print(g);
  Serial.print(" B:"); Serial.println(b);

  uint16_t seuil = 50;

  if (r > g + seuil && r > b + seuil) {
    allumer(255, 0, 0);
    Serial.println("→ ROUGE");

  } else if (g > r + seuil && g > b + seuil) {
    allumer(0, 255, 0);
    Serial.println("→ VERT");

  } else if (b > r + seuil && b > g + seuil) {
    allumer(0, 0, 255);
    Serial.println("→ BLEU");

  } else {
    allumer(0, 0, 0);
    Serial.println("→ INDÉTERMINÉ");
  }

  delay(200);
}

void allumer(int r, int g, int b) {
  for (int i = 0; i < NUMPIXELS; i++) {
    strip.setPixelColor(i, strip.Color(r, g, b));
  }
  strip.show();
}