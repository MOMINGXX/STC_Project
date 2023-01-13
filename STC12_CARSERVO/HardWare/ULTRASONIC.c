#include "ULTRASONIC.h"

uint16_t Distance = 0;

/****
	* @brief	定时器1初始化      //11.0592MHz		  
	* @param   	无
	* @return   无    	
	* Sample usage:Timer0_Init();
	* @note 
    */
void Timer1_Init()		
{
	AUXR |= 0x40;			//定时器时钟1T模式
	TMOD &= 0x0F;			//设置定时器模式
	TMOD |= 0x10;			//设置定时器模式
	TL1 = 0;				//设置定时初始值
	TH1 = 0;				//设置定时初始值
	TF1 = 0;				//清除TF1标志
	TR1 = 1;				//定时器1开始计时
}

/****
	* @brief	超声波初始化      			  
	* @param   	无
	* @return   无    	
	* Sample usage:Ultrasonic_Init();
	* @note 
    */
void Ultrasonic_Init()
{
	Trig = 0;
	Echo = 0;
	Timer1_Init();	
}

/****
	* @brief	开启超声波     			  
	* @param   	无
	* @return   无    	
	* Sample usage:Ultrasonic_Start();
	* @note 
    */
static void Ultrasonic_Start()
{
	Trig = 0;
	_nop_();
	Trig = 1;
	Delay10us();
	Trig = 0;
}

/****
	* @brief	超声波距离计算		  
	* @param   	无
	* @return   无    	
	* Sample usage:Ultrasonic_GetDistance();
    */
uint16_t Ultrasonic_GetDistance()
{
	uint16_t Time = 0;
	
	Ultrasonic_Start();
	Echo = 1;
	while(!Echo);		//等待低电平结束
	TR1 = 1;
	while(Echo);		//等待高电平结束
	TR1 = 0;
	
	Time = TH1*256+TL1;
	TH1=0;
	TL1=0;
	//Time = Time * (12/24);
	
	Distance = Time *1.7/100;		//距离计算  mm
	return Distance;
}

