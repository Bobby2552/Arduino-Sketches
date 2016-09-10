#include <AFMotor.h>

AF_DCMotor drive(1);
AF_DCMotor steer(2);
int avoidDist = 18;

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
  duration = pulseIn(A1, HIGH, 30000);
  
  Serial.println(duration);
  
   // convert the time into a distance
  inches = microsecondsToInches(duration);
  
  if (inches < avoidDist) {
    avoid();
  }
  else {
    drive.run(FORWARD); 
  }
  
  delay(50);
}

long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
}

void avoid() {
  drive.run(BACKWARD);
  steer.run(BACKWARD);
  delay(1500);
  drive.run(FORWARD);
  steer.run(FORWARD);
  delay(500);
  steer.run(RELEASE);
}
