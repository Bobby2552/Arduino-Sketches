void setup() 
{ 
  pinMode(21, OUTPUT);       // Motor Dir
  pinMode(22, OUTPUT);     // Motor Step
  }
void loop() 
{
  Pololu_A4988_Example();
}
void Pololu_A4988_Example()
{  
  delay(500);   // delay for Controller startup
  digitalWrite(21, HIGH);     // Turn left
  for(double i = 0; i < 500; i++)  //5000 steps in one direction
  {   
    digitalWrite(22, HIGH);
    delay(50);
    digitalWrite(22, LOW);
    delay(50);
  } 
  delay(500);   // delay for Controller startup
  digitalWrite(21, LOW);     // Turn left
  for(double i = 0; i < 500; i++)  //5000 steps in one direction
  {   
    digitalWrite(22, HIGH);
    delay(50);
    digitalWrite(22, LOW);
    delay(50);
  } 
  delay(500);
}

