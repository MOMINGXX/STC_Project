#include "STC12_DELAY.h"

#if (SYS_CLK == 24000000)

/****
	@brief      —”≥Ÿ1Œ¢√Î
	@param		Œﬁ	
	@return     Œﬁ        	
	Sample usage:  Delay1us(); —”≥Ÿ1us
****/
void Delay1us()		
{
    uint8_t i;
	i = 3;
	while (--i);
}

/****
	@brief      —”≥Ÿ5Œ¢√Î
	@param		Œﬁ	
	@return     Œﬁ        	
	Sample usage:  Delay5us(); —”≥Ÿ5us
****/
void Delay5us()	
{
	uint8_t i;
	i = 27;
	while (--i);
}

/****
	@brief      —”≥Ÿ10Œ¢√Î
	@param		Œﬁ	
	@return     Œﬁ        	
	Sample usage:  Delay10us(); —”≥Ÿ10us
****/
void Delay10us()	
{
	uint8_t i;
	i = 57;
	while (--i);
}

/****
	@brief      —”≥Ÿ15Œ¢√Î
	@param		Œﬁ	
	@return     Œﬁ        	
	Sample usage:  Delay15us(); —”≥Ÿ15us
****/
void Delay15us()		
{
	uint8_t i;
	_nop_();
	_nop_();
	i = 38;
	while (--i);
}

/****
	@brief      —”≥Ÿ50Œ¢√Î
	@param		Œﬁ	
	@return     Œﬁ        	
	Sample usage:  Delay50us(); —”≥Ÿ50us
****/
void Delay50us()		
{
	uint8_t i;
	uint8_t j;
    _nop_();
    _nop_();
	i = 2;
	j = 38;
	do
	{
		while (--j);
	} while (--i);
}

/****
	@brief      —”≥Ÿ100Œ¢√Î
	@param		Œﬁ	
	@return     Œﬁ        	
	Sample usage:  Delay100us(); —”≥Ÿ100us
****/
void Delay100us()	
{
	uint8_t i;
	uint8_t j;
    _nop_();
    _nop_();
	i = 3;
	j = 81;
	do
	{
		while (--j);
	} while (--i);
}

/****
	@brief      —”≥Ÿ1∫¡√Î
	@param		Œﬁ	
	@return     Œﬁ        	
	Sample usage:  Delay1ms(); —”≥Ÿ1ms
****/
void Delay1ms()
{
	uint8_t i;
	uint8_t j;
    _nop_();
    _nop_();
	i = 24;
	j = 84;
	do
	{
		while (--j);
	} while (--i);
}

#elif (SYS_CLK == 12000000)		//12MHz

/****
	@brief      —”≥Ÿ1Œ¢√Î
	@param		Œﬁ	
	@return     Œﬁ        	
	Sample usage:  Delay1us(); —”≥Ÿ1us
****/
void Delay1us()		//@12.000
{
	_nop_();
    _nop_();
}

/****
	@brief      —”≥Ÿ5Œ¢√Î
	@param		Œﬁ	
	@return     Œﬁ        	
	Sample usage:  Delay5us(); —”≥Ÿ5us
****/
void Delay5us()		//@12.000
{
	uint8_t i;
	i = 12;
	while (--i);
}

/****
	@brief      —”≥Ÿ10Œ¢√Î
	@param		Œﬁ	
	@return     Œﬁ        	
	Sample usage:  Delay10us(); —”≥Ÿ10us
****/
void Delay10us()		
{
	uint8_t i;
	i = 27;
	while (--i);
}

/****
	@brief      —”≥Ÿ15Œ¢√Î
	@param		Œﬁ	
	@return     Œﬁ        	
	Sample usage:  Delay15us(); —”≥Ÿ15us
****/
void Delay15us()		
{
	uint8_t i;
	_nop_();
	_nop_();
	i = 38;
	while (--i);
}

