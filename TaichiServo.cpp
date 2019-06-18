#include <Arduino.h>
#include <Servo.h>
#include "TaichiServo.h"

TaichiServo::TaichiServo(){
}

TaichiServo::TaichiServo(long usrServoDelay){
  if (usrServoDelay > DEFAULT_SERVO_SPEED){
    servoSpeed = usrServoDelay;
  }
}

void TaichiServo::setTarget(int usrTarget){
  if (usrTarget > 180){
    usrTarget = 180;
  } else if (usrTarget < 0){
    usrTarget = 0;
  } 
  servoTarget = usrTarget;
}

int TaichiServo::getTarget(){
  return servoTarget;
}

int TaichiServo::getPosition(){
  return this->read();
}

int TaichiServo::getDistanceToGo(){
  servoPos = this->read();
  distance2Go = servoTarget - servoPos;
  return distance2Go;
}

int TaichiServo::setServoSpeed(int usrServoSpeed){
  servoSpeed = usrServoSpeed;
}

void TaichiServo::servoUpdate(){
  servoPos = this->read();
  if (delayCouter < servoSpeed){
    delayCouter++;
  }else {
    delayCouter = 0;
    distance2Go = servoTarget - servoPos;
    if(distance2Go > 0){
      servoPos++;
      this->write(servoPos);
    } else if (distance2Go < 0){
      servoPos--;
      this->write(servoPos);
    }
  }
}
