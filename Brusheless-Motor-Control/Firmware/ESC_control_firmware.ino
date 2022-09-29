/* 
 *  Author: René A. Cartaya López
 *
 * Goal: ESC Control of a brusheless motor
 *
 */

#include <Servo.h>
char data;
Servo ESC_con;  // create servo object to control a servo
int velocity = 0;    // variable to store the servo position

void setup() 
{ 
  Serial.begin(9600); 
  pinMode(LED_BUILTIN, OUTPUT); 
  digitalWrite (LED_BUILTIN, LOW); //initially set to low
  Serial.println("Basic building block for CNC Control #2");
  ESC_con.attach(9);  // attaches the servo on pin 9 to the servo object
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
  velocity = 0; 
  ESC_con.write(velocity);              // set the velocity of rotation

  if  (data == 'b') 
  velocity = 10; 
  ESC_con.write(velocity);              // set the velocity of rotation

  if  (data == 'c') 
  velocity = 20; 
  ESC_con.write(velocity);              // set the velocity of rotation

  if  (data == 'd') 
  velocity = 30; 
  ESC_con.write(velocity);              // set the velocity of rotation

  if  (data == 'e') 
  velocity = 40; 
  ESC_con.write(velocity);              // set the velocity of rotation

  if  (data == 'f') 
  velocity = 50; 
  ESC_con.write(velocity);              // set the velocity of rotation
}

  
