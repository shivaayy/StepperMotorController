#include <AccelStepper.h>
AccelStepper stepper(1,2,3);
long int maximumSpeed=800;
int count=0;
void setup() {
  Serial.begin(9600);
  stepper.setMaxSpeed(maximumSpeed);
  stepper.setAcceleration(400);
  stepper.moveTo(12000);
}

void loop() {
  while(true){
      if (stepper.distanceToGo() == 0){
      maximumSpeed=map(analogRead(A0),0,1023,400,1600);
      Serial.println(maximumSpeed);
      stepper.setMaxSpeed(maximumSpeed);
      stepper.moveTo(-stepper.currentPosition());
   }
    stepper.run();
  }

}
