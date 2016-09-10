// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h>
#include <Wire.h>

#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing one(6, 7, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing two(8, 9, MAX_DISTANCE);
NewPing three(2, 3, MAX_DISTANCE);
NewPing four(4, 5, MAX_DISTANCE);

void setup() {
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
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
  
  Wire.beginTransmission(4);
  Wire.write("step");
  Wire.endTransmission();
  
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
  
  Wire.beginTransmission(4);
  Wire.write("step");
  Wire.endTransmission();
  
  delayMicroseconds(400000);
 }
}

int cm(int uS) {
  return uS / US_ROUNDTRIP_CM; 
}
