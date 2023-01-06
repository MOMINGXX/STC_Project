#include "UART.h"
#include "MOTOR.h"
//#include <stdio.h>
#include <string.h>

//char arr[]={0x10,0x12,0x03,0x04,6,7,5};

void Voice_Mode();

void main()
{
	Uart_Init(UART_1,GPIORX_P30,GPIOTX_P31,9600,TIM_1);
	ES = 1;
	//IE2 |= 0x01;
	EA = 1;
	while(1)
	{
		
		Voice_Mode();
		/* test
		if(NULL != strstr(RX_DAT,"FORWARD"))
			P1=0;
		Uart_SendByte(UART_1,'p');
		Uart_SendString(UART_1,"ABCD");  
		Uart_SendBuff(UART_1,&arr,7);
		printf("Hello\n");
		*/
	}
}

void Voice_Mode()
{
	if(Flag1==1)
	{
		if(strstr(RX1_DAT,FORWARD) != NULL)
		{
			Motor_ForWard();
			//P2=0x0f;
			Uart_SendString(UART_1,RX1_DAT);  
		}
		else if(strstr(RX1_DAT,BACK) != NULL)
		{
			Motor_Back();
			//P2=0xf0;
			Uart_SendString(UART_1,RX1_DAT);  
		}
		else if(strstr(RX1_DAT,TURNLEFT) != NULL)
		{
			Motor_TurnLeft();
			Uart_SendString(UART_1,RX1_DAT);  
		}
		else if(strstr(RX1_DAT,TURNRIGHT) != NULL)
		{
			Motor_Turnright();
			Uart_SendString(UART_1,RX1_DAT);  
		}
		else if(strstr(RX1_DAT,STOP) != NULL)
		{
			Motor_Stop();
			Uart_SendString(UART_1,RX1_DAT);  
		}
		else if(strstr(RX1_DAT,REDUCESPEED	) != NULL)
		{
			Motor_ReduceSpeed();
			Uart_SendString(UART_1,RX1_DAT);  
		}
		else if(strstr(RX1_DAT,ADDSPEED ) != NULL)
		{
			Motor_AddSpeed();
			Uart_SendString(UART_1,RX1_DAT);  
		}
		Flag1=0;
	}
}