#include "UART.h"

uint8_t DAT1;				//存放接收的字符
uint8_t RX1_BUFF[DATA_MAX];		//接收的数据	缓冲区
uint8_t RX1_DAT[DATA_MAX];			//存放接收的数据
uint8_t RX1_COUNT=0;			//接收计数
bit Flag1 = 0;				//标志位

uint8_t DAT2;				//存放接收的字符
uint8_t RX2_BUFF[DATA_MAX];		//接收的数据	缓冲区
uint8_t RX2_DAT[DATA_MAX];			//存放接收的数据
uint8_t RX2_COUNT=0;			//接收计数
bit Flag2 = 0;				//标志位


/****
	@brief      串口初始化
	@param   	Uart_n			串口号  USART_1,USART_2
	@param		GPIORX_Pin		接收I/O口	P30 P12 P42
	@param		GPIOTX_Pin		发送I/O口	P31 P13 P43
	@param		baud			波特率	115200 57600 9600 4800 2400
	@param		Tim_n			波特率发生器
	@return     无        	
	Sample usage:  Uart_Init(UART_1,GPIORX_P30,GPIOTX_P31,9600,Tim_1);             
	@note    若需波特率加倍 则将	#define SMOD 0	-->  #define SMOD 1
****/
void Uart_Init(UART_NAME Uart_n,GPIO_PIN GPIORX_Pin,GPIO_PIN GPIOTX_Pin,uint16_t baud,UART_TIM Tim_n)	
{
	switch(Uart_n)
	{		
		case UART_1:
		{
			SCON = 0x50;		//8位数据,可变波特率
			#if SMOD == 0
			PCON &= 0x7F;		//波特率不倍速
			#elif SMOD == 1
			PCON |= 0x80;		//使能波特率倍速位SMOD
			#endif
			if(TIM_1 == Tim_n)
			{
				AUXR |= 0x40;		//定时器时钟1T模式
				AUXR &= 0xFE;		//串口1选择定时器1为波特率发生器
				TMOD &= 0x0F;		//设置定时器模式
				TMOD |= 0x20;		//设置定时器模式
				#if SMOD == 1
				TL1 = TH1 = -(2*SYS_CLK/32/baud);		//设置定时器初始值与重载值
				#elif SMOD == 0
				TL1 = TH1 = -(SYS_CLK/32/baud);		//设置定时器初始值与重载值
				#endif
				
				#ifndef OPEN_EA
				ET1 = 0;			//禁止定时器中断
				TR1 = 1;			//定时器1开始计时
				#endif
			}
			else if(TIM_BRT == Tim_n)
			{
				#if SMOD == 1
				BRT = -(2*SYS_CLK/32/baud);			//设置定时重载值
				#elif SMOD == 0
				BRT = -(SYS_CLK/32/baud);			//设置定时重载值
				#endif
				AUXR |= 0x04;		//定时器时钟1T模式
				AUXR |= 0x01;		//串口1使用独立波特率发射器为波特率发生器
				AUXR |= 0x10;		//启动独立波特率发射器
			}
			if(GPIORX_P30 == GPIORX_Pin && GPIOTX_P31 == GPIOTX_Pin)
			{
				//P30双向IO口
				P3M1 &= ~0x01;	
				P3M0 &= ~0x01;
				//P31双向IO口
				P3M1 &= ~0x02;
				P3M0 &= ~0x02;
			}
			break;
		}
		case UART_2:
		{
			#if SMOD == 1
			AUXR |= 0x08;		//使能波特率倍速位S2SMOD
			BRT = -(2*SYS_CLK/32/baud);			//设置定时重载值
			#elif SMOD == 0
			AUXR &= 0xF7;		//波特率不倍速
			BRT = -(SYS_CLK/32/baud);			//设置定时重载值
			#endif
			S2CON = 0x50;		//8位数据,可变波特率
			AUXR |= 0x04;		//定时器时钟1T模式
			AUXR |= 0x10;		//启动独立波特率发射器
			if(GPIORX_P12 == GPIORX_Pin && GPIOTX_P13 == GPIOTX_Pin)
			{
				//P12双向IO口
				P1M1 &= ~0x40;
				P1M0 &= ~0x40;
				
				//P13双向IO口
				P1M1 &= ~0x80;
				P1M0 &= ~0x80;
				AUXR1 &= ~0x10;
			}
			else if(GPIORX_P42 == GPIORX_Pin && GPIOTX_P43 == GPIOTX_Pin)
			{
				//P42双向IO口
				P4M1 &= ~0x40;
				P4M0 &= ~0x40;
				
				//P43双向IO口
				P4M1 &= ~0x80;
				P4M0 &= ~0x80;
				AUXR1 |= 0x10;
			}
			break;
		}
	}
}

