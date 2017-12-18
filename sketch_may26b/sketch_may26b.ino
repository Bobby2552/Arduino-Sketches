#include <aJSON.h>

char * str = (char *) malloc(sizeof(char) * 250);
int i = 0;
long start = millis();
aJsonObject * msg;
void setup() 
{
  Serial2.begin(9600);         //Sets the data rate in bits per second (baud) for Serial2 data transmission
  Serial.begin(9600);
  pinMode(13, OUTPUT);        //Sets digital pin 13 as output pin
}
void loop()
{
  if(Serial2.available() > 0)  // Send data only when you receive data:
  {
    //Check to see if the text should be included in the current transmission.
    if (millis() - start > 100) {
      str[i] = 0;
      msg = aJson.parse(str);
      aJsonObject * mode = aJson.getObjectItem(msg, "mode");
      Serial.print(mode->aJson_String);

      Serial.print(str);
      Serial.print('\n');
      start = millis();
      i = 0;
      //Clear out the array
      for (int j = 0; j < 250; j++) {
        str[j] = 0;
      } 
    }
    str[i++] = Serial2.read();      //Read the incoming data and store it into variable data
  }                            
}
