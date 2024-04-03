/*
 * usart.h
 *
 *  Created on: Apr 1, 2024
 *      Author: cherikiansh
 */
#ifndef USART_H_
#define USART_H_

#include "stm32f4xx.h"
#include "stm32f407xx.h"

#define baud_9600		9600
#define baud_38400		38400
#define baud_115200		115200

#define baud_brr_9600	0x683
#define baud_brr_38400	0x1A1
#define baud_brr_115200	0x8B

void uartinit(uint32_t baud);
void uartputch(uint8_t ch);
uint8_t uartgetch(void);
void uartputs(char str[]);
void uartgets(char str[]);

#endif /* USART_H_ */


