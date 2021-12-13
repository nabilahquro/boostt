void setup() 
{
  pinMode(7, OUTPUT);

}

void loop() 
{
  digitalWrite(7, HIGH); //OFF
  delayMicroseconds(400);
  digitalWrite(7, LOW); //ON
  delayMicroseconds(1000 - 400);

}
