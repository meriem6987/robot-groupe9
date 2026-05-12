#include <Adafruit_NeoPixel.h>

#define PIN 6
#define NUMPIXELS 30

Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
}

void loop() {
  // Rouge
  allumer(255, 0, 0);
  delay(1000);

  // Vert
  allumer(0, 255, 0);
  delay(1000);

  // Bleu
  allumer(0, 0, 255);
  delay(1000);

  // Jaune
  allumer(255, 255, 0);
  delay(1000);

  // Violet
  allumer(128, 0, 128);
  delay(1000);

  // Cyan
  allumer(0, 255, 255);
  delay(1000);

  // Blanc
  allumer(255, 255, 255);
  delay(1000);

  // Éteint
  allumer(0, 0, 0);
  delay(1000);
}

void allumer(int r, int g, int b) {
  for (int i = 0; i < NUMPIXELS; i++) {
    strip.setPixelColor(i, strip.Color(r, g, b));
  }
  strip.show();
}