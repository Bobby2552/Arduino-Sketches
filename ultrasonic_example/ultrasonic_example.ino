#include <UltrasonicSensor.h>

//I've connected pins 11 and 12 to the echo and trig on my sensor, respectivly.
UltrasonicSensor sensor(11, 12);

void setup() {
  Serial.begin(9600); 
}

void loop() {
  //30000 is the timeout for the ping. If the recieving 'eye' doesn't 'hear' the ping within this time (microseconds), ping will return 0.
  //30000 is a good value to use on most sensors, but this depends on your sensor, and how long you want to wait for a response.
  //ping method without a timeout is availible (long ping()), but I don't recommend using it.
  long duration = sensor.ping(30000);
  
  //changing the time the ping took to a number of inches.
  long inches = sensor.toIn(duration);
  
  //same thing as toIn, but with centimeters instead of inches.
  long centis = sensor.toCm(duration);
  
  Serial.print(duration);
  Serial.print("\t");
  Serial.print(inches);
  Serial.print(" in.");
  Serial.print("\t");
  Serial.print(centis);
  Serial.print(" cm");
  Serial.println();
}
