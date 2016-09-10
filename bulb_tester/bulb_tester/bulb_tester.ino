void setup() {
 Serial.begin(115200); 
}

double solarPanel = 42;
double oldSolarPanel;

long oldTime = 0;

void loop() {
 solarPanel = analogRead(0) / 1023.0;

 if (oldSolarPanel < 0.05 && solarPanel > 0.05) {
   oldTime = millis();
 }

 if (solarPanel > 0.05) {
  Serial.print(solarPanel); 
  Serial.print("\t:\t");
  Serial.println(millis() - oldTime);
 }
   
 oldSolarPanel = solarPanel;
 
 delay(10);
}
