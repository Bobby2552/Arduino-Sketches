#include <AFMotor.h>

AF_Stepper stepper(20, 2);

void setup() {
  stepper.setSpeed(255); 
}

void loop() {
  stepper.step(1, FORWARD, DOUBLE);
  delay(50); 
}
