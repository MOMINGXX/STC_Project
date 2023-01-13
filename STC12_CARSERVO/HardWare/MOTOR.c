#include "MOTOR.h"

uint8_t compare=80;

/****
	@brief      定时器初始化		500微秒@11.0592MHz
	@param   	无
	@return     无       	
	Sample usage:   Time0_Init();
****/
void Time0_Init()
{
	AUXR |= 0x80;			//定时器时钟1T模式
	TMOD &= 0xF0;			//设置定时器模式
	TMOD |= 0x01;			//设置定时器模式
	TL0 = 0x66;				//设置定时初始值
	TH0 = 0xEA;				//设置定时初始值
	TF0 = 0;				//清除TF0标志
	TR0 = 1;				//定时器0开始计时
	ET0 = 1;				//开启定时器中断
	EA = 1;					//开启总中断 
}

/****
    *@brief		加速
    *@param		无
    *@retval	无
*****/
void Motor_AddSpeed()
{
	compare+=10;
}

/****
    *@brief		减速
    *@param		无
    *@retval	无
*****/
void Motor_ReduceSpeed()
{
	compare-=10;
}

/****
	* @brief      电机初始化、定时器0初始化
	*			  舵机、蜂鸣器初始化
	* @param   	  无
	* @return     无       	
	Sample usage:    Motor_Init(); 
    */
void Motor_Init()
{
	Time0_Init();
	
	LEFT_MOTOR_STOP;
	RIGHT_MOTOR_STOP;
}

/****
	@brief      前进
	@param   	无
	@return     无       	
	Sample usage:    Motor_Ford(); 
****/
void Motor_ForWard()
{
	LEFT_MOTOR_GO;
	RIGHT_MOTOR_GO;
}

/****
	@brief      后退
	@param   	无
	@return     无       	
	Sample usage:    Motor_Back();        
****/
void Motor_Back()
{
	LEFT_MOTOR_BACK;
	RIGHT_MOTOR_BACK;
}

/****
    *@brief		左转
    *@param		无
    *@retval	无
	Sample usage:    Motor_Turnleft();  
*****/
void Motor_TurnLeft()
{
	LEFT_MOTOR_BACK;
	RIGHT_MOTOR_GO;
}

/****
    *@brief		右转
    *@param		无
    *@retval	无
	Sample usage:    Motor_Turnright();  
*****/
void Motor_TurnRight()
{
	LEFT_MOTOR_GO;
	RIGHT_MOTOR_BACK;
}

/****
    *@brief		停止
    *@param		无
    *@retval	无
	Sample usage:    Motor_Stop();  
*****/
void Motor_Stop()
{
	LEFT_MOTOR_STOP;
	RIGHT_MOTOR_STOP;
}

//定时器0中断
void Time0_Routine() interrupt 1
{
	static uint8_t count1=0; //电机计数标志
	static uint8_t count2=0; //舵机计数标志
	TL0 = 0x66;				//设置定时初始值
	TH0 = 0xEA;				//设置定时初始值
	//电机
	count1++;
	count1 %= 200;
	if(compare > count1)
	{
		EN1=EN2=1;
	}
	else 
	{
		EN1=EN2=0;
	}
		
	//舵机
	count2++;			//500us 记一次
	count2 %= 40;		//20ms 周期
	if(Servo_PWM > count2)
	{
		Servo=1;
	}
	else 
	{
		Servo=0;
	}
	
	//蜂鸣器
	if(Voice_Count != 0)
	{
		Voice_Count--;
		Beep = 0;
	}
	else
	{
		Beep = 1;
	}
}

	

