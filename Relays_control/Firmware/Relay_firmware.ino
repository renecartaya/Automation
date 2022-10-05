/* Author: René Cartaya
   Date: September 2022
   Goal: Computer control of a relay of 5V
   Description:  
    S: pin 3
    +: 5V
    -: GND
*/

// Defining

char user_In; // User serial input
const int relay_pin = 3;  // defining the arduino pin connects to connected to the pin IN of the relay


void setup() {
  Serial.begin(9600); // force to do actions just under serial signals commands
  digitalWrite (relay_pin, LOW); //initially set to low, it could also depends of the pins connected on the relay
  pinMode(relay_pin, OUTPUT); // initialize digital pin as an output.
}

// the loop function runs over and over again forever
void loop()
{

  while (Serial.available())
  {
    user_In = Serial.read();
  }

  if (user_In == 'H')
  digitalWrite(relay_pin, HIGH);   // turn the LED on (HIGH is the voltage level)

  
  if (user_In == 'L')
  
  digitalWrite(relay_pin, LOW);    // turn the LED off by making the voltage LOW

}
