#include <UltrasonicSensor.h>

UltrasonicSensor front(4, 5);
UltrasonicSensor right(6, 7);
UltrasonicSensor left (8, 9);

void setup() {
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT); 
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  delay(1000);
}

void loop() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  delay(1000000);
}
