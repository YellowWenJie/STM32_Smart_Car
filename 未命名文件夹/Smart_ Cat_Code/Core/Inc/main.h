/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.h
 * @brief          : Header for main.c file.
 *                   This file contains the common defines of the application.
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
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED1_Pin GPIO_PIN_13
#define LED1_GPIO_Port GPIOC
#define Echo_Pin GPIO_PIN_1
#define Echo_GPIO_Port GPIOA
#define Trig_Pin GPIO_PIN_2
#define Trig_GPIO_Port GPIOA
#define IRQ_24L01_Pin GPIO_PIN_4
#define IRQ_24L01_GPIO_Port GPIOA
#define CSN_24L01_Pin GPIO_PIN_5
#define CSN_24L01_GPIO_Port GPIOA
#define CE_24L01_Pin GPIO_PIN_6
#define CE_24L01_GPIO_Port GPIOA
#define Back_AIN2_Pin GPIO_PIN_5
#define Back_AIN2_GPIO_Port GPIOD
#define Back_BIN1_Pin GPIO_PIN_6
#define Back_BIN1_GPIO_Port GPIOD
#define Back_BIN2_Pin GPIO_PIN_7
#define Back_BIN2_GPIO_Port GPIOD
#define Front_AIN1_Pin GPIO_PIN_3
#define Front_AIN1_GPIO_Port GPIOB
#define Front_AIN2_Pin GPIO_PIN_4
#define Front_AIN2_GPIO_Port GPIOB
#define Front_BIN1_Pin GPIO_PIN_5
#define Front_BIN1_GPIO_Port GPIOB
#define Front_BIN2_Pin GPIO_PIN_6
#define Front_BIN2_GPIO_Port GPIOB
#define Back_AIN1_Pin GPIO_PIN_7
#define Back_AIN1_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
  /*---------------------- LED控制宏 ------------------------*/

#define LED1_ON HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);    // 输出低电平，点亮LED1
#define LED1_OFF HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET); // 输出高电平，关闭LED1

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
