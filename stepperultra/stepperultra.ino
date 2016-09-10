#include <Stepper.h>

#include <AFMotor.h>
 
 
AF_Stepper motor(200, 1);
int time = 10.5 * 45;
 
 
void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Stepper test!");
 
  motor.setSpeed(10);  // 10 rpm   
 
  motor.release();
  
}
 
void loop() {
 for (int i = 0; i < 100; i++) {
   while(analogRead(A0) < 950) { }
 motor.step(1, FORWARD, INTERLEAVE);
 }
 
for (int i = 0; i < 100; i++) {
  while(analogRead(A0) < 950) { }
 motor.step(1, BACKWARD, INTERLEAVE);
 } 
}
