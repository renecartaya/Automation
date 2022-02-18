int pin_step = 2;
int period_ms = 50;

void setup()
{
  pinMode(pin_step, OUTPUT);
}
void loop()
{
  {
    digitalWrite(pin_step, HIGH);
    delay(period_ms);
    digitalWrite(pin_step, LOW);
    delay(period_ms);
  } 
}
