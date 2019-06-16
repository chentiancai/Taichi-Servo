/*
Taichi-Servo
基于Arduino官方servo库，增加了更多功能。
*/

#include "TaichiServo.h"

TaichiServo myservo(100);

void setup() {
  Serial.begin(9600);
  myservo.attach(5);
  myservo.setTarget(180);  
}

void loop() {
  if(myservo.getPosition() == 0){    

    myservo.setTarget(180);  
  } else if (myservo.getPosition() == 180){

    myservo.setTarget(0);
  }   
   
  myservo.servoUpdate();
}
