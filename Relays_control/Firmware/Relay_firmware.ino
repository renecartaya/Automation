/* Author: René Cartaya
   Date: September 2022
   Goal: Computer control of a relay of 5V
   Description: Firmware for the control of a module of 4 relays
*/

// Defining

char user_In; // User serial input
const int relay_pin_1 = 3;  // defining the arduino pin connects to connected to the pin IN of the relays
const int relay_pin_2 = 5;
const int relay_pin_3 = 6;
const int relay_pin_4 = 9;

void setup() {
  Serial.begin(9600); // force to do actions just under serial signals commands
  
  digitalWrite (relay_pin_1, LOW); //initially set to low, it could also depends of the pins connected on the relay
  pinMode(relay_pin_1, OUTPUT); // initialize digital pin as an output.
  
  digitalWrite (relay_pin_2, LOW); //initially set to low, it could also depends of the pins connected on the relay
  pinMode(relay_pin_2, OUTPUT); // initialize digital pin as an output.

  digitalWrite (relay_pin_3, LOW); //initially set to low, it could also depends of the pins connected on the relay
  pinMode(relay_pin_3, OUTPUT); // initialize digital pin as an output.

  digitalWrite (relay_pin_4, LOW); //initially set to low, it could also depends of the pins connected on the relay
  pinMode(relay_pin_4, OUTPUT); // initialize digital pin as an output.
}

// the loop function runs over and over again forever
void loop()
{

  while (Serial.available())
  {
    user_In = Serial.read();
  }

  if (user_In == 'A')
  digitalWrite(relay_pin_1, HIGH);   // turn the LED on (HIGH is the voltage level)

  
  if (user_In == 'B')
  digitalWrite(relay_pin_1, LOW);    // turn the LED off by making the voltage LOW

 
  if (user_In == 'C')
  digitalWrite(relay_pin_2, HIGH);   // turn the LED on (HIGH is the voltage level)

  
  if (user_In == 'D')
  digitalWrite(relay_pin_2, LOW);    // turn the LED off by making the voltage LOW
  

  if (user_In == 'E')
  digitalWrite(relay_pin_3, HIGH);   // turn the LED on (HIGH is the voltage level)

  
  if (user_In == 'F')
  digitalWrite(relay_pin_3, LOW);    // turn the LED off by making the voltage LOW
  

  if (user_In == 'G')
  digitalWrite(relay_pin_4, HIGH);   // turn the LED on (HIGH is the voltage level)

  
  if (user_In == 'H')
  digitalWrite(relay_pin_4, LOW);    // turn the LED off by making the voltage LOW

}
