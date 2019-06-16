#ifndef TAICHISERVO_H_
#define TAICHISERVO_H_
#include <Arduino.h>
#include <Servo.h>

#define DEFAULT_SERVO_DELAY 10

class TaichiServo: public Servo{
  public:
    TaichiServo(); //ctor
    TaichiServo(long usrServoDelay); //ctor2   
     
    void setTarget(int usrTarget);   //将用户输入的坐标位置作为目标位置进行设置
    int getTarget();                 //获取舵机目的位置
    int getDistanceToGo();           //获取舵机当前位置与目标舵机位置之间的差距
    int getPosition();               //获取舵机当前位置
    void servoUpdate();              //舵机动起来 
     
  private:
    int servoTarget;                  //舵机目标位置
    int servoPos; //舵机当前位置
    int distance2Go;
    int delayCouter;
    long delayTarget = DEFAULT_SERVO_DELAY;

};

#endif
