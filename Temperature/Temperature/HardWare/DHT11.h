#ifndef __DHT11_H__
#define __DHT11_H__

#include <STC12C5A60S2.H>
#include "STC12_DELAY.h"

sbit DHT11_PIN = P2^3;

void DHT11_Init();
uint8_t DHT11_Read_Bit();
uint8_t DHT11_Read_Byte();
void DHT11_Read_Data(uint8_t *TempH,uint8_t *TempL,uint8_t *HumiH,uint8_t *HumiL);

#endif /*__DHT11_H__*/