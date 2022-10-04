/* Author: René Cartaya
   Date: September 2022
   Goal: Computer control of a relay of 5V
   Description:  
    S: pin 3
    +: 5V
    -: GND
*/

// Defining
const int RELAY_PIN = 3;  // defining the arduino pin connects to connected to the pin IN of the relay

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin as an output.
  pinMode(RELAY_PIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(RELAY_PIN, HIGH);
  delay(1000);
  digitalWrite(RELAY_PIN, LOW);
  delay(1000);
}
