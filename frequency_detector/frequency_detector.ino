int buf[] = [3];
unsigned long firstTime;
unsigned long secondTime;
unsigned long sum = 0;

void setup() {
  Serial.begin(9600); 
}

void loop() {
  for (int i = 0; i < 3; i++) {
    // Fill Buffer
    buf[0] = analogRead(A0);
    buf[1] = analogRead(A0);
    buf[2] = analogRead(A0);
    do {
      //shift values back in array
      buf[0] = buf[1];
      buf[1] = buf[2];
      buf[2] = analogRead(A0);
    } while(!(buf[1] > buf[0] && buf[1] > buf[2]));
    firstTime = micros();
    // Fill Buffer
    buf[0] = analogRead(A0);
    buf[1] = analogRead(A0);
    buf[2] = analogRead(A0);
    do {
      //shift values back in array
      buf[0] = buf[1];
      buf[1] = buf[2];
      buf[2] = analogRead(A0);
    } while(!(buf[1] > buf[0] && buf[1] > buf[2]));
    secondTime = micros();
    sum += (secondTime - firstTime);
  }
  int freq = 1 / ((sum / 3.0) / 1000000.0);
  Serial.print(freq);
  Serial.println("Hz");
  
}
