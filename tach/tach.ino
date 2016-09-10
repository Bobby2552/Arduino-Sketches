#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

int tachPin = 2;
volatile int state = LOW;
int ctr = 0;
int buffer[84];
int timeRange = 5000;
int pixelTime = 50;
int rotations = 0;
int pixelsPerMinute = 60000 / pixelTime;
long curTime = 0;
long oldTime = 0;

 Adafruit_PCD8544 display = Adafruit_PCD8544(5, 4, 3);


void setup() {
    pinMode(tachPin, INPUT);
    pinMode(13, OUTPUT);
    pinMode(6, OUTPUT);
    Serial.begin(115200);
      display.begin();
      display.setContrast(50);
      display.clearDisplay();
}

void loop() {
  curTime = millis();
  digitalWrite(13, digitalRead(tachPin));
  if(digitalRead(tachPin) == LOW) {    
    ctr++; 
  }
  if(curTime - oldTime > 50) {
    //if (ctr <= 5) return;
    //Serial.println(ctr);
    rotations = ctr / 2;
    //Serial.print(rotations);
    Serial.println("here");
    update(rotations * pixelTime);
    //Serial.print("\t");
    //Serial.println(rotations);
    ctr = 0;
    oldTime = curTime;
  }

}

void update(int revs) {
  
  Serial.println(revs);
  display.clearDisplay();
  //Shift values in buffer
  for (int i = 0; i < 83; i++) {
    buffer[i] = buffer[i + 1];
  }
  //Insert current value
  buffer[83] = revs;
  
  if (buffer[83] > 10000) {
    for (int i = 0; i < 5; i++) {
      digitalWrite(6, HIGH);
      delay(1);
      digitalWrite(6, LOW);
      delay(1);
    } 
  }
  
  for(int i = 0; i < 84; i++) {
    //Serial.println(buffer[i]);
    
    int yPix = map(buffer[i], 2500, 17500, 0, 47);
    display.drawPixel(i, yPix, BLACK);
    //delay(10);
    //Serial.print(i);
    //Serial.print(", ");
    //Serial.println(yPix);
  }
  display.display();
  //delay(10000);
}
