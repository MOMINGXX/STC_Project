#ifndef	__Deal_H__
#define __Deal_H__

#include "DS18B20.h"
#include "EEPROM.h"
#include "UART.h"
#include <stdio.h>
#include "KEY.h"
#include "oled.h"
#include "DHT11.h"
#include "CRC16.h"

typedef enum 
{
    TEMPH_ADD = 4,
    TEMPH_RED,
    TEMPL_ADD,
    TEMPL_RED,
}Alert_InitTepedf;

void Deal_Init();
void Key_Scan();
void Temp_Alarm();
void OLED_DS18B20_Temp(uint8_t x);
void OLED_DHT11_Temp();
void OLED_Alert_Temp();
void Alert_Temp_Set();

#endif	/*__Deal_H__*/