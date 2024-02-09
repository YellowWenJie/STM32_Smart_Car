#ifndef __LED_H
#define __LED_H

#include "stm32h7xx_hal.h"
#include "main.h"

/*----------------------------------------- LED控制宏 ----------------------------------*/

#define LED1_ON HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET) // 输出低电平，点亮LED1
#define LED1_OFF HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET)  // 输出高电平，关闭LED1
#define LED1_Toggle HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);           // 翻转IO口状态

/*---------------------------------------- 函数声明 ------------------------------------*/

void LED_Init(void);

#endif //__LED_H
