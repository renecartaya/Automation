char data;

void setup() 
{ 
  Serial.begin(9600); 
  pinMode(LED_BUILTIN, OUTPUT); 
  digitalWrite (LED_BUILTIN, LOW); //initially set to low
  Serial.println("Basic building block for CNC Control #1");
}
 
void loop() 
{
while (Serial.available())
  {
    data = Serial.read();
  }

  if (data == 'H')
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)

  
  else if (data == 'L')
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
}
