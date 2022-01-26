#include <AccelStepper.h>
AccelStepper stepper(1,2,3);
long int maximumSpeed=4000;
int count=0;
// stepper control global variable
int starting_delay_microseconds = 10000;
int final_delay_microseconds_at_max_speed = 125;
int current_delay_microseconds=starting_delay_microseconds;
unsigned long int start_millis=0;
unsigned long int current_millis=0;
unsigned long int time_in_sec=0;
/////////

//
float acceleration =0.1;  // steps/sec^2 
//
void setup() {
  Serial.begin(9600);
  DDRD=B00001100;
}

void loop() {
  while(true){
    custom_run();
    PORTD=B00001100;
    delayMicroseconds(current_delay_microseconds);
    PORTD=B00001000;
    delayMicroseconds(current_delay_microseconds);    
  }

}

void custom_run(){
  unsigned long int temp_millis= millis();
if(current_delay_microseconds>final_delay_microseconds_at_max_speed && temp_millis-current_millis>=1000){
//  Serial.println(current_delay_microseconds);
  current_millis=temp_millis;
  time_in_sec++;
      // v=u+at;
//int final_speed =(500000.0/current_delay_microseconds)+(acceleration*time_in_sec);
//current_delay_microseconds=500000.0/final_speed;
current_delay_microseconds=500000.0*current_delay_microseconds/(500000+current_delay_microseconds*acceleration*time_in_sec);
  
}
}
