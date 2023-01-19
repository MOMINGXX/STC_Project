#include "MP3_TF_16P.h"

void main()
{
	Uart_Init(UART_1,GPIORX_P30,GPIOTX_P31,9600,TIM_BRT);	
	Uart_SendCMD(Specify_Volume,0x00,20);
	Uart_SendFolder(Specify_Folder,0x00,2,6);
	while(1)
	{
		
	}
}

