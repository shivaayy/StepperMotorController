
int dir_pin=3;
int pul_pin=2;
int temp=10000;
float z=0.0;
int potentioMeterReading=0;
void setup()
{
  pinMode(dir_pin,OUTPUT);
  pinMode(pul_pin,OUTPUT);
  digitalWrite(dir_pin,HIGH);
  Serial.begin(9600);
  
  for(int j=1;j<=18;j++){
    Serial.println(j);
    z=150000.0/temp;
    Serial.println(z);
    
    for(int i=0;i<200*1;i++){
      digitalWrite(pul_pin,HIGH);
      delayMicroseconds(temp);
      digitalWrite(pul_pin,LOW);
      delayMicroseconds(temp);
  
 }
 
    temp=temp-400;
    
  }
  temp=temp-100; 
  z=150000.0/temp;
  Serial.println(z);
  for(int i=0;i<200*30;i++){
  digitalWrite(pul_pin,HIGH);
  delayMicroseconds(temp);
  digitalWrite(pul_pin,LOW);
  delayMicroseconds(temp);
  
 }
   
	
}

void loop()
{
  potentioMeterReading=analogRead(A0);
  temp = map(potentioMeterReading,0,1024,4500,2500);
  
  
  Serial.println(150000.0/temp);
  
  for(int i=0;i<200;i++){
    digitalWrite(pul_pin,HIGH);
    delayMicroseconds(temp);
    digitalWrite(pul_pin,LOW);
    delayMicroseconds(temp);
  
 }

}
