/* 
 *  Linear positioning system Version I
 *  
 *  Author: René A. Cartaya López
 *
 *  Goal: Optical encoder for liear positioning
 *
 */

int encoder_pin = 2;  // The pin the encoder is connected           
unsigned int rpm;     // rpm reading
volatile byte pulses;  // number of pulses
unsigned long timeold; 
// The number of pulses per revolution
// depends on your index disc!!
unsigned int pulsesperturn = 20;
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

 void counter()
 {    
      pulses++;    //Update count
 }

void setup()
 {
   Serial.begin(9600);
   pinMode(encoder_pin, INPUT);//Use statusPin to flash along with interrupts
   
   //Interrupt 0 is digital pin 2, so that is where the IR detector is connected
   //Triggers on FALLING (change from HIGH to LOW)
   attachInterrupt(0, counter, FALLING);
   // Initialize
   pulses = 0;
   rpm = 0;
   timeold = 0;

 }

 void loop()
 {

  float duration = pulseIn(2, HIGH);// Reads the echoPin, returns the sound wave travel time in microseconds
  distance = duration * 0.034 / 2; // Calculating the distance considering the speed of sound wave divided by 2 (go and back)

  String dataToSend = String(distance);
  Serial.println(dataToSend);  // print out the value you read:
  delay(300);        // delay in between reads for stability
  
   if (millis() - timeold >= 500){  /*Uptade every one second, this will be equal to reading frecuency (Hz).*/
 
   detachInterrupt(0);
   rpm = (60 * 500 / pulsesperturn )/ (millis() - timeold)* pulses;
   timeold = millis();
   pulses = 0;

   
   //Serial.print("RPM = ");//Write it out to serial port
   //Serial.println(rpm,DEC);//Write it out to serial port
   
   //attachInterrupt(0, counter, FALLING);//Restart the interrupt processing
   }
  }
