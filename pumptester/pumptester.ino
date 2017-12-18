#define in1 6
#define in2 7
int rotDirection = 0;
int pressed = false;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  Serial.setTimeout(50);
  String time = Serial.readString();
  if (time != NULL) {
    Serial.println("Running motor for " + time + " milliseconds");
    digitalWrite(in1, HIGH);
    delay(time.toInt());
    digitalWrite(in1, LOW); 
  }
}
