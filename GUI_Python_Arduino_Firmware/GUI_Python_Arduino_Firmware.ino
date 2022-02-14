int data;

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

  if (data == '1')
  digitalWrite (LED_BUILTIN, HIGH);

  else if (data == '0')
  digitalWrite (LED_BUILTIN, LOW);

}