/****
	@brief      —”≥Ÿ50Œ¢√Î
	@param		Œﬁ	
	@return     Œﬁ        	
	Sample usage:  Delay100us(); —”≥Ÿ50us
****/
void Delay50us()		
{
	uint8_t i;
	uint8_t j;
    _nop_();
    _nop_();
	i = 1;
	j = 145;
	do
	{
		while (--j);
	}while (--i);
}

/****
	@brief      —”≥Ÿ100Œ¢√Î
	@param		Œﬁ	
	@return     Œﬁ        	
	Sample usage:  Delay100us(); —”≥Ÿ100us
****/
void Delay100us()		
{
	uint8_t i;
	uint8_t j;
    _nop_();
    _nop_();
	i = 2;
	j = 38;
	do
	{
		while (--j);
	} while (--i);
}

/****
	@brief      —”≥Ÿ1∫¡√Î
	@param		Œﬁ	
	@return     Œﬁ        	
	Sample usage:  Delay1ms(); —”≥Ÿ1ms
****/
void Delay1ms()	
{
	uint8_t i;
	uint8_t j;
    _nop_();
    _nop_();
	i = 12;
	j = 168;
	do
	{
		while (--j);
	} while (--i);
}

#else //11059200MHz

/****
	@brief      —”≥Ÿ1Œ¢√Î
	@param		Œﬁ	
	@return     Œﬁ        	
	Sample usage: Delay1us(); —”≥Ÿ1us
****/
void Delay1us()		
{
	_nop_();
}

/****
	@brief      —”≥Ÿ5Œ¢√Î
	@param		Œﬁ	
	@return     Œﬁ        	
	Sample usage:  Delay5us(); —”≥Ÿ5us
****/
void Delay5us()	
{
	uint8_t i;
	_nop_();
	_nop_();
    _nop_();
	i = 10;
	while (--i);
}

/****
	@brief      —”≥Ÿ10Œ¢√Î
	@param		Œﬁ	
	@return     Œﬁ        	
	Sample usage:  Delay10us(); —”≥Ÿ10us
****/
void Delay10us()		
{
	uint8_t i;
	_nop_();
	_nop_();
    _nop_();
	i = 24;
	while (--i);
}

/****
	@brief      —”≥Ÿ15Œ¢√Î
	@param		Œﬁ	
	@return     Œﬁ        	
	Sample usage:  Delay15us(); —”≥Ÿ15us
****/
void Delay15us()		
{
	uint8_t i;
	_nop_();
	_nop_();
	i = 38;
	while (--i);
}

/****
	@brief      —”≥Ÿ50Œ¢√Î
	@param		Œﬁ	
	@return     Œﬁ        	
	Sample usage:  Delay100us(); —”≥Ÿ50us
****/
void Delay50us()	
{
	uint8_t i;
	uint8_t j;
    _nop_();
    _nop_();
    _nop_();
	i = 1;
	j = 133;
	do
	{
		while (--j);
	} while (--i);
}

/****
	@brief      —”≥Ÿ100Œ¢√Î
	@param		Œﬁ	
	@return     Œﬁ        	
	Sample usage:  Delay100us(); —”≥Ÿ100us
****/
void Delay100us()		
{
	uint8_t i;
	uint8_t j;
	i = 2;
	j = 15;
	do
	{
		while (--j);
	}while (--i);
}

/****
	@brief      —”≥Ÿ1∫¡√Î
	@param		Œﬁ	
	@return     Œﬁ        	
	Sample usage:  Delay1ms(); —”≥Ÿ1ms
****/
void Delay1ms()
{
	uint8_t i;
	uint8_t j;
	_nop_();
	i = 11;
	j = 190;
	do
	{
		while (--j);
	}while(--i);
}

#endif

/****
	@brief      —”≥Ÿtime∫¡√Î
	@param		time	—”≥Ÿ ±º‰(1-65535)	
	@return     Œﬁ        	
	Sample usage:  Delay(1000); —”≥Ÿ1s
****/
void Delay(uint16_t time)
{
	if(time < 1)
	{
		time = 1;
	}	
	do 
	{ 
		Delay1ms();
	}while (--time);
}