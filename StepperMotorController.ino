
int dir_pin=3;
int pul_pin=2;
int temp=15200;
float z=0.0;
int potentioMeterReading=0;
void setup()
{
  pinMode(dir_pin,OUTPUT);
  pinMode(pul_pin,OUTPUT);
  digitalWrite(dir_pin,HIGH);
  Serial.begin(9600);
  
  for(int j=1;j<=35;j++){
//    Serial.println(j);
    z=75000.0/temp;
    Serial.println(z);
    
    for(int i=0;i<200*4;i++){
      digitalWrite(pul_pin,HIGH);
//      delayMicroseconds(temp);
      digitalWrite(pul_pin,LOW);
      delayMicroseconds(temp);
  
 }
 
    temp=temp-400;
    
  }
  temp=temp+100; 
  z=75000.0/temp;
  Serial.println(z);
  for(int i=0;i<200*40;i++){
  digitalWrite(pul_pin,HIGH);
//  delayMicroseconds(temp);
  digitalWrite(pul_pin,LOW);
  delayMicroseconds(temp);
  
 }
   
	
}

void loop()
{
  potentioMeterReading=analogRead(A0);
  temp = map(potentioMeterReading,0,1024,2300,1200);
  
  
  Serial.println(75000.0/temp);
  
  for(int i=0;i<200*4;i++){
    digitalWrite(pul_pin,HIGH);
//    delayMicroseconds(temp);
    digitalWrite(pul_pin,LOW);
    delayMicroseconds(temp);
  
 }

}
