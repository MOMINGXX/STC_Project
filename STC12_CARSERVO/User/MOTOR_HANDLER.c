#include "MOTOR_HANDLER.h"

uint8_t Auto_Hand_Mode_Flag=1;	//自动手动模式切换标志(默认蓝牙模式)

uint16_t Distance_Middle = 0;	//中间距离
uint16_t Distance_Left = 0;		//左侧距离
uint16_t Distance_Right = 0;	//右侧距离

/****
	* @brief	蓝牙...模式		不局限与蓝牙模块使用
	* @param   	无
	* @return   无    	
	* Sample usage:MOTOR_Blue_Mode();
	* @note 
    */
void MOTOR_Blue_Mode()
{
	if(Flag1 == 1)
	{
		if(strstr(RX1_DAT,FORWARD) != NULL)			//接收的数据判比较
		{
			Motor_ForWard();		//前进
		}
		else if(strstr(RX1_DAT,BACK) != NULL)
		{
			Motor_Back();			//后退
		}
		else if(strstr(RX1_DAT,TURNLEFT) != NULL)
		{
			Motor_TurnLeft(); 		//左转
		}
		else if(strstr(RX1_DAT,TURNRIGHT) != NULL)
		{
			Motor_TurnRight(); 		//右转
		}
		else if(strstr(RX1_DAT,STOP) != NULL)
		{
			Motor_Stop();			//停止
		}
		else if(strstr(RX1_DAT,REDUCESPEED	) != NULL)
		{
			Motor_ReduceSpeed();	//减速		每次 减10 
		}
		else if(strstr(RX1_DAT,ADDSPEED ) != NULL)
		{
			Motor_AddSpeed(); 		//加速		每次 加10 
		}
		Flag1=0;						//接收标志清零
		Uart_SendString(UART_1,RX1_DAT); 
	}
}

/****
	* @brief	避障模式
	* @param   	无
	* @return   无    	
	* Sample usage:Motor_Ultrasonic_Mode();
	* @note 
    */
void Motor_Ultrasonic_Mode()
{
	Servo_PWM = 3;			//超声波转向中间
	Delay1ms();
	Distance_Middle = Ultrasonic_GetDistance();			//检测右侧距离
	Delay1ms();
	if(Distance_Middle <= 200)
	{
		Voice_Count = 200;		//蜂鸣器提醒

		Motor_Stop();			//停止

		Servo_PWM = 1;		//超声波转向右侧
		Delay(1000);
		Distance_Right = Ultrasonic_GetDistance();		//检测右侧距离
		Delay1ms();

		Servo_PWM = 5;		//超声波转向左侧
		Delay(1600);
		Distance_Left = Ultrasonic_GetDistance();		//检测左侧距离
		Delay1ms();
	}
	if(Distance_Middle > 300)		//前方距离大于30cm  前进
	{
		Motor_ForWard();
	}
	else if(Distance_Right >= Distance_Left && Distance_Right > 300)	
	{
		//若右距离大于左距离 并且大于30cm时  右转一段时间停下
		Motor_TurnRight();
		Delay(1000);
		Motor_Stop();
	}
	else if(Distance_Right <= Distance_Left && Distance_Left > 300)		
	{
		//若左距离大于右距离 并且大于30cm时  左转一段时间停下
		Motor_TurnLeft();
		Delay(1000);
		Motor_Stop();
	}
	//printf("Distance:%d\r\n",Distance_Middle);			//打印下距离
}

/****
	* @brief	运行模式切换 -- 避障  蓝牙  
	* @param   	无
	* @return   无    	
	* Sample usage:Auto_Hand_Mode();
	* @note 
    */
void Auto_Hand_Mode()
{
	switch(Auto_Hand_Mode_Flag)
	{
		case Ultrasonic_Mode:
			Motor_Ultrasonic_Mode();		//避障
		break;
		case Blue_Mode:
			MOTOR_Blue_Mode();				//蓝牙
		break;
		default:							//正常情况只有 0 / 1 两种 不会执行该语句  可以不写
			printf("Select Err\n");
		break;
	}
}

/****
	* @brief	Into 中断函数  -- 检测按键 
	* @param   	无
	* @return   无  
	* @note 	由于按键在 P3.2 所以用中断  也可另写一个按键检测函数
    */
void Int0() interrupt 0
{
	if(Key == 0)
	{
		Delay(20);
		if(Key == 0)
		{
			if(Auto_Hand_Mode_Flag)		
			{
				Auto_Hand_Mode_Flag = 0;
			}
			else 
			{
				Auto_Hand_Mode_Flag = 1;
			}
		}
		while(!Key);
	}
}