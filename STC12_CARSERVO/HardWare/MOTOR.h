#ifndef	__MOTOR_H__
#define __MOTOR_H__

//#include <STC12C5A60S2.H>
#include "Servo.h"
#include "BEEP.h"

#define FORWARD 		("FORWARD")
#define BACK 			("BACK")
#define TURNLEFT		("LEFT")
#define TURNRIGHT		("RIGHT")
#define STOP			("STOP")
#define REDUCESPEED		("REDUCE")
#define ADDSPEED 		("ADD")

//定义驱动器输出端引脚
sbit LEFT_IN1 =P1^2;
sbit LEFT_IN2 =P1^3;
sbit RIGHT_IN3=P1^4;
sbit RIGHT_IN4=P1^5;

#define LEFT_MOTOR_GO     	 	{LEFT_IN1=1,LEFT_IN2=0;}  	//左电机向前转
#define LEFT_MOTOR_BACK   	 	{LEFT_IN1=0,LEFT_IN2=1;} 		//左电机向后转
#define LEFT_MOTOR_STOP			{LEFT_IN1=0,LEFT_IN2=0;}      //左电机停转                     
#define RIGHT_MOTOR_GO    		{RIGHT_IN3=1,RIGHT_IN4=0;}		//右电机向前转
#define RIGHT_MOTOR_BACK   		{RIGHT_IN3=0,RIGHT_IN4=1;}		//右电机向后转
#define RIGHT_MOTOR_STOP   		{RIGHT_IN3=0,RIGHT_IN4=0;}      //右电机停转 

//定义驱动器使能端引脚
sbit EN1=P1^6;
sbit EN2=P1^7;

extern uint8_t compare;

//减速
void Motor_ReduceSpeed();
//加速
void Motor_AddSpeed();
//初始化
void Motor_Init();
//前进
void Motor_ForWard();
//后退
void Motor_Back();
//左转
void Motor_TurnLeft();
//右转
void Motor_TurnRight();
//停止
void Motor_Stop();


#endif