#include "Deal.h"

void main()
{
	Deal_Init();

	ES = 1;
	EA = 1;

	while (1)
	{
		Key_Scan();
		Temp_Alarm(); 
	}
}
