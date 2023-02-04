#include "Deal.h"

//Alert_Temp[0]	高温报警值	Alert_Temp[1]		低温报警值
uint8_t Alert_Temp[2];
char TempH,TempL,HumiH,HumiL;
float T;
uint8_t Mode = 0;
uint8_t KeyNum = 0;

/****
	* @brief	数据处理 初始化 			  
	* @param   	无
	* @return   无 	
	* Sample usage:Deal_Init();
	* note:	最低为负值  但存储的是正值 所以会在	OLED_Alert_Temp()
	*		中处理
    */
void Deal_Init()
{
    Uart_Init(UART_1,GPIORX_P30,GPIOTX_P31,9600,TIM_BRT);	
	Timer0_Init();
	DHT11_Init();
	OLED_Init();
	OLED_Clear();
	
	//如果阈值非法，则设为默认值
	AT24C02_Sequential_Read(0,Alert_Temp,2);
	if(Alert_Temp[0] > 125 || Alert_Temp[1] <-55 || Alert_Temp[0] <= Alert_Temp[1])
	{
		Alert_Temp[0] = 30;
		Alert_Temp[1] = 10;
	}
}

/****
	* @brief	显示DS18B20 测得温度 			  
	* @param   	x	OLED 显示行位置  x = 0(黄色) 2 4 6
	* @return   无 	
	* Sample usage:OLED_DS18B20_Temp(2);
    */
void OLED_DS18B20_Temp(uint8_t x)
{
	if((x % 2 == 0) && (x <= 6) && (x >= 0))
	{
		OLED_ShowCHinese(1,x,11);
		OLED_ShowCHinese(16,x,12);
		OLED_ShowChar(32,x+1,':',2);	
		
		OLED_ShowCHinese(92,x,14);
		
		DS18B20_ConvertT();
		T=DS18B20_ReadT();
		//printf("\r\nwd:>%f\n",T);
		if(T<0)
		{
			OLED_ShowChar(74,x+1,'.',2);
			OLED_ShowChar(43,x,'-',16);
			OLED_ShowNum(49,x,T,3,16);
			OLED_ShowNum(82,x,(uint32_t)(T*10000)%10000,2,16);
		}
		else OLED_ShowChar(64,x+1,'.',2);
		OLED_ShowNum(39,x,T,3,16);
		OLED_ShowNum(72,x,(uint32_t)(T*10000)%10000,2,16);
	}
	else
	{
		OLED_ShowString(1,x,"Wrong Position!",16);
	}

}

/****
	* @brief	显示DHT11 测得温度 			  
	* @param   	无
	* @return   无 	
	* Sample usage:OLED_DHT11_Temp();
    */
void OLED_DHT11_Temp()
{
	
    DHT11_Read_Data(&TempH,&TempL,&HumiH,&HumiL);	
	
	/*
	printf("Tem:%d ℃\r\n", (int)TempH);
	printf("Tem:%d ℃\r\n", (int)TempL);
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

/****
	* @brief	显示DHT11 测得温度 			  
	* @param   	无
	* @return   无 	
	* Sample usage:OLED_DS18B20_Temp(2);
    */
void OLED_Alert_Temp()
{
	OLED_ShowString(1,2,"TempH:",16);
    OLED_ShowString(1,4,"TempL:",16);

	OLED_ShowNum(56,2,Alert_Temp[0],3,16);
	OLED_ShowChar(50,2,'+',16);
	OLED_ShowChar(50,4,'-',16);
	OLED_ShowNum(56,4,Alert_Temp[1],3,16);
	OLED_ShowCHinese(92,2,14);
	OLED_ShowCHinese(92,4,14);
}

/****
	* @brief	预警温度设置			  
	* @param   	无
	* @return   无 	
	* Sample usage:Alert_Temp_Set();
    */
void Alert_Temp_Set()
{
	if(KeyNum)
	{
		if(4 == KeyNum)							//高温预警值 ++
		{
			Alert_Temp[0]++;
			if(Alert_Temp[0] > 125)
			{
				Alert_Temp[0] = 125;
			}
		}
		else if(5 == KeyNum)					//高温预警值 --
		{
			Alert_Temp[0]--;
			if(Alert_Temp[0] <= Alert_Temp[1])
			{
				Alert_Temp[0]++;
			} 
		}
		else if(6 == KeyNum)					//低温预警值 ++
		{
			Alert_Temp[1]++;
			if(Alert_Temp[1] >= Alert_Temp[0])
			{
				Alert_Temp[1]--;
			} 
		}
		else if(7 == KeyNum)					//低温预警值 --
		{
			Alert_Temp[1]--;
			if(Alert_Temp[1] <= 0)
			{
				Alert_Temp[1] = 55;
			}
		}
		AT24C02_Page_Write(0,Alert_Temp,2);		//存储预警值
		OLED_Alert_Temp();
	}
}

/****
	* @brief	按键扫描			  
	* @param   	无
	* @return   无 	
	* Sample usage:Key_Scan();
    */
void Key_Scan()
{
	KeyNum = key();
}

/****
	* @brief	模式的选择					  
	* @param   	无
	* @return   无 	
	* Sample usage:Mode_Select();
    */
void Mode_Select()
{
	if(1 == KeyNum)
	{
		OLED_Clear();
		Mode = 0;		//显示温湿度
	}
	else if(2 == KeyNum)
	{
		OLED_Clear();
		Mode = 1;		//显示预警值
	}
	else if(3 == KeyNum)
	{
		OLED_Clear();
		Mode = 2;		//设置预警值
	}
	switch (Mode)
	{
		case 0:
			OLED_ShowString(1,0,"Temp Humi Test!",16);
			OLED_DS18B20_Temp(2);
			OLED_DHT11_Temp();
		break;
		
		case 1:
			OLED_ShowString(1,0,"Temp Warning !",16);
			OLED_Alert_Temp();
		break;
		case 2:
			OLED_ShowString(1,0,"Temp Alert Set!",16);
			Alert_Temp_Set();
		break;
		default:
			OLED_ShowString(1,0,"ERROR !",16);
		break;
	}
}

/****
	* @brief	温度报警		  
	* @param   	无
	* @return   无 	
	* Sample usage:Temp_Alarm();
    */
void Temp_Alarm()
{
	Mode_Select();
	if(T > Alert_Temp[0])
	{
		OLED_Clear();
		OLED_DS18B20_Temp(0);
		OLED_ShowString(1,2,"Warning...!!!",16);
		OLED_ShowString(1,4,"High Temp !!!",16);
		Delay(1000);
	}		
	else if(T < (0-Alert_Temp[1]))
	{
		OLED_Clear();
		OLED_DS18B20_Temp(0);
		OLED_ShowString(1,2,"Warning...!!!",16);
		OLED_ShowString(1,4,"Low Temp  !!!",16);
		Delay(1000);
	}			 
}