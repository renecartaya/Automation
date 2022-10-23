/* 
 *  Linear positioning system Version I
 *  
 *  Author: René A. Cartaya López
 *
 *  Goal: Optical encoder for liear positioning
 *
 */

int encoder_pin = 4;  // The pin the encoder is connected           
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
   float dataRead_0 = analogRead(encoder_pin);   // read the input on asigned pin :
   dataRead_0 = (dataRead_0/1024.0)*5;
   String dataToSend_0 = String(dataRead_0);
   Serial.println(dataToSend_0);  // print out the value you read:
   delay(delay_time);        // delay in between reads for stability
  
   if (millis() - timeold >= 500){  /*Uptade every one second, this will be equal to reading frecuency (Hz).*/
   detachInterrupt(0);

   dist = (pulsesperturn * 60 * 500 )/ (millis() - timeold)* pulses;// Just an test, this have not physical meaning like it is
   timeold = millis();
   pulses = 0;
   
   Serial.print("Distance = ");
   Serial.println(dist,DEC);
   attachInterrupt(0, counter, FALLING);
   }
  }
 
