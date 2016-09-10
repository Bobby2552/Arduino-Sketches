#include <AFMotor.h>

AF_DCMotor drive(1);
int targetDist = 24;

void setup() {
  drive.setSpeed(255);
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  Serial.begin(9600);
}

void loop() {
//  long duration, inches;
//  pinMode(A4, OUTPUT);
//  digitalWrite(A4, LOW);
//  delayMicroseconds(2);
//  digitalWrite(A4, HIGH);
//  delayMicroseconds(5);
//  digitalWrite(A4, LOW);
//  
//  pinMode (A2, INPUT);//attach pin 4 to Echo
//  duration = pulseIn(A2, HIGH);
//  
//   // convert the time into a distance
//  inches = microsecondsToInches(duration);
//  
//  if (inches > targetDist - 2 && inches < targetDist + 2) {
//    //digitalWrite(0, LOW);
//    //digitalWrite(1, LOW);
//    drive.run(RELEASE);
//    Serial.print("RELEASE");
//  }
//  
//  else if (inches < targetDist - 2) {
//    //digitalWrite(0, HIGH);
//    //digitalWrite(1, LOW);
//    drive.run(BACKWARD);
//    Serial.print("BACKWARD");
//  }
//  
//  else if (inches > targetDist + 2) {
//    //digitalWrite(0, LOW);
//    //digitalWrite(1, HIGH);
//    drive.run(FORWARD);
//    Serial.print("FORWARD");
//  }
//  
//  Serial.println();
//  delay(50);

  drive.run(FORWARD);
  delay(1000);
  drive.run(BACKWARD);
  delay(1000);
  drive.run(RELEASE);
  delay(10000000);

}

long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
