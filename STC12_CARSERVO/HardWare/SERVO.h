#ifndef  __DuoJi_H__
#define  __DuoJi_H__

#include <STC12C5A60S2.H>

//定义舵机IO端口
sbit Servo=P2^6;

extern uint8_t Servo_PWM;//舵机的角度控制/1 0   2 45   3 90   4 135   5 180

#endif