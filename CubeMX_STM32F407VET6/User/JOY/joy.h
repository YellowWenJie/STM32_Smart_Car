/*
 * joy.h
 *
 *  Created on: Feb 4, 2024
 *      Author: YellowWenJie
 */

#ifndef JOY_JOY_H_
#define JOY_JOY_H_

#include "stm32f4xx_hal.h"
#include "main.h"

extern unsigned char tmp_buf[32];
uint16_t *NRF24Lo1_RX_Adjusted_ADC_Data();
uint16_t *Joystick_Data();

#endif /* JOY_JOY_H_ */
