char user_In;
int pin_dir = 2;
int pin_step = 3;
int period_ms = 2;
int inter_delay = 0; // This control the waiting time after each order
int step_num = 200;

void setup()
{
  Serial.begin(9600); 
  pinMode(pin_step, OUTPUT);
  pinMode(pin_dir, OUTPUT);
}
void loop()
{
if(Serial.available()> 0){ // this conditional make mandatory an serial command to start
  user_In = Serial.read();
  
// ========================= Counterclockwise ======================================= //

  if(user_In == 'U'){
  
  digitalWrite(pin_dir,HIGH); // Counterclockwise 
  for(int x = 0; x < step_num; x++)
  {
    digitalWrite(pin_step, HIGH);
    delay(period_ms);
    digitalWrite(pin_step, LOW);
    delay(period_ms);
  } 
 delay(inter_delay); // Wait a second
 }

// ========================= Clockwise ======================================= //

  if(user_In == 'D'){
  
  digitalWrite(pin_dir,LOW); // Clockwise 
  for(int x = 0; x < step_num; x++)
  {
    digitalWrite(pin_step, HIGH);
    delay(period_ms);
    digitalWrite(pin_step, LOW);
    delay(period_ms);
  } 
 delay(inter_delay); // Wait a second
 }
// delay(inter_delay); // Wait a second
}
}
