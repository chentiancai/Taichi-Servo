/*
  basic
  by Taichi-Maker
  www.taichi-maker.com
  2019-06-15
  
  本程序旨在使用Taichi-Servo库控制舵机往复运动
  This example code shows how to use Taichi-Servo lib to 
  control servo.
  
  舵机连接情况/Servo Arduino Connection
    5号引脚连接舵机 / myservo attached to pin 5
*/

#include <TaichiServo.h>

#define startPos 45   //舵机往复运动起始位置 / Start position of servo move back and forth
#define endPos  135   //舵机往复运动结束位置 / End position of servo move back and forth
#define servoSpeed 50 //舵机运行速度 / Servo Speed

//建立舵机对象并设置运行速度 / Create a TaichiServo object and set its speed.
TaichiServo myservo(servoSpeed); 

void setup() {
  myservo.attach(5);  //5号引脚连接舵机 / myservo attached to pin 5
  myservo.setTarget(endPos);   //初始设定舵机运动目标位置 / Setup myservo initial target  
}

void loop() {
  if(myservo.getPosition() == endPos){    
    myservo.setTarget(startPos);  
  } else if (myservo.getPosition() == startPos){
    myservo.setTarget(endPos);
  }   
   
  myservo.servoUpdate();
}
