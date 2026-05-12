#define PIN_A 2

volatile int compteur = 0;

void setup() {
  Serial.begin(9600);
  pinMode(PIN_A, INPUT);
  attachInterrupt(digitalPinToInterrupt(PIN_A), compter, RISING);
}

void compter() {
  compteur++;
}

void loop() {
  Serial.print("Position : ");
  Serial.println(compteur);
  delay(100);
}