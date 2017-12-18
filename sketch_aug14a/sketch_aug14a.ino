
void setup() {
  for (int i = 46; i < 54; i++) {
    pinMode(i, OUTPUT); 
  }
  Serial.begin(9600);
}

void loop() {
  for (int i = 46; i < 54; i++) {
    digitalWrite(i, HIGH);
    Serial.println("Enabling pin " + String(i));
   delay(500);
   
  digitalWrite(i, LOW); 
  }

}
