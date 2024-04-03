/*
 * main.c
 *
 *  Created on: Apr 2, 2024
 *      Author: cherikiansh
 */


#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"
#include "eeprom.h"
#include "usart.h"
#include "i2c.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	char str[32] = "";
	char ch;
	SystemInit();
	EEPROM_Init();
	uartinit(9600);
	do
			{
	uartputs("Enter the choice\r\n");
	uartputs("1.EEPROM write\r\n");
	uartputs("2.EEPROM READ\r\n");
	//ch=uartgetch();
	uartgets(str);
	sscanf(str,"%d",&ch);

	switch(ch)
	{
	case 1:uartgets(str);
		EEPROM_Write(0x0020, (uint8_t*)str, 16);
		break;
	case 2:
		EEPROM_Read(0x0020, (uint8_t*)str, 16);
		uartputs(str);
		break;
	}
	}while(ch!=0);
	return 0;
	}











