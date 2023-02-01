#include "DHT11.h"

/****
	* @brief	DHT11 延时80us      			  
	* @param   	无
	* @return   无  	
	* Sample usage: DHT11_Delay80us();
    */
static void DHT11_Delay80us()		//@24.000MHz
{
	unsigned char i, j;

	_nop_();
	_nop_();
	i = 2;
	j = 218;
	do
	{
		while (--j);
	} while (--i);
}

/****
	* @brief	DHT11 延时60us      			  
	* @param   	无
	* @return   无  	
	* Sample usage: DHT11_Delay60us();
    */
static void DHT11_Delay60us()		//@24.000MHz
{
	unsigned char i, j;

	_nop_();
	_nop_();
	i = 2;
	j = 98;
	do
	{
		while (--j);
	} while (--i);
}

/****
	* @brief	DHT11 初始化      			  
	* @param   	无
	* @return   无  	
	* Sample usage: DHT11_Init();
    */
void DHT11_Init()
{
    uint8_t i;
    DHT11_PIN = 1;
    i = 117;while (--i);        //30us
    DHT11_PIN = 0;
    Delay(20);
    DHT11_PIN = 1;
    i = 117;while (--i);
}

/****
	* @brief	DHT11 读取引脚状态    			  
	* @param   	无
	* @return   0 / 1  	
	* Sample usage:DHT11_Init();
    */
uint8_t DHT11_Read_Bit()
{
    while(DHT11_PIN);           //等待低电平 开始传输数据
    while(!DHT11_PIN);          //等待高电平
    Delay(60);
    if(DHT11_PIN)
    {
        return 1;
    }
    return 0;
}                                     

/****
	* @brief	DHT11 读取数据   			  
	* @param   	无
	* @return   Byte    读取的数据  	
	* Sample usage:DHT11_Read_Byte();
    */
/*
uint8_t DHT11_Read_Byte()
{
    uint8_t i = 0;
    uint8_t Byte = 0x00;
    for(i = 0; i < 8; i++)
    {
        Byte <<= 1;
        Byte |= DHT11_Read_Bit();
    }
}
*/

/****
	* @brief	DHT11 读取数据   			  
	* @param   	无
	* @return   Byte    读取的数据  	
	* Sample usage:DHT11_Read_Byte();
    */
uint8_t DHT11_Read_Byte()
{
    uint8_t i = 0;
    uint8_t Byte = 0x00;
    for(i = 0; i < 8; i++)
    {
        while(DHT11_PIN);       //等待低电平 开始传输数据
        while(!DHT11_PIN);
        DHT11_Delay60us();
        Byte <<= 1;
        if(DHT11_PIN == 1)
        {
            Byte += 1;
        }
        while(DHT11_PIN);       //等待低电平 开始传输下一个数据
    }
    return Byte;
}

/****
	* @brief	DHT11 读取温湿度数据   			  
	* @param   	Data    存储读取的温湿度数据 
	* @return   0 / 1   0>读取的数据错误         1    	
	* Sample usage:DHT11_Read_Data(&TempH,&TempL,&HumiH,&HumiL);
    */
void DHT11_Read_Data(uint8_t *TempH,uint8_t *TempL,uint8_t *HumiH,uint8_t *HumiL)
{
	uint8_t i;
	uint8_t Buff[5];
	DHT11_Init();
	if(DHT11_PIN == 0)
	{
		while(DHT11_PIN == 0);    //等待拉高 
		//DHT11_Delay80us();		
		for(i=0;i<5;i++)
		{
			Buff[i] = DHT11_Read_Byte();
		}
		//i = 147;while (--i);
		if(Buff[4] == Buff[0] + Buff[1] + Buff[2] + Buff[3])
		{
			*HumiH = Buff[0];
			*HumiL = Buff[1];
			*TempH = Buff[2];
			*TempL = Buff[3];
		}
	}
}
