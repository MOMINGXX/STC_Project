#ifndef __DHT11_H__
#define __DHT11_H__

#include <STC12C5A60S2.H>
#include "STC12_DELAY.h"

sbit DHT11_PIN = P2^0;

void DHT11_Init();
uint8_t DHT11_Read_Bit();
uint8_t DHT11_Read_Byte();
uint8_t DHT11_Read_Data(uint8_t *Data);

#endif /*__DHT11_H__*/