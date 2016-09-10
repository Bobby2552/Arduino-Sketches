#include <UltrasonicSensor.h>
#include <AFMotor.h>

int targetDist = 24;

UltrasonicSensor sensor(51, 50);
AF_DCMotor drive(3);

void setup() {
  drive.setSpeed(255);
}

void loop() {
  
  long inches = sensor.toIn(sensor.ping());
  
  if (inches > targetDist - 2 && inches < targetDist + 2) {
    
    drive.run(RELEASE);
    Serial.print("RELEASE");
    
  }
  
  else if (inches < targetDist - 2) {

    if ( inches > targetDist - 10) {
      drive.setSpeed(175);
    }
    
    else {
      drive.setSpeed(255);
    }
    
    drive.run(BACKWARD);
    Serial.print("BACKWARD");
    
  }
  
  else if (inches > targetDist + 2) {
    
    if ( inches < targetDist + 10) {
      drive.setSpeed(175);
    }
    
    else {
      drive.setSpeed(255);
    }
    
    drive.run(FORWARD);
    Serial.print("FORWARD");
    
  }
  
  Serial.println();
  delay(100);
}
