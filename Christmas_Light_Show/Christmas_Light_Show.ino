const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to

int sensorValue = 0;        // value read from the pot

void setup() {
  // initialize serial communications at 9600 bps:
  for (int i = 1; i < 8; i++) {
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600); 
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin); 
  // change the analog out value:     
//  sensorValue += 1;
  sensorValue *= 3;
  if (sensorValue < 20 && sensorValue > 0){
  digitalWrite(1, LOW);  
  }else if (sensorValue > 20 && sensorValue < 40){
  digitalWrite(2, LOW);
  }else if (sensorValue > 40 && sensorValue < 60){
  digitalWrite(3, LOW);
  }else if (sensorValue > 60 && sensorValue < 80){
  digitalWrite(4, LOW);
  }else if (sensorValue > 80 && sensorValue < 100){
  digitalWrite(5, LOW);
  }else if (sensorValue > 100 && sensorValue < 120){
  digitalWrite(6, LOW); 
  }else if (sensorValue > 120 && sensorValue < 140){
  digitalWrite(7, LOW);
  }

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
    delay(20);  
  for (int i = 1; i < 8; i++) {
    digitalWrite(i, HIGH);
  }
                   
}
