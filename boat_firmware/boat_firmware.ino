#include <Servo.h>
unsigned long lastConnected = 0;

float rightPower, leftPower = 0;
Servo leftMotor, rightMotor;



void setup() {
  Serial1.begin(9600);
  Serial.begin(115200);
  leftMotor.attach(6);
  rightMotor.attach(7);
}

void loop() {
  if(Serial1.available()>0){
    char selector = Serial1.read();
    switch(selector){
      case 'o':
       lastConnected = millis();
        break;
        
      case 'r':
        rightPower = Serial1.parseFloat();
        break;

      case 'l':
        leftPower = Serial1.parseFloat();
        break;
    }
  }

  if(millis-lastConnected > 700){
    disconnected();
  }
  else{
   //Control code
    setMotors(rightPower, leftPower);  
  }
}


void disconnected(){
  setMotors(0,0)
}


void setMotors(float rightVal, float leftVal){
  //servo microseconds from 1000 to 2000
  
  leftMotor.writeMilliseconds(constrain());
  rightMotor.write();
}
