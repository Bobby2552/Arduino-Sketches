#include <UltrasonicSensor.h>

UltrasonicSensor front(5, 4);
UltrasonicSensor right(7, 6);
UltrasonicSensor left(9, 8);

void setup() {
  Serial.begin(19200);
}

void loop() {
  Serial.print("Front:  ");
  Serial.print(front.toIn(front.ping(30000)));
  Serial.println(" in");
  Serial.print("Right:  ");
  Serial.print(right.toIn(right.ping(30000)));
  Serial.println(" in");
  Serial.print("Left :  ");
  Serial.print(left.toIn(left.ping(30000)));
  Serial.println(" in");
  Serial.println();
  
  delay(100);
}
