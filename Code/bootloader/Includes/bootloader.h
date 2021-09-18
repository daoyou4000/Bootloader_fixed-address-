/*
 * bootloader.h
 *
 *  Created on: 12.9.2021
 *      Author: xxx
 */

#ifndef INCLUDES_BOOTLOADER_H_
#define INCLUDES_BOOTLOADER_H_



#define APP1_START (0x08005000)			//Origin + Bootloader size (20kB)
#define APP2_START (0x0800A800)			//Origin + Bootloader size (20kB) + App1 Bank (22kB)
#define FLASH_BANK_SIZE (0X5800)		//22kB
#define FLASH_PAGE_SIZE_USER (0x400)	//1kB

#include"datatypes.h"
#include "stm32l431xx.h"

typedef enum
{
    JumpMode,
	FlashMode
} BootloaderMode;

typedef enum
{
    App1,
	App2
} AppSelection;

typedef enum
{
    Unerased,
	Erased,
	Unlocked,
	Locked
} FlashStatus;


void vL431_DeInitAndJump(void);
void jumpToApp(const uint32_t address);
uint32_t readWord(uint32_t address);

#endif /* INCLUDES_BOOTLOADER_H_ */
