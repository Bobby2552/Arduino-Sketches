#include <AFMotor.h>

AF_Stepper stepper(100, 2);

void setup() {
  
}

void loop() {
  stepper.step(10, FORWARD, MICROSTEP);
  delay(1000);
}
