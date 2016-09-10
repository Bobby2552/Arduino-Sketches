const int speed = 5;

void setup() {
  // initialize digital pin 13 as an output.
  for (int i = 2; i < 10; i++) {
  pinMode(i, OUTPUT);
  }
}

// the loop function runs over and over again forever
void loop() {
  for (int i = 2; i < 10; i++) {
    digitalWrite(i, HIGH);
    delay(speed);
    digitalWrite(i, LOW);
    delay(speed);
  }
  for (int i = 2; i < 10; i++) {
    digitalWrite(i, LOW);
    delay(speed);
    digitalWrite(i, HIGH);
    delay(speed);
  }
                // wait for a second
}
