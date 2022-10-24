/* 
 *  Firmware for linear positioning system 
 *  
 *  Optical encoder module
 *  
 *  Author: René A. Cartaya López
 *
 *  Goal: Optical encoder for liear positioning
 *
 */

int encoder_pin = 2;  // The pin the encoder is connected           
unsigned int dist;     // linear steps reading
volatile byte pulses;  // number of pulses
unsigned long timeold; 
unsigned int pulsesperturn = 20;
int delay_time = 300;

 void counter()
 {
      pulses++;    
 }

void setup()
 {
   Serial.begin(9600); // initialize serial communication at 9600 bits per second:
   pinMode(encoder_pin, INPUT);
   attachInterrupt(0, counter, FALLING);
   pulses = 0;
   dist = 0;
   timeold = 0;

 }

 void loop()
 {

  digitalWrite(encoder_pin, LOW); // Clears the trigPin condition
  delayMicroseconds(2);

  digitalWrite(encoder_pin, HIGH);// Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  delayMicroseconds(10);
  digitalWrite(encoder_pin, LOW);
  
   float dataRead_0 = analogRead(encoder_pin);   // read the input on asigned pin :
   dataRead_0 = (dataRead_0/1024.0)*5;
  
   String dataToSend_0 = String(dataRead_0);
   Serial.println(dataToSend_0);  // print out the value you read:
   delay(delay_time);        // delay in between reads for stability
  
   if (millis() - timeold >= 1000)
   {  /*Uptade every one second, this will be equal to reading frecuency (Hz).*/
   detachInterrupt(0);

   dist = (pulsesperturn * 60 * 1000 )/ (millis() - timeold)* pulses;// Just an test, this have not physical meaning like it is
   timeold = millis();
   pulses = 0;

   // data to be tested in Arduino serial monitor, can not be used at the same time of the Python GUI i.e. for test on Arduino IDE uncomment it and use the below commands, for Python GUI use, keep as it is
   
    Serial.print("Distance = ");
    Serial.println(dist,DEC);
    attachInterrupt(0, counter, FALLING);
   }
  }
 
