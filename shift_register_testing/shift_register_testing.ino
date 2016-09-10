/*
Adafruit Arduino - Lesson 4. 8 LEDs and a Shift Register
*/

int latchPin = 8;
int clockPin = 12;
int dataPin = 11;

boolean leds[8] = {false, true, false, true, true, false, true, true};
boolean zeros[8] = {false, false, false, false, false, false, false, false};

void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}

void loop() 
{
    for (int i = 0; i < 8; i++) {
     digitalWrite(dataPin, zeros[i] ? HIGH:LOW);
     delay(1);
     digitalWrite(clockPin, HIGH);
     delay(1);
     digitalWrite(clockPin, LOW);
     delay(1);
     digitalWrite(dataPin, LOW);
       digitalWrite(latchPin, HIGH);
  
  digitalWrite(latchPin, LOW);
     
  }
  
  for (int i = 0; i < 8; i++) {
     digitalWrite(dataPin, leds[i] ? HIGH:LOW);
     delay(1);
     digitalWrite(clockPin, HIGH);
     delay(1);
     digitalWrite(clockPin, LOW);
     delay(1);
     digitalWrite(dataPin, LOW);
       digitalWrite(latchPin, HIGH);
  
  digitalWrite(latchPin, LOW);
    delay(500);
     
  }
  delay(1000);

}

