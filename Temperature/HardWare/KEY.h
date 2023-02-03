#ifndef  _KEY_H_
#define	 _KEY_H_

#include <STC12C5A60S2.H>

sbit Key1 = P0^0;
sbit Key2 = P0^1;
sbit Key3 = P0^2;
sbit Key4 = P0^3;
sbit Key5 = P0^4;
sbit Key6 = P0^5;
sbit Key7 = P0^6;
sbit Key8 = P0^7;

void Key_Loop();
void Timer0_Init();
unsigned char key();
unsigned char key_GetState();

#endif