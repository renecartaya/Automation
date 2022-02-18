void setup()
{
  pinMode(2, OUTPUT);
}
void loop()
{
  {
    digitalWrite(2, HIGH);
    delay(50); // 5 Volts in Multumeter if is set in 2000 milliseconds
    digitalWrite(2, LOW);
    delay(50); // 5 Volts in Multumeter if is set in 2000 milliseconds
  } 
}
