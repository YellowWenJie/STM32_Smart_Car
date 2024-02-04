/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    usart.c
 * @brief   This file provides code for the configuration
 *          of the USART instances.
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
/* Includes ------------------------------------------------------------------*/
#include "usart.h"

/* USER CODE BEGIN 0 */
#include <stdio.h>

#ifdef __GNUC__

#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)

#else

#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)

#endif /* __GNUC__ */

uint8_t USART1_Rx_Buf[USART1_REC_LEN];
uint16_t USART1_Rx_STA = 0;
uint8_t USART1_NewData;

uint8_t USART2_Rx_Buf[USART2_REC_LEN];
uint16_t USART2_Rx_STA = 0;
uint8_t USART2_NewData;

uint8_t USART3_Rx_Buf[USART3_REC_LEN];
uint16_t USART3_Rx_STA = 0;
uint8_t USART3_NewData;

/* USER CODE END 0 */

UART_HandleTypeDef huart1;

/* USART1 init function */

void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspInit 0 */

  /* USER CODE END USART1_MspInit 0 */
    /* USART1 clock enable */
    __HAL_RCC_USART1_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**USART1 GPIO Configuration
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_9|GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* USART1 interrupt Init */
    HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART1_IRQn);
  /* USER CODE BEGIN USART1_MspInit 1 */

  /* USER CODE END USART1_MspInit 1 */
  }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef* uartHandle)
{

  if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspDeInit 0 */

  /* USER CODE END USART1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART1_CLK_DISABLE();

    /**USART1 GPIO Configuration
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_9|GPIO_PIN_10);

    /* USART1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART1_IRQn);
  /* USER CODE BEGIN USART1_MspDeInit 1 */

  /* USER CODE END USART1_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */
PUTCHAR_PROTOTYPE
{

  /* Place your implementation of fputc here */

  /* e.g. write a character to the EVAL_COM1 and Loop until the end of transmission */
  HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xFFFF);

  return ch;
}
//* 锟叫断回碉拷
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{

  //* USART1 锟斤拷锟斤拷
  if (huart == &huart1)
  {

    printf("%c", USART1_NewData);
    //* 锟叫讹拷锟斤拷锟斤拷位锟侥碉拷一位?
    if ((USART1_Rx_STA & 0x8000) == 0)
    {
      //* 锟叫讹拷锟斤拷锟斤拷位锟侥第讹拷位
      if (USART1_Rx_STA & 0x4000)
      {
        if (USART1_NewData != 0x0a) //? 0x0a(锟斤拷锟斤拷)
          USART1_Rx_STA = 0;
        else
          USART1_Rx_STA |= 0x8000;
      }
      else
      { //* 锟叫讹拷锟角诧拷锟角回筹拷
        if (USART1_NewData == 0x0d)
          USART1_Rx_STA |= 0x4000;
        else
        {
          //* 锟斤拷锟斤拷锟斤拷锟斤拷拥锟斤拷锟斤拷锟斤拷锟�
          USART1_Rx_Buf[USART1_Rx_STA & 0x3FFF] = USART1_NewData;
          USART1_Rx_STA++;
          if (USART1_Rx_STA > (USART1_REC_LEN - 1))
            USART1_Rx_STA = 0;
        }
      }
    }
    //* 锟斤拷锟铰匡拷始锟叫讹拷
    HAL_UART_Receive_IT(&huart1, (uint8_t *)&USART1_NewData, 1);
  }
  //* USART2 锟斤拷锟斤拷
  // else if (huart == &huart2)
  // {
  //   HAL_UART_Transmit(&huart2, (uint8_t *)&USART2_NewData, 1, 0xFFFF);

  //   printf("%c", USART2_NewData);
  //   //* 锟叫讹拷锟斤拷锟斤拷位锟侥碉拷一位

  //   if ((USART2_Rx_STA & 0x8000) == 0)
  //   {
  //     //* 锟叫讹拷锟斤拷锟斤拷位锟侥第讹拷位
  //     if (USART2_Rx_STA & 0x4000)
  //     {
  //       if (USART2_NewData != 0x0a) //? 0x0a(锟斤拷锟斤拷)
  //         USART2_Rx_STA = 0;
  //       else
  //         USART2_Rx_STA |= 0x8000;
  //     }
  //     else
  //     { //* 锟叫讹拷锟角诧拷锟角回筹拷
  //       if (USART2_NewData == 0x0d)
  //         USART2_Rx_STA |= 0x4000;
  //       else
  //       {
  //         //* 锟斤拷锟斤拷锟斤拷锟斤拷拥锟斤拷锟斤拷锟斤拷锟�
  //         USART2_Rx_Buf[USART2_Rx_STA & 0x3FFF] = USART2_NewData;
  //         USART2_Rx_STA++;
  //         if (USART2_Rx_STA > (USART2_REC_LEN - 1))
  //           USART2_Rx_STA = 0;
  //       }
  //     }
  //   }
  //   //* 锟斤拷锟铰匡拷始锟叫讹拷
  //   HAL_UART_Receive_IT(&huart2, (uint8_t *)&USART2_NewData, 1);
  // }
}

/* USER CODE END 1 */
