// Variable declaration
int pin_dir = 2; // direction pin setted at output # 2
int pin_step = 3; // step pin setted at output # 2
int period_ms = 50; // velocity setting

void setup()
{
  pinMode(pin_step, OUTPUT);
  pinMode(pin_dir, OUTPUT);
}
void loop()
{
  {
    digitalWrite(pin_dir,LOW);
    digitalWrite(pin_step, HIGH);
    delay(period_ms);
    digitalWrite(pin_step, LOW);
    delay(period_ms);
  } 
}
// Author: René A. Cartaya L.
