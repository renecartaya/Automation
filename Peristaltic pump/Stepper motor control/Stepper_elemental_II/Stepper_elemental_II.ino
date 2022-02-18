// Declared variables
int pin_step = 2; // Output pin selection
int period_ms = 50; // Velocity setting

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
// Author: René Cartaya
