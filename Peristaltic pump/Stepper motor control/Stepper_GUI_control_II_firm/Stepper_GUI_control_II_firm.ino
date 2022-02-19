// Interfaced version
char user_In; // User input
int pin_dir = 2; // Setting I/O pin for stepper direction control
int pin_step = 3;// Setting I/O pin for stepper driving
int period_ms = 2; // setting the frequency through the signal period
int inter_delay = 1500; // setting the waiting time between processes
const int step_num = 1000; // setting the min number of steps to do in each process

void setup()
{
  Serial.begin(9600); 
  pinMode(pin_step, OUTPUT);
  pinMode(pin_dir, OUTPUT);
}

void loop()
{
if(Serial.available()> 0){ 
    
    user_In = Serial.read();               // read user input
      
      if(user_In == 'U'){                
        digitalWrite(pin_dir, HIGH); 
      }
      
      if(user_In == 'D'){
       digitalWrite(pin_dir, LOW);         
      }

      if(user_In == 'H'){
       digitalWrite(pin_step, HIGH); 
         for(int x = 0; x < step_num; x++)
         {
          digitalWrite(pin_step, HIGH);
          delay(period_ms);
          digitalWrite(pin_step, LOW);
          delay(period_ms);
          }         
      }

      if(user_In == 'L'){
       digitalWrite(pin_step, LOW);         
      }

  } // Serial.available loop
  
  //digitalWrite(pin_dir,LOW); // Clockwise 

// delay(inter_delay); // Wait a second
}
