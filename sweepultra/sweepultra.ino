#include <Servo.h>
#include <NewPing.h>

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 150 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

double phi = 0;    // variable to store the servo position
double theta = 0;
double r = 0;
double x = 0;
double y = 0;
double z = 0;
int del = 10;
double uS = 0;

void setup()
{
    myservo.attach(10);  // attaches the servo on pin 9 to the servo object
    myservo.write(45);
    Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
    Serial.println(US_ROUNDTRIP_CM);
    pinMode(2, OUTPUT);
}

void loop()
{
    for(theta = 0; theta < 360; theta += .9) {

        for(phi = 0; phi <= 90; phi += 1) calc();
        step();
        
        theta += .9;

        for(phi = 90; phi>=0; phi-=1) calc();
        step();
    }
    for(theta = 360; theta > 0; theta -= .9) {
        for(phi = 0; phi <= 90; phi += 1) calc();
        step();
        
        theta -= .9;
        
        for(phi = 90; phi>=0; phi-=1) calc();
        step();
    }
}

double con(double deg) {
    return (deg * 3.14159) / 180;
}
void calc() {
    myservo.write(phi);              // tell servo to go to position in variable 'pos'
    uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
    delayMicroseconds(8550 - uS);
    r = uS / US_ROUNDTRIP_CM;
    if(r == 0) {
        return;
    }
    x = r * sin(con(theta)) * cos(con(phi));
    y = r * sin(con(theta)) * sin(con(phi));
    z = r * cos(con(theta));
    Serial.print(x, 5);
    Serial.print(",");
    Serial.print(y, 5);
    Serial.print(",");
    Serial.println(z, 5);
}
void step() {
    digitalWrite(2, HIGH);
    delayMicroseconds(100);
    digitalWrite(2, LOW);
}
