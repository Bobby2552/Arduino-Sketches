
#define COUNT(arr) (sizeof(arr) / sizeof(*arr))

int analogPin=0;
int strobePin=2;
int resetPin=3;

int filter=90;
int del = 15;

#define NUM_CHANNELS 7

double channels[NUM_CHANNELS] = {0};
double channelTotals[NUM_CHANNELS] = {0};
double channelAvgs[NUM_CHANNELS] = {0};

int maxSamplesToAverage = 5;
int curSample = maxSamplesToAverage;

void readChannels() {
  digitalWrite(resetPin, HIGH);
  digitalWrite(resetPin, LOW);
  for (int i=0;i<NUM_CHANNELS;i++){
    digitalWrite(strobePin, LOW);
    delay(del);
    channels[i]=analogRead(analogPin);
    channels[i]=constrain(channels[i], filter, 1023);
    channels[i] /= 1023.0;
    
    Serial.print(channels[i]);
    Serial.print(" ");
    digitalWrite(strobePin, HIGH);
  }
  
  Serial.println();
  curSample++;
  
  if (curSample > maxSamplesToAverage) {
    for (int i = 0; i < NUM_CHANNELS; i++) {
      channelAvgs[i] = channelTotals[i] / maxSamplesToAverage;
      channelTotals[i] = 0;  
    }
    
    curSample = 0; 
  }
}

void setup() {
  Serial.begin(9600);
  
  pinMode(analogPin, INPUT);
  pinMode(strobePin, OUTPUT);
  pinMode(resetPin, OUTPUT);
  
  for (int i = 5; i < 9; i++) {
     pinMode(i, OUTPUT); 
  }
  
  digitalWrite(resetPin, LOW);
  digitalWrite(strobePin, HIGH);

  //readChannels();
}

void loop() {
  readChannels();
}
