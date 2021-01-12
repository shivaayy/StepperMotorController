
int dir_pin=3;
int pul_pin=2;
int temp=10000;
void setup()
{
  pinMode(dir_pin,OUTPUT);
  pinMode(pul_pin,OUTPUT);
  digitalWrite(dir_pin,HIGH);
  
  for(int j=0;j<19;j++){
    
    for(int i=0;i<200*3;i++){
  digitalWrite(pul_pin,HIGH);
 delayMicroseconds(temp);
 digitalWrite(pul_pin,LOW);
 delayMicroseconds(temp);
  
 }
 temp=temp-400;
    
  }

for(int i=0;i<200*30;i++){
  digitalWrite(pul_pin,HIGH);
 delayMicroseconds(temp);
 digitalWrite(pul_pin,LOW);
 delayMicroseconds(temp);
  
 }
   
	
}

void loop()
{
temp=4000;
  for(int i=0;i<200*30;i++){
  digitalWrite(pul_pin,HIGH);
 delayMicroseconds(temp);
 digitalWrite(pul_pin,LOW);
 delayMicroseconds(temp);
  
 }

}
