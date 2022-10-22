int encoder_pin = 4;  // The pin the encoder is connected           
unsigned int dist;     // rpm reading
volatile byte pulses;  // number of pulses
unsigned long timeold; 
unsigned int pulsesperturn = 20;

 void counter()
 {
      pulses++;    
 }

void setup()
 {
   Serial.begin(9600);
   pinMode(encoder_pin, INPUT);
   attachInterrupt(0, counter, FALLING);
   pulses = 0;
   dist = 0;
   timeold = 0;

 }

 void loop()
 {
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
 
