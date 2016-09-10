int ctr = 0;
int val;
long beginTime;
long endTime;


void setup() {
 Serial.begin(9600); 
}

void loop() {
  val = analogRead(A0);
  if (ctr == 0) {
    beginTime = millis();
  } else if (ctr == 99) {
    endTime = millis();
    Serial.println(millis() - beginTime);
    ctr = 0; 
  }
  
  if (val < 100) {
    ctr++; 
  }
  
}
