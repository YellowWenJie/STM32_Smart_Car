/*
 * joy.h
 *
 *  Created on: Feb 4, 2024
 *      Author: YellowWenJie
 */

#ifndef JOY_JOY_H_
#define JOY_JOY_H_

#include "stm32f1xx_hal.h"
#include "main.h"

extern uint16_t AD_Value[4];  // 定义一个数组
uint8_t *Adjusted_ADC_Data(); // 高位低位合并后

#endif /* JOY_JOY_H_ */
