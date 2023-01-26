#include "LD3320.h"

void main()
{
	Uart_Init(UART_1,GPIORX_P30,GPIOTX_P31,9600,TIM_BRT);	
	ES = 1;
	EA = 1;
	Uart_SendCMD(Specify_Volume,0x00,20);
	while(1)
	{
		MP3_Play();
	}
}

