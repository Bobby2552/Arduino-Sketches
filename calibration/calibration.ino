void setup() {
  Serial.begin(9600); 
}

void loop() {
  long duration, inches;
  pinMode(A0, OUTPUT);
  digitalWrite(A0, LOW);
  delayMicroseconds(2);
  digitalWrite(A0, HIGH);
  delayMicroseconds(5);
  digitalWrite(A0, LOW);
  
  pinMode (A1, INPUT);//attach pin 4 to Echo
  duration = pulseIn(A1, HIGH);
  
   // convert the time into a distance
  inches = microsecondsToInches(duration);
  
  Serial.println(distance);
  delay(500);
}
