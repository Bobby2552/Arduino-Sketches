// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h>

#define TRIGGER_PIN  9  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     8  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
  pinMode(2, OUTPUT);
}

void loop() {
  delayMicroseconds(200);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  int cm = uS / US_ROUNDTRIP_CM;
  if ((cm >= 30) && (cm <= 60)) {
    digitalWrite(8, HIGH);
    
    for (int i = 0; i < 5; i++) {
      delayMicroseconds(200);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
      unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
      int cm = uS / US_ROUNDTRIP_CM;
      if ((cm <= 30) && (cm >= 60)) {
        break;
      }
    }
    delay(500);
  }
  
  else digitalWrite(8, LOW);
  Serial.print(cm);
  Serial.print(" cm\n");
}
