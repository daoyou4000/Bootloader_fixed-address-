#include "datatypes.h"
#include "stm32l431xx.h"
#include "hardware.h"
#include "isr.h"

bool bToggle=FALSE;

int main(void)
{
	vInitSystemClock();
	vInitTaskTimer();

	while(1)
	{
		if(gbRunTask)
		{
			if(bToggle)
			{
				//GPIOA->ODR|=0x00000001; // PA0 high
				GPIOB->ODR|=0x00002001; // PB13 high
				bToggle=FALSE;
			}
			else
			{
				//GPIOA->ODR&=(~0x00000001); // PA0 low
				GPIOB->ODR&=(~0x00002001); // PB13 low
				bToggle=TRUE;
			}

			gbRunTask=FALSE;
		}
	}

	// return; // cannot reach
}


