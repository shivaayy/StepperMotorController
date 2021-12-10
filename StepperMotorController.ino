
int dir_pin=3;
int pul_pin=2;
int motor_direction=HIGH;
unsigned long int initial_time=millis();
int direction_change_time=5000;
void setup()
{
  pinMode(dir_pin,OUTPUT);
  pinMode(pul_pin,OUTPUT);
  digitalWrite(dir_pin,HIGH);
  Serial.begin(9600);
}

void loop()
{
//  int potentioMeterReading=analogRead(A0);
//  int rpm = map(potentioMeterReading,0,1024,30,150);
//  int time_delay=30000/rpm;
//  Serial.println("-----rpm-----");
//  Serial.println(rpm);
//  Serial.println("----time delay------");
//  Serial.println(time_delay);
//  Serial.println("----direction------");
//  Serial.println(motor_direction);
//  unsigned long int final_time=millis();
//  Serial.println("----final time------");
//  Serial.println(final_time);
//  if(final_time-initial_time>direction_change_time){
//    changeDirection();
//    initial_time=final_time;
//  }
  for(int i=0;i<200*5;i++){
    digitalWrite(pul_pin,HIGH);
    delayMicroseconds(1000);
//      delayMicroseconds(time_delay);
      digitalWrite(pul_pin,LOW);
      delayMicroseconds(1000);
//      delayMicroseconds(time_delay);
  }
  
}

void changeDirection(){
  if(motor_direction==1)
  motor_direction=0;
  else
  motor_direction=1;
  digitalWrite(dir_pin,motor_direction);
  
}
