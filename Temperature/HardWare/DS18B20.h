#ifndef __DS15B20_H__
#define __DS15B20_H__

#include <STC12C5A60S2.H>
#include <intrins.h>
#include "STC12_DELAY.h"

sbit DS18B20_PIN = P1^1;

#define DS18B20_CONVERT_T 		0x44
#define DS18B20_SKIP_ROM 		0xCC
#define DS18B20_READ_SCRATCHPAD	0xBE

void DS18B20_Init();
uint8_t DS18B20_ReadBit();
float DS18B20_ReadT();
void DS18B20_ConvertT();
uint8_t DS18B20_ReadByte();
uint8_t DS18B20_ReadBit();
void DS18B20_WriteBit(uint8_t Bit);
void DS18B20_WriteByte(uint8_t Byte);

#endif  /*__DS15B20_H__*/