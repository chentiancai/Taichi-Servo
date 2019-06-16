/*
  three_Servos
  by Taichi-Maker
  www.taichi-maker.com
  2019-06-15
  
  本程序旨在使用Taichi-Servo库让3个舵机同时往复运动
  This example code shows how to use Taichi-Servo lib to 
  control three servos move simultaneously.
  
  舵机连接情况/Servo Arduino Connection
    3号引脚连接舵机1 / myservo1 attached to pin 3
    4号引脚连接舵机2 / myservo2 attached to pin 4
    5号引脚连接舵机3 / myservo3 attached to pin 5
*/

#include <TaichiServo.h>

#define startPos 45   //舵机往复运动起始位置 / Start position of servo move back and forth
#define endPos  135   //舵机往复运动结束位置 / End position of servo move back and forth
#define servoSpeed 50 //舵机运行速度 / Servo Speed

TaichiServo myservo1(servoSpeed);  //建立舵机对象1
TaichiServo myservo2(servoSpeed);  //建立舵机对象2
TaichiServo myservo3(servoSpeed);  //建立舵机对象3

void setup() {
  Serial.begin(9600);
  myservo1.attach(3);   //3号引脚连接舵机1 / myservo1 attached to pin 3
  myservo2.attach(4);   //4号引脚连接舵机2 / myservo2 attached to pin 4
  myservo3.attach(5);   //5号引脚连接舵机3 / myservo3 attached to pin 5
  
  myservo1.setTarget(endPos);   //初始设定舵机1运动目标位置 / myservo1 initial target
  myservo2.setTarget(endPos);   //初始设定舵机2运动目标位置 / myservo2 initial target
  myservo3.setTarget(endPos);   //初始设定舵机3运动目标位置 / myservo3 initial target  
}

void loop() {
  //舵机1往复运动 / myservo1 moves back and forth
  if(myservo1.getPosition() == endPos){
    myservo1.setTarget(startPos);
  } else if (myservo1.getPosition() == startPos){
    myservo1.setTarget(endPos);
  }   
  
  //舵机2往复运动 / myservo2 moves back and forth
  if(myservo2.getPosition() == endPos){
    myservo2.setTarget(startPos);
  } else if (myservo2.getPosition() == startPos){
    myservo2.setTarget(endPos);
  }    
   
  //舵机3往复运动 / myservo3 moves back and forth
  if(myservo3.getPosition() == endPos){
    myservo3.setTarget(startPos);
  } else if (myservo3.getPosition() == startPos){
    myservo3.setTarget(endPos);
  }  

  //重要：servoUpdate函数用于更新舵运行状态，必须经常调用否则舵机无法正常运行!
  //IMPORTANT: servoUpdate MUST be called constantly or servo CANNOT work!      
  myservo1.servoUpdate();
  myservo2.servoUpdate();
  myservo3.servoUpdate();  
}
