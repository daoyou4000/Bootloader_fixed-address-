/*
 * bootloader.c
 *
 *  Created on: 12.9.2021
 *      Author: XXXX
 */

#include"bootloader.h"
#include"stm32l431xx.h"
#include"hardware.h"

// From https://github.com/viktorvano/STM32-Bootloader/blob/master/STM32F103C8T6_Bootloader/Core/Inc/bootloader.h
typedef void (application_t)(void);

// From https://github.com/viktorvano/STM32-Bootloader/blob/master/STM32F103C8T6_Bootloader/Core/Inc/bootloader.h
typedef struct
{
    uint32_t    stack_addr;     // Stack Pointer
    application_t*  func_p;        // Program Counter
} JumpStruct;

AppSelection App;

void vL431_DeInitAndJump(void)
{
	BootloaderMode bootloaderMode;
	if(((GPIOA->IDR)&0x00000001) == TRUE )
	{
		bootloaderMode = FlashMode;
		for(uint8_t i=0; i<10; i++)
		{
			GPIOB->ODR|=0x00002001; // PB13 high
		}

	}else
	{
		bootloaderMode = JumpMode;
		//HAL_GPIO_WritePin(USB_ENABLE_GPIO_Port, USB_ENABLE_Pin, GPIO_PIN_RESET);
	}

	if( ( (GPIOA->IDR) & 0x00000002) == 0x00000002)
		App = App1;
	else
		App = App2;

	if(bootloaderMode == JumpMode)
	{
		if(App == App1)
		{
			//Check if the application is there
			GPIOB->ODR&=(~0x00002001); // PB13 low
			uint8_t emptyCellCount = 0;
			for(uint8_t i=0; i<10; i++)
			{
				if(readWord(APP1_START + (i*4)) == -1)
					emptyCellCount++;
			}

			if(emptyCellCount != 10)
			{

				jumpToApp(APP1_START);
			}
			else
			{

			}
				//errorBlink();
		}
		else
		{
			//Check if the application is there
			uint8_t emptyCellCount = 0;
			for(uint8_t i=0; i<10; i++)
			{
				if(readWord(APP2_START + (i*4)) == -1)
					emptyCellCount++;
			}

			if(emptyCellCount != 10)
			{

				jumpToApp(APP2_START);
			}
			else
			{
				//errorBlink();
			}

		}
	}
}

uint32_t readWord(uint32_t address)
{
	uint32_t read_data;
	read_data = *(uint32_t*)(address);
	return read_data;
}

void jumpToApp(const uint32_t address)
{
	const JumpStruct* vector_p = (JumpStruct*)address;
	vDeInitSystemClock();
	//deinitEverything();
	SysTick->CTRL = 0;
	SysTick->LOAD = 0;
	SysTick->VAL = 0;
	/* let's do The Jump! */
    /* Jump, used asm to avoid stack optimization */
    asm("msr msp, %0; bx %1;" : : "r"(vector_p->stack_addr), "r"(vector_p->func_p));
}
