#include <AccelStepper.h>
AccelStepper stepper(1,2,3);
long int maximumSpeed=4000;
int count=0;
// stepper control global variable
int starting_delay_microseconds = 10000;
int final_delay_microseconds_at_max_speed = 100;
int current_delay_microseconds=starting_delay_microseconds;
unsigned long int start_millis=0;
unsigned long int current_millis=0;
unsigned long int setup_time_in_sec=0;
/////////

//
float acceleration =1;  // steps/sec^2 
//
void setup() {
  Serial.begin(9600);
  DDRD=B00001100;
}

void loop() {
  while(current_delay_microseconds>final_delay_microseconds_at_max_speed){
    custom_run(true);
    PORTD=B00001100;
    delayMicroseconds(current_delay_microseconds);
    PORTD=B00001000;
    delayMicroseconds(current_delay_microseconds);    
  }
    while(true){
    custom_run(false);
    PORTD=B00001100;
    delayMicroseconds(current_delay_microseconds);
    PORTD=B00001000;
    delayMicroseconds(current_delay_microseconds);    
  }

}

void custom_run(bool setup_mode){
  unsigned long int temp_millis= millis();
  
if(setup_mode && current_delay_microseconds>final_delay_microseconds_at_max_speed && temp_millis-current_millis>=1000){
//  Serial.println("setup");
//Serial.println(current_delay_microseconds);
  current_millis=temp_millis;
  setup_time_in_sec++;
  current_delay_microseconds=500000.0*current_delay_microseconds/(500000+current_delay_microseconds*acceleration*setup_time_in_sec);
}
else{
  if(temp_millis-current_millis>=1000){
//      int temp_read= map(analogRead(A0),0,1023,300,130);
//      if(temp_read-final_delay_microseconds_at_max_speed>1 || temp_read-final_delay_microseconds_at_max_speed<-1){
//        setup_time_in_sec=0;
//        final_delay_microseconds_at_max_speed=temp_read;
//        }
  }
  if( current_delay_microseconds>final_delay_microseconds_at_max_speed && temp_millis-current_millis>=1000){
//    Serial.println("accelarting");
//Serial.println(current_delay_microseconds);
  current_millis=temp_millis;
  setup_time_in_sec++;
  current_delay_microseconds=500000.0*current_delay_microseconds/(500000+current_delay_microseconds*acceleration*setup_time_in_sec);
}
  else if(current_delay_microseconds-final_delay_microseconds_at_max_speed<-1 && temp_millis-current_millis>=1000){
//    Serial.println("dis-accelarting");
//Serial.println(current_delay_microseconds);
  current_millis=temp_millis;
  setup_time_in_sec++;
  current_delay_microseconds=500000.0*current_delay_microseconds/(500000-current_delay_microseconds*acceleration*setup_time_in_sec);
}

  }

}
