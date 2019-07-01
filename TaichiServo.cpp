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

void TaichiServo::setServoSpeed(int usrServoSpeed){
  servoSpeed = usrServoSpeed;
}

int TaichiServo::getServoSpeed(){
  return servoSpeed;
}

void TaichiServo::servoUpdate(){
    servoPos = this->read(); 				//获取当前舵机的位置
    distance2Go = servoTarget - servoPos;   //获取当前位置与目标位置的距离
	
    if (distance2Go != 0) {					//如果当前位置与目标位置间存在距离
											//检查速度延迟参数是否达到设定数值
	  if (delayCouter < servoSpeed){		//如果速度延迟参数尚未达到设定数值
		delayCouter++;						//延迟参数自加
	  }else {								//如果速度延迟参数已经达到设定数值
		delayCouter = 0;					//延迟参数复位清零
		
		if(distance2Go > 0){				//如果距离为正
		  servoPos++;						
		  this->write(servoPos);			//舵机正转一步
		} else if (distance2Go < 0){		//如果距离为负
		  servoPos--;							
		  this->write(servoPos);			//舵机反转一步
		}
	  }
    }
}
