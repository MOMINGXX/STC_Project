#include "MOTOR_HANDLER.h"

void main()
{
	Motor_Init();
	Ultrasonic_Init();
	Uart_Init(UART_1,GPIORX_P30,GPIOTX_P31,9600,TIM_BRT);
	ES = 1;
	IT0 = 1;
	EX0 = 1;
	//IE2 |= 0x01;
	EA = 1;		//定时器中已开启
	Voice_Count = 100;
	while(1)
	{
		Auto_Hand_Mode();
	}
}

