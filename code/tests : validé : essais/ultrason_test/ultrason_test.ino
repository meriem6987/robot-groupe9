void setup() {
  Serial.begin(9600);

}

void loop() {
 // Envoyer une impulsion ultrason
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
  delayMicroseconds(2);
  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);

  // Lire le retour
  pinMode(2, INPUT);
  long duree = pulseIn(2, HIGH);
  
  // Convertir en cm
  long distance = duree / 58;
  
  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(500);

}
