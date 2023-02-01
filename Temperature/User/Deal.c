#include "Deal.h"

float T;
uint8_t TempH,TempL,HumiH,HumiL;

void Deal_Init()
{
    Uart_Init(UART_1,GPIORX_P30,GPIOTX_P31,9600,TIM_BRT);	
	
	DHT11_Init();

	OLED_Init();
	OLED_Clear();
	OLED_ShowString(1,0,"Temp Humi Test!",16);
}

void OLED_DS18B20_Temp()
{
	OLED_ShowCHinese(1,2,11);
	OLED_ShowCHinese(16,2,12);
	OLED_ShowChar(32,3,':',2);	
	
	OLED_ShowCHinese(108,2,14);
	
	DS18B20_ConvertT();
	T=DS18B20_ReadT();
	//printf("\r\nwd:>%f\n",T);
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
	
    DHT11_Read_Data(&TempH,&TempL,&HumiH,&HumiL);	
	
	/*
	printf("Tem:%d ¡æ\r\n", (int)TempH);
	printf("Tem:%d ¡æ\r\n", (int)TempL);
    printf("Hum:%d %%H\r\n", (int)HumiH);
    printf("Hum:%d %%H\r\n", (int)HumiL);
    */
	
	OLED_ShowChar(47,6,'0'+(TempH/10),16);
	OLED_ShowChar(55,6,'0'+(TempH%10),16);
	OLED_ShowChar(72,6,'0'+(TempL/10),16);
	OLED_ShowChar(80,6,'0'+(TempL%10),16);	
	OLED_ShowCHinese(1,6,11);
	OLED_ShowCHinese(16,6,12);
	OLED_ShowChar(32,7,':',2);	
	OLED_ShowChar(64,7,'.',2);
	OLED_ShowCHinese(92,6,14);
	
	OLED_ShowChar(47,4,'0'+(HumiH/10),16);
	OLED_ShowChar(55,4,'0'+(HumiH%10),16);
	OLED_ShowChar(72,4,'0'+(HumiL/10),16);
	OLED_ShowChar(80,4,'0'+(HumiL%10),16);
	OLED_ShowCHinese(1,4,13);
	OLED_ShowCHinese(16,4,12);
	OLED_ShowChar(32,5,':',2);	
	OLED_ShowChar(64,5,'.',2);
	OLED_ShowString(92,4,"%RH",16);
}