/****
	@brief      串口发送一个字节
	@param   	uart_n          串口号  USART_1,USART_2
	@param     Byte  			要发送的字节    
	@return     无
	Sample usage:    Uart_SendByte(UART_1,'p');  
****/
void Uart_SendByte(UART_NAME Uart_n,uint8_t Byte)
{
	switch(Uart_n)
	{
		case UART_1:
		{
			SBUF=Byte;
			while (UART1_GET_TX_FLAG == 0);
			UART1_CLEAR_TX_FLAG;
		}
			break;
		case UART_2:
		{
			S2BUF=Byte;
			while(UART2_GET_TX_FLAG==0);
			UART2_CLEAR_TX_FLAG;
		}
			break;
	}
}

/****
	@brief      串口发送一个字符串 
	@param   	uart_n          串口号  USART_1,USART_2
	@param   	String			要发送的字符串 
	@return     无        	
	Sample usage:     Uart_SendString(UART_1,"ABCD");    
****/
void Uart_SendString(UART_NAME Uart_n,uint8_t *String)
{
	while(*String != '\0')
	{
		Uart_SendByte(Uart_n,*String++);
	}
}

/****
	@brief      串口发送数组
	@param   	uart_n          串口号  USART_1,USART_2
	@param   	Buff			要发送的数组 
	@param   	Len				数组长度
	@return     无        	
	Sample usage:     Uart_SendString(UART_1,arr,sizeof(arr)/sizeof(arr[0]));    
****/
void Uart_SendBuff(UART_NAME Uart_n,uint8_t *Buff,uint16_t Len)
{
	while(Len--)
	{
		Uart_SendByte(Uart_n,*Buff++);
	}
}

/****
	@brief      printf打印
	@param   	c
	@return     c        	
	Sample usage:  printf("Hello\n"); 
****/
#if (PRINTF_SELECT == 1)
uint8_t putchar(uint8_t c)
{
	if(c == '\n')
	{
		Uart_SendByte(UART_1,0x0D);
	}
	Uart_SendByte(UART_1,c);
	return c;
}

#elif (PRINTF_SELECT == 2)
uint8_t putchar(uint8_t c)
{
	if(c == '\n')
	{
		Uart_SendByte(UART_1,0x0D);
	}
	Uart_SendByte(UART_1,c);
	return c;
}
#endif

/*
//不换行
#if (PRINTF_SELECT == 1)
char putchar(char c)
{
	Uart_SendByte(UART_1,c);
	return c;
}

#elif (PRINTF_SELECT == 2)
char putchar(char c)
{
	Uart_SendByte(UART_1,c);
	return c;
}
#endif
*/

//串口1中断接收数据
#if (UART_ROUTINE_SELECT == 1)
void Uart1_Routine() interrupt 4
{
	static uint8_t i=0;
	if(UART1_GET_RX_FLAG)
	{
		UART1_CLEAR_RX_FLAG;
		DAT1 = SBUF;
		if(DAT1 != '#')				//'#'结束标志
		{
			RX1_BUFF[RX1_COUNT++] = DAT1++;
		}
		else
		{
			for(i=0;i<RX1_COUNT;i++)
			{
				RX1_DAT[i] = RX1_BUFF[i];
			}
			RX1_COUNT=0;
			Flag1=1;
		}
	}
}

//串口2中断接收数据
#elif (UART_ROUTINE_SELECT == 2)
void Uart1_Routine() interrupt 8
{
	static uint8_t i=0;
	if(UART2_GET_RX_FLAG)
	{
		UART2_CLEAR_RX_FLAG;
		DAT2 = S2BUF;
		if(DAT2 != '#')				//'#'结束标志
		{
			RX2_BUFF[RX2_COUNT++] = DAT2++;
		}
		else
		{
			for(i=0;i<RX2_COUNT;i++)
			{
				RX2_DAT[i] = RX2_BUFF[i];
			}
			RX2_COUNT=0;
			Flag2=1;
		}
	}
}
#endif
