/*
 * joy.c
 *
 *  Created on: Feb 4, 2024
 *      Author: YellowWenJie
 */
#include "joy.h"

uint16_t AD_Value[4]; // 定义一个数组

//* 将16位拆分成俩个8位，再将俩个八位合并到一个数组
uint8_t *Adjusted_ADC_Data()
{
  static uint8_t Adjusted_ADC_Data_Variable[8];

  static uint8_t Adjusted_ADC_Data_High[4]; // 高位

  static uint8_t Adjusted_ADC_Data_Low[4]; // 低位

  int loop, index, h_len, l_len;

  h_len = l_len = 4;

  index = 0;

  for (uint8_t i = 0; i < 4; i++)
  {
    Adjusted_ADC_Data_High[i] = (AD_Value[i] >> 8) & 0xff; // 高8位
  }

  for (uint8_t i = 0; i < 4; i++)
  {
    Adjusted_ADC_Data_Low[i] = AD_Value[i] & 0xff; // 低8位
  }

  for (loop = 0; loop < h_len; loop++)
  {
    Adjusted_ADC_Data_Variable[index] = Adjusted_ADC_Data_High[loop];
    index++;
  }

  for (loop = 0; loop < l_len; loop++)
  {
    Adjusted_ADC_Data_Variable[index] = Adjusted_ADC_Data_Low[loop];
    index++;
  }

  return Adjusted_ADC_Data_Variable;
}
