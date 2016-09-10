#include <Wire.h>
#include <Stepper.h>
#include <NewPing.h>

const int stepsPerRevolution = 200;

Stepper myStepper(stepsPerRevolution, 2,3,4,5);

#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing one(11, 10, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing two(12, 13, MAX_DISTANCE);
NewPing three(6, 7, MAX_DISTANCE);
NewPing four(8, 9, MAX_DISTANCE);

int steps = 0;

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  for (int i = 0; i < 50; i++) {
  int first = cm(one.ping());
  int second = cm(two.ping());
  int third = cm(three.ping());
  int fourth = cm(four.ping());
  
  Serial.print(first);
  Serial.print(",");
  Serial.print(second);
  Serial.print(",");
  Serial.print(third);
  Serial.print(",");
  Serial.print(fourth);
  Serial.print("\n");
  
  myStepper.step(1);
  
  delayMicroseconds(400000);
 }
 for (int i = 0; i < 50; i++) {
  int first = cm(one.ping());
  int second = cm(two.ping());
  int third = cm(three.ping());
  int fourth = cm(four.ping());
  
  Serial.print(first);
  Serial.print(",");
  Serial.print(second);
  Serial.print(",");
  Serial.print(third);
  Serial.print(",");
  Serial.print(fourth);
  Serial.print("\n");
  
  myStepper.step(-1);
  
  delayMicroseconds(400000);
}
}

int cm(int uS) {
  return uS / US_ROUNDTRIP_CM; 
}
