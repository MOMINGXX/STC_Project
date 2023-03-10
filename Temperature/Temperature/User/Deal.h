#ifndef	__Deal_H__
#define __Deal_H__

#include "DS18B20.h"
#include "EEPROM.h"
#include "UART.h"
#include <stdio.h>
#include "oled.h"
#include "DHT11.h"

void Deal_Init();
void OLED_DS18B20_Temp();
void OLED_DHT11_Temp();

#endif	/*__Deal_H__*/