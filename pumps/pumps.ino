int pumps[] = {2,3,4,5,6,7,8,9};

void setup() {
  for (int i = 0; i < 8; i++) {
   pinMode(pumps[i], OUTPUT); 
  }
  for (int i = 0; i < 8; i++) {
   digitalWrite(pumps[i], HIGH); 
  }
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 8; i++) {
    digitalWrite(pumps[i], LOW);
    delay(1000);
    digitalWrite(pumps[i], HIGH); 
  }
}
