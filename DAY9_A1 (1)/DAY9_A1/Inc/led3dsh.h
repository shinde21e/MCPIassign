/*
 * led3dsh.h
 *
 *  Created on: Apr 3, 2024
 *      Author: cherikiansh
 */
#include <stdint.h>
#include "stm32f4xx.h"
#include "spi.h"
#include"stm32f407xx.h"
#ifndef LED3DSH_H_
#define LED3DSH_H_

#define LIS_CTRL_REG4_ADDR               0x20
#define LIS_STATUS_ADDR                  0x27
#define LIS_OUT_X_L_ADDR                 0x28
#define LIS_OUT_X_H_ADDR                 0x29
#define LIS_OUT_Y_L_ADDR                 0x2A
#define LIS_OUT_Y_H_ADDR                 0x2B
#define LIS_OUT_Z_L_ADDR                 0x2C
#define LIS_OUT_Z_H_ADDR                 0x2D

#define LIS_DATARATE_25                  ((uint8_t)0x40)
#define LIS_X_ENABLE                     ((uint8_t)BV(0))
#define LIS_Y_ENABLE                     ((uint8_t)BV(1))
#define LIS_Z_ENABLE                     ((uint8_t)BV(2))
#define LIS_XYZ_ENABLE                   (LIS_X_ENABLE | LIS_Y_ENABLE | LIS_Z_ENABLE)

#define LIS_STATUS_XYZ_Msk					(BV(0) | BV(1) | BV(2))

typedef struct {
	int16_t x;
	int16_t y;
	int16_t z;
}LIS_Data;

void LIS_WriteIO(uint8_t reg, uint8_t data[], uint8_t size);
void LIS_ReadIO(uint8_t reg, uint8_t data[], uint8_t size);

void LIS_Init(void);
LIS_Data LIS_GetData(void);
int LIS_DRdy(void);



#endif /* LED3DSH_H_ */
