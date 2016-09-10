#include <eRCaGuy_analogReadXXbit.h>

double res = 1023.0;
eRCaGuy_analogReadXXbit adc;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int base = res * (4.8 / 3.3);
  float vals[4];
  for (int i = 0; i < 4; i++) {
    vals[i] = adc.analogReadXXbit(i, 15, 1); 
    Serial.print(vals[i]);
    Serial.print("\t");
  }
  Serial.print((vals[0] + vals[1] + vals[2] + vals[3]) / 4);
  Serial.println();
}
