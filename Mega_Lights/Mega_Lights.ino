const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to

int sensorValue = 0;        // value read from the pot
int lowPin = 1;

void setup() {
  // initialize serial communications at 9600 bps:
  for (int i = lowPin + 1; i < lowPin + 8; i++) {
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600); 
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin); 
  // change the analog out value:     
//  sensorValue += 1;
  sensorValue *= 15;
  if (sensorValue < 20 && sensorValue > 0){
    digitalWrite(lowPin + 1, HIGH);  
  }else if (sensorValue > 20 && sensorValue < 40){
  digitalWrite(lowPin + 2, HIGH);
  }else if (sensorValue > 40 && sensorValue < 60){
  digitalWrite(lowPin + 3, HIGH);
  }else if (sensorValue > 60 && sensorValue < 80){
  digitalWrite(lowPin + 4, HIGH);
  }else if (sensorValue > 80 && sensorValue < 100){
  digitalWrite(lowPin + 5, HIGH);
  }else if (sensorValue > 100 && sensorValue < 120){
  digitalWrite(lowPin + 6, HIGH); 
  }else if (sensorValue > 120 && sensorValue < 140){
  digitalWrite(lowPin + 7, HIGH);
  }

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
    delay(5);  
  for (int i = 1; i < 8; i++) {
    digitalWrite(i, LOW);
  }
                   
}
