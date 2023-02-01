#include "Deal.h"
#include "EEPROM.h"

uint8_t arr2[256]={0}; 
uint8_t arr3[256]={0}; 

int i = 0;
void main()
{
	Deal_Init();

	for( i = 0; i < 256; i++)
	{
		arr2[i] = i;
		//AT24C02_Byte_Write(i,arr2[i]);
	}

	AT24C02_Buffer_Write(0,arr2,255);

	AT24C02_Sequential_Read(0,arr3,255);
	for(i = 0; i < 256; i++)
	{
		printf("%bu ",arr3[i]);
		if(i%8 ==0)
		{
			printf("\n");
		}
	}
	printf("\n");

	while(1)
	{
		//OLED_DS18B20_Temp();
		//OLED_DHT11_Temp();
	}
}

