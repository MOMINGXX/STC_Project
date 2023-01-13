#ifndef	__BEEP_H__
#define __BEEP_H__

#include <STC12C5A60S2.H>

sbit Beep=P2^3;

extern uint16_t Voice_Count;

#endif /*__BEEP_H__*/