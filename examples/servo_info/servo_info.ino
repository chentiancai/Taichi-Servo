/*
  servo_info
  by Taichi-Maker
  www.taichi-maker.com
  2019-06-15
  
  本程序旨在使用Taichi-Servo库获取舵机的运行状态
  This example code shows how to use Taichi-Servo lib to 
  get servo operation status.
  
  舵机连接情况/Servo Arduino Connection
    5号引脚连接舵机 / myservo attached to pin 5
*/

#include <TaichiServo.h>

#define startPos 45   //舵机往复运动起始位置 / Start position of servo move back and forth
#define endPos  135   //舵机往复运动结束位置 / End position of servo move back and forth
#define servoSpeed 100 //舵机运行速度 / Servo Speed

//建立舵机对象并设置运行速度 / Create a TaichiServo object and set its speed.
TaichiServo myservo(servoSpeed); 

void setup() {
  Serial.begin(9600); // 启动串口通讯 / Begin Serial Communication
  myservo.attach(5);  //5号引脚连接舵机 / myservo attached to pin 5
  myservo.setTarget(endPos);   //初始设定舵机运动目标位置 / Setup myservo initial target  
  
  // 获取myservo目标位置 / Get myservo's target position.
  int servoTarget = myservo.getTarget(); 
  
  // 通过串口监视器输出舵机目标位置 / Show servoTarget via Serial Monitor.
  Serial.print("servoTarget is "); Serial.println(servoTarget);

  // 获取myservo当前位置 / Get myservo's current position.
  int servoCurrentPos = myservo.getPosition(); 
  
  // 通过串口监视器输出舵机目标位置 / Show servoTarget via Serial Monitor.
  Serial.print("servoCurrentPos is "); Serial.println(servoCurrentPos);
  
  // 获取myservo当前位置与目标位置的距离 
  // Get myservo's distance between current position and target position.
  int servoDistanceToGo = myservo.getDistanceToGo();
  
  // 通过串口监视器输出舵机目标位置 / Show servoTarget via Serial Monitor.
  Serial.print("servoDistanceToGo is "); Serial.println(servoDistanceToGo);  
}

void loop() {


  if(myservo.getPosition() == endPos){    
    myservo.setTarget(startPos);    
  } else if (myservo.getPosition() == startPos){
    myservo.setTarget(endPos);
  }  


   
  //重要：servoUpdate函数用于更新舵运行状态，必须经常调用否则舵机无法正常运行!
  //IMPORTANT: servoUpdate MUST be called constantly or servo CANNOT work!
  myservo.servoUpdate();  
}
