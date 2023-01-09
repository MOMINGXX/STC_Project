#ifndef __UART_H__
#define __UART_H__

#include <STC12C5A60S2.H>

#define SYS_CLK 11059200L	//系统频率设置

#if !defined(SYS_CLK)
#define SYS_CLK 24000000L
#endif

#define SMOD 0		

#define UART1	1
#define UART2	2

#define	PRINTF_SELECT 		 UART1		//选择 printf 函数所使用的串口，参数 UART1~UART2

#define	UART_ROUTINE_SELECT  UART1		//选择 串口中断 函数所使用的串口，参数 UART1~UART2

#define	UART1_CLEAR_RX_FLAG (SCON  &= ~0x01)
#define	UART2_CLEAR_RX_FLAG (S2CON &= ~0x01)

#define	UART1_CLEAR_TX_FLAG (SCON  &= ~0x02)
#define	UART2_CLEAR_TX_FLAG (S2CON &= ~0x02)

#define UART1_GET_RX_FLAG   (SCON  & 0x01)
#define UART2_GET_RX_FLAG   (S2CON & 0x01)

#define UART1_GET_TX_FLAG   (SCON  & 0x02)
#define UART2_GET_TX_FLAG   (S2CON & 0x02)

extern uint8_t RX1_DAT[10];
extern bit Flag1;

extern uint8_t RX2_DAT[10];
extern bit Flag2;

typedef enum
{
	UART_1,
	UART_2,
}UART_NAME;

typedef enum
{
	TIM_BRT,
	TIM_1,
}UART_TIM;

typedef enum
{
	GPIORX_P30,GPIOTX_P31,
	GPIORX_P12,GPIOTX_P13,
	GPIORX_P42,GPIOTX_P43,
}GPIO_PIN;

void Uart_SendByte(UART_NAME Uart_n,uint8_t Byte);
void Uart_SendString(UART_NAME Uart_n,uint8_t *String);
void Uart_SendBuff(UART_NAME Uart_n,uint8_t *Buff,uint16_t Len);
void Uart_Init(UART_NAME Uart_n,GPIO_PIN GPIORX_Pin,GPIO_PIN GPIOTX_Pin,uint16_t baud,UART_TIM Tim_n);

#endif
