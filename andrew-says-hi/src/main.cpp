#include "Arduino.h"

void setup() {
  pinMode(3, OUTPUT); 
}

void loop() {
  analogWrite(3, 255 * sin(millis() * 0.25));
  delay(50);
}
