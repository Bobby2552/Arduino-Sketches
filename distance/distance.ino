#include <AFMotor.h>

AF_DCMotor drive(1);
AF_DCMotor steer(2);

void setup() {
  drive.setSpeed(255);
  steer.setSpeed(255); 
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
   
   Serial.println(inches);
   
   delay(50);

}

long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
}
