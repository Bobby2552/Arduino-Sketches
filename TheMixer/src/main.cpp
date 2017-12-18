#include "Arduino.h"

String data;

void setup() {
	Serial1.setTimeout(100);
	Serial.begin(115200);
	Serial1.begin(115200);
}

void loop() {
	while (Serial1.available() > 0) {
		data = Serial1.readString();
		Serial.print(data);
		Serial.print("\n");
	}
}
