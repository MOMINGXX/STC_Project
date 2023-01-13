#ifndef __ULTRASONIC_H__
#define __ULTRASONIC_H__

#include "STC12_DELAY.h"

sbit Trig = P3^4;         //³¬Éù²¨Ä£¿é´¥·¢¶Ë
sbit Echo = P3^5;         //³¬Éù²¨Ä£¿é»ØÏì¶Ë

//extern uint16_t Distance;

void Ultrasonic_Init();
uint16_t Ultrasonic_GetDistance();

#endif /*__ULTRASONIC_H__*/