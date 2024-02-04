/*
 * led.c
 *
 *  Created on: Dec 30, 2023
 *      Author: YellowWenJie
 */
#include "led.h"

void LED_0(uint8_t x)
{
  if (x)
    HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_SET);
  else
    HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_RESET);
}

void LED_1(uint8_t x)
{
  if (x)
    HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
  else
    HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
}
