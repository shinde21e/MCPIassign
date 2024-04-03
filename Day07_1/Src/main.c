/**
 ******************************************************************************
 * @file           : main.c
 * @author         : superuser
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"
#include "uart.h"
#include "led.h"
#include "switch.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	char str[20];
	SystemInit();
	LedInit(LED_GREEN);
	SwitchInit(SWITCH);
	UartInit(BAUD_9600);

	int count=0;
	UartPuts("KILL COUNT \n");



	while(1) {
			// wait until switch interrupt generated
			while(exti0_flag == 0)
				;
			// Blink the Led
			LedBlink(LED_GREEN, 700);
			count++;
			sprintf(str,"\r%d ",count);
			UartPuts(str);

			exti0_flag = 0;
		}
	return 0;
}
