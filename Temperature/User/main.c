#include "DS18B20.h"
#include "UART.h"
#include <stdio.h>
#include "oled.h"
#include "DHT11.h"

float T;
uint8_t TempBuff[5];

void OLED_DS18B20_Temp();
void OLED_DHT11_Temp();

void main()
{
	Uart_Init(UART_1,GPIORX_P30,GPIOTX_P31,9600,TIM_BRT);	
	
	DHT11_Init();

	OLED_Init();
	OLED_Clear();
	OLED_ShowString(1,0,"Temp Humi Test!",16);
	
	while(1)
	{
		OLED_DS18B20_Temp();
		OLED_DHT11_Temp();
	}
}

void OLED_DS18B20_Temp()
{
	OLED_ShowCHinese(1,2,11);
	OLED_ShowCHinese(16,2,12);
	OLED_ShowChar(32,3,':',2);	
	
	OLED_ShowCHinese(108,2,14);
	
	DS18B20_ConvertT();
	T=DS18B20_ReadT();
	printf("\r\nwd:>%f\n",T);
	if(T<0)
	{
		OLED_ShowChar(74,3,'.',2);
		OLED_ShowChar(43,2,'-',16);
		OLED_ShowNum(49,2,T,3,16);
		OLED_ShowNum(82,2,(uint32_t)(T*10000)%10000,3,16);
	}
	else OLED_ShowChar(64,3,'.',2);
	OLED_ShowNum(39,2,T,3,16);
	OLED_ShowNum(72,2,(uint32_t)(T*10000)%10000,4,16);
}

void OLED_DHT11_Temp()
{
	DHT11_Read_Data(TempBuff);	
	printf("\r\nwdd:>%d\r\n",'0'+(TempBuff[2]/10));
	printf("%d\r\n",'0'+(TempBuff[2]%10));
	printf("%d\r\n",'0'+(TempBuff[3]/10));
	printf("%d\r\n",'0'+(TempBuff[3]%10));

	printf("\r\nsd:> %d\r\n",'0'+(TempBuff[0]/10));
	printf("%d\r\n",'0'+(TempBuff[0]%10));
	printf("%d\r\n",'0'+(TempBuff[1]/10));
	printf("%d\r\n",'0'+(TempBuff[1]%10));
	
	OLED_ShowChar(47,6,'0'+(TempBuff[2]/10),16);
	OLED_ShowChar(55,6,'0'+(TempBuff[2]%10),16);
	OLED_ShowChar(72,6,'0'+(TempBuff[3]/10),16);
	OLED_ShowChar(80,6,'0'+(TempBuff[3]%10),16);	
	OLED_ShowCHinese(1,6,11);
	OLED_ShowCHinese(16,6,12);
	OLED_ShowChar(32,7,':',2);	
	OLED_ShowChar(64,7,'.',2);
	OLED_ShowCHinese(92,6,14);
	
	OLED_ShowChar(47,4,'0'+(TempBuff[0]/10),16);
	OLED_ShowChar(55,4,'0'+(TempBuff[0]%10),16);
	OLED_ShowChar(72,4,'0'+(TempBuff[1]/10),16);
	OLED_ShowChar(80,4,'0'+(TempBuff[1]%10),16);
	OLED_ShowCHinese(1,4,13);
	OLED_ShowCHinese(16,4,12);
	OLED_ShowChar(32,5,':',2);	
	OLED_ShowChar(64,5,'.',2);
	OLED_ShowString(92,4,"%RH",16);
}
/*
void OLED_DHT11_Temp()
{
	DHT11_Read_Data(&tempH,&tempL,&humiH,&humiL);	
	
	printf("\r\nwdd:>%d\r\n",'0'+(tempH/10));
	printf("%d\r\n",'0'+(tempH/10));
	printf("%d\r\n",'0'+(tempH/10));
	printf("%d\r\n",'0'+(tempH/10));

	printf("\r\nsd:> %d\r\n",'0'+(humiH/10));
	printf("%d\r\n",'0'+(humiH/10));
	printf("%d\r\n",'0'+(humiH/10));
	printf("%d\r\n",'0'+(humiH/10));
	
	OLED_ShowChar(47,6,'0'+(tempH/10),16);
	OLED_ShowChar(55,6,'0'+(tempH%10),16);
	OLED_ShowChar(72,6,'0'+(tempL/10),16);
	OLED_ShowChar(80,6,'0'+(tempL%10),16);	
	OLED_ShowCHinese(1,6,11);
	OLED_ShowCHinese(16,6,12);
	OLED_ShowChar(32,7,':',2);	
	OLED_ShowChar(64,7,'.',2);
	OLED_ShowCHinese(92,6,14);
	
	OLED_ShowChar(47,4,'0'+(humiH/10),16);
	OLED_ShowChar(55,4,'0'+(humiH%10),16);
	OLED_ShowChar(72,4,'0'+(humiL/10),16);
	OLED_ShowChar(80,4,'0'+(humiL%10),16);
	OLED_ShowCHinese(1,4,13);
	OLED_ShowCHinese(16,4,12);
	OLED_ShowChar(32,5,':',2);	
	OLED_ShowChar(64,5,'.',2);
	OLED_ShowString(92,4,"%RH",16);
}*/