// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h>

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
double deg = 0;
double distance = 0;
double rad = 0;
double x = 0;
double y = 0;

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
}

void loop() {
  for (int i = 0; i < 400; i++) {
    deg += .9;
    delay(15);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
    unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
    distance = uS / US_ROUNDTRIP_CM; // Convert ping time to distance in cm and print result (0 = outside set distance range)
    rad = (deg * 3.14159) / 180;
    x = distance * cos(rad);
    y = distance * sin(rad);
    Serial.print(x);
    Serial.print(",");
    Serial.println(y);
  }
  for (int i = 0; i < 400; i++) {
    deg -= .9;
    delay(15);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
    unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
    distance = uS / US_ROUNDTRIP_CM; // Convert ping time to distance in cm and print result (0 = outside set distance range)
    rad = (deg * 3.14159) / 180;
    x = distance * cos(rad);
    y = distance * sin(rad);
    Serial.print(x);
    Serial.print(",");
    Serial.println(y);
  }
}
