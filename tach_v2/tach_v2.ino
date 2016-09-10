#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

int tachPin = 2;
int ctr = 0;
int buffer[84];
long curTime = 0;
long oldTime = 0;
long startTime = 0;
long endTime = 0;

 Adafruit_PCD8544 display = Adafruit_PCD8544(5, 4, 3);


void setup() {
    pinMode(tachPin, INPUT);
    pinMode(6, OUTPUT);
    Serial.begin(115200);
      display.begin();
      display.setContrast(50);
      display.clearDisplay();
      
}

void loop() {
  if (digitalRead(tachPin) == LOW) {
    if (ctr == 0) {
     startTime = millis();
     ctr++;
    } else if (ctr < 10) {
      ctr++;
    } else if (ctr == 10) {
      endTime = millis();
      long time = (endTime - startTime) / 10;
      int rpms = toRpm(time);
      Serial.println(rpms);
      delay(50);
    }
  }
}

int toRpm(long time) {
  int rpm = (1000 / time) * 30;
}
