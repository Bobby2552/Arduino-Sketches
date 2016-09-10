const int X_SIZE = 10;
const int Y_SIZE = 5;
const int X_START_PIN = 44;
const int Y_START_PIN = 2;

void setup() {
 for (int i = X_START_PIN; i < X_START_PIN + X_SIZE + Y_SIZE; i++) {
  pinMode(i, OUTPUT);
 } 
}

void loop() {
  while(1) {
   led(0,0,1); 
  }
  push(1);
}

void random(int dly) {
   led(random(0,X_SIZE), random(0,Y_SIZE), dly);
}

void led(int x, int y, int dly) {
 x += X_START_PIN;
 y += Y_START_PIN;
 for(int i = X_START_PIN; i < X_START_PIN + X_SIZE; i++) {
  digitalWrite(i, x == i ? HIGH:LOW);
 }
 for(int i = Y_START_PIN; i < Y_START_PIN + Y_SIZE; i++) {
  digitalWrite(i, y == i ? LOW:HIGH); 
 }
 
 delay(dly);
 
 for(int i = X_START_PIN; i < X_START_PIN + X_SIZE + 1; i++) {
  digitalWrite(i, LOW); 
 }
 for(int i = Y_START_PIN; i < Y_START_PIN + Y_SIZE + 1; i++) {
  digitalWrite(i, HIGH); 
 }
}

void push(int dly) {
 for (int x = 0; x < X_SIZE; x++) {
  for (int y = 0; y < Y_SIZE; y++) {
   if (y == sqrt(x)) led(x, y, dly);
  }
 } 
}
 
 void test(int dly) {
  for (int x = 0; x < X_SIZE; x++) {
   for (int y = 0; y < Y_SIZE; y++) {
    led(x, y, dly);
   } 
  } 
 }
