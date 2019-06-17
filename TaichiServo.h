#ifndef TAICHISERVO_H_
#define TAICHISERVO_H_
#include <Arduino.h>
#include <Servo.h>

#define DEFAULT_SERVO_SPEED 10

class TaichiServo: public Servo{
  public:
    TaichiServo();                      //无速度参数的构造函数 / ctor of no speed parameter
    TaichiServo(long usrServoDelay);    //带有速度参数的构造函数 / ctor with speed parameter
     
    void setTarget(int usrTarget);          //将用户输入的坐标位置作为目标位置 / set servo's target pos
    int getTarget();                        //获取舵机目的位置 / get servo target pos
    int getPosition();                      //获取舵机当前位置 / get servo current position
    int setServoSpeed(int usrServoSpeed);   //设置舵机速度 / set servo speed
    void servoUpdate();                     //舵机动起来 / make servo move
    int getDistanceToGo();                  //获取舵机当前位置与目标舵机位置之间的差距 
                                            // get the distance between target and current position     
  private:
    int servoTarget;                  //舵机目标位置
    int servoPos;                     //舵机当前位置
    int distance2Go;                  //舵机当前位置与目标舵机位置之间的差距
                                      //distance between current and target pos
    int delayCouter;                  //控制舵机速度用计数器 / counter used to control servo speed
    int servoSpeed = DEFAULT_SERVO_SPEED;  //舵机速度参数 / speed control parameter
};

#endif
