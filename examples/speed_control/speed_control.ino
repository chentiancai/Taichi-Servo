/*
  speed_control
  by Taichi-Maker
  www.taichi-maker.com
  2019-06-16
  
  本程序旨在使用Taichi-Servo库控制舵机运行速度
  This example code shows how to use Taichi-Servo lib to 
  control servo speed.
  
  舵机连接情况/Servo Arduino Connection
    5号引脚连接舵机 / myservo attached to pin 5
*/

#include "TaichiServo.h"

#define startPos 0   //舵机往复运动起始位置 / Start position of servo move back and forth
#define endPos  180   //舵机往复运动结束位置 / End position of servo move back and forth

//建立舵机对象 / Create a TaichiServo object
TaichiServo myservo; 

void setup() {
  myservo.attach(5);  //5号引脚连接舵机 / myservo attached to pin 5
  myservo.setTarget(endPos);   //初始设定舵机运动目标位置 / Setup myservo initial target  
}

void loop() {
  

  //控制舵机往复运动 / Servo moves back and forth
  if(myservo.getPosition() == endPos){  
    myservo.setServoSpeed(100);    //设置舵机运行速度为100
    myservo.setTarget(startPos);  
  } else if (myservo.getPosition() == startPos){
    myservo.setServoSpeed(10);   //设置舵机运行速度为10
    myservo.setTarget(endPos);
  }   
  
  //重要：servoUpdate函数用于更新舵运行状态，必须经常调用否则舵机无法正常运行!
  //IMPORTANT: servoUpdate MUST be called constantly or servo CANNOT work!   
  myservo.servoUpdate();
}
