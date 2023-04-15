#ifndef __STC12_DELAY_H__
#define __STC12_DELAY_H__

#include <STC12C5A60S2.H>
#include <intrins.h>


#define SYS_CLK 24000000L

#ifndef SYS_CLK 
#define SYS_CLK 11059200L
#endif

//—”≥Ÿ1Œ¢√Î
void Delay1us();
//—”≥Ÿ5Œ¢√Î
void Delay5us();
//—”≥Ÿ10Œ¢√Î
void Delay10us();
//—”≥Ÿ15Œ¢√Î
void Delay15us();
//—”≥Ÿ50Œ¢√Î
void Delay50us();	
//—”≥Ÿ100Œ¢√Î
void Delay100us();	
//—”≥Ÿ1∫¡√Î
void Delay1ms();			
//—”≥Ÿtime∫¡√Î
void Delay(uint16_t time);	

#endif /*__STC12_DELAY_H__*/