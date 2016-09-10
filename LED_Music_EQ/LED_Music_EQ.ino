int strobePin = 2;
int resetPin = 3;
int outPin = A0;
int spectrumValues[7];
int band;
int filter = 80;

void setup() {
  pinMode(resetPin, OUTPUT);
  digitalWrite(resetPin, LOW);
  pinMode(strobePin, OUTPUT);
  digitalWrite(strobePin, HIGH);
  for (int i = 4; i < 11; i++) {
    pinMode(i, OUTPUT);
  } 
  Serial.begin(115200);
}

void loop() {
 digitalWrite(resetPin, HIGH);
 digitalWrite(resetPin, LOW);
 for(band=0; band <7; band++)
 {
 digitalWrite(strobePin, LOW); // strobe pin on the shield - kicks the IC up to the next band 
 delayMicroseconds(30); // 
 spectrumValues[band] = analogRead(outPin);
 //spectrumValues[band] = constrain(spectrumValues[band], 0, 1023);
 spectrumValues[band] = map(spectrumValues[band], 0, 1023, 0, 255);
 digitalWrite(strobePin, HIGH);  
 }  
  
  for (int i = 0; i < 7; i++) {
    Serial.print(spectrumValues[i]);
    Serial.print("\t");
    digitalWrite(i + 4, spectrumValues[i] > 100 ? HIGH:LOW); 
  }
  delay(10);
  Serial.println();
}

void readMSGEQ7()
// Function to read 7 band equalizers
{
 digitalWrite(resetPin, HIGH);
 digitalWrite(resetPin, LOW);
 for(band=0; band <7; band++)
 {
 digitalWrite(strobePin, LOW); // strobe pin on the shield - kicks the IC up to the next band 
 delayMicroseconds(30); // 
 spectrumValues[band] = analogRead(outPin);
 //spectrumValues[band] = constrain(spectrumValues[band], 0, 1023);
 spectrumValues[band] = map(spectrumValues[band], 0, 1023, 0, 255);
 digitalWrite(strobePin, HIGH);
 }
}
