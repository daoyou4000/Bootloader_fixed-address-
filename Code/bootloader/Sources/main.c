

#include "datatypes.h"
#include "stm32l431xx.h"
#include "hardware.h"
#include "isr.h"
#include "bootloader.h"

bool bToggle=FALSE;


int main(void)
{

	vInitSystemClock();
	vInitTaskTimer();
	uint16_t i = 100;
	while(i)
	{
		if(gbRunTask)
		{
			if(bToggle)
			{
				GPIOA->ODR|=0x00000001; // PA0 high
				GPIOB->ODR|=0x00002001; // PB13 high
				bToggle=FALSE;
			}
			else
			{
				GPIOA->ODR&=(~0x00000001); // PA0 low
				GPIOB->ODR&=(~0x00002001); // PB13 low
				bToggle=TRUE;
			}

			gbRunTask=FALSE;
			i--;
		}

	}
	//vDeInitSystemClock();
	//i = 10;
	//while(i)
	//{
	//	i--;
	//}
	//jumpToApp(APP1_START);
	vL431_DeInitAndJump();
	while(1)
	{

	}

	// return; // cannot reach
}


