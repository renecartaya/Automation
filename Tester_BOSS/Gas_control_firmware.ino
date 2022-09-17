/* 
 *  Author: René A. Cartaya López
 *
 * Goal: The control of a Gas Injection system for a plasma source
 *
 */

#include <Servo.h>
char data;
Servo myservo;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position

void setup() 
{ 
  Serial.begin(9600); 
  pinMode(LED_BUILTIN, OUTPUT); 
  digitalWrite (LED_BUILTIN, LOW); //initially set to low
  Serial.println("Basic building block for CNC Control #1");
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}
 
void loop() 
{
while (Serial.available())
  {
    data = Serial.read();
  }

  if (data == 'H')
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)

  
  if (data == 'L')
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW

  if  (data == 'a') 
  pos = 0; 
  myservo.write(pos);              // tell servo to go to position in variable 'pos'

  if  (data == 'b') 
  pos = 50; 
  myservo.write(pos);              // tell servo to go to position in variable 'pos'

  if  (data == 'c') 
  pos = 100; 
  myservo.write(pos);              // tell servo to go to position in variable 'pos'

  if  (data == 'd') 
  pos = 150; 
  myservo.write(pos);              // tell servo to go to position in variable 'pos'

  if  (data == 'e') 
  pos = 200; 
  myservo.write(pos);              // tell servo to go to position in variable 'pos'

}

  
