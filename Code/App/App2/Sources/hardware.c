//----------------------------------------------------------------------------------------------------------------------------
// 1) INCLUDE FILES
//----------------------------------------------------------------------------------------------------------------------------
#include "datatypes.h"
#include "hardware.h"
#include "stm32l431xx.h"

//----------------------------------------------------------------------------------------------------------------------------
// 2) MACRO DEFINITIONS (maximum name length is 31 char!)
//----------------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------------
// 3) LOCAL DATA STRUCTURES AND ENUMS
//----------------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------------
// 4) GLOBAL VARIABLE DEFINITIONS
//----------------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------------
// 5) LOCAL, STATIC VARIABLES
//----------------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------------
// 6) DECLARATIONS OF LOCAL FUNCTION PROTOTYPES
//----------------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------------
// 7) FUNCTIONS
//----------------------------------------------------------------------------------------------------------------------------
void vInitSystemClock(void)
{
	// lower latency for high MCU clock speed
	FLASH->ACR|=FLASH_ACR_LATENCY;

	// enable port a clock
	RCC->AHB2ENR|=RCC_AHB2ENR_GPIOAEN;
	RCC->AHB2ENR|=RCC_AHB2ENR_GPIOBEN;
	// enable port b clock
	RCC->AHB2ENR|=RCC_AHB2ENR_GPIOHEN;

	// PA0 to output
	GPIOA->MODER  &=(~0x00000002); // output
	GPIOA->OSPEEDR|=0x00000002; // high speed

	// PB13 to output
	GPIOB->MODER  &=(~0x08000002); // output
	GPIOB->OSPEEDR|=0x08000002; // high speed

	// enable timer 2 clock
	RCC->APB1ENR1|=RCC_APB1ENR1_TIM2EN;

	// init system clock

	RCC->CR &= (uint32_t)(~RCC_CR_PLLON);

	while((RCC->CR & RCC_CR_PLLRDY) != 0)
	{
	    // For robust implementation, add here time-out management
	}
	RCC->CR|=RCC_CR_HSEON;
	RCC->PLLCFGR|=RCC_PLLCFGR_PLLSRC_HSE;
	RCC->PLLCFGR|=0x00000000; // PLLM 1
	RCC->PLLCFGR&=(~0x00001000);
	RCC->PLLCFGR|=0x00000A00; // PLLN 10
	RCC->PLLCFGR|=0x00000000; // PLLR 2

	RCC->PLLCFGR|=RCC_PLLCFGR_PLLREN;

	RCC->CR|=RCC_CR_PLLON; // pll on

	while((RCC->CR & RCC_CR_PLLRDY) != 0)
	{
	    // For robust implementation, add here time-out management
	}

	RCC->CFGR|=RCC_CFGR_SW_PLL; // pll to system clock source

	while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL)
	{
	    // For robust implementation, add here time-out management
	}

	return;
}

void vInitTaskTimer(void)
{
	// tim2

	// 80MHz->1ms
	TIM2->ARR=MAIN_LOOP_DELAY;

	TIM2->CR1|=TIM_CR1_CEN;

	NVIC_EnableIRQ(TIM2_IRQn);

	TIM2->DIER|=TIM_DIER_UIE;

	return;
}



