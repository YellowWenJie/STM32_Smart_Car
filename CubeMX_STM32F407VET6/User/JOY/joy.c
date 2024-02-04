/*
 * joy.c
 *
 *  Created on: Feb 4, 2024
 *      Author: YellowWenJie
 */
#include "joy.h"
#include "../NRF24L01/nrf24l01.h"
#include "stdio.h"

unsigned char tmp_buf[32] = {0};

//* 将俩个八位数合并为十六位并塞入一个数组
uint16_t *NRF24Lo1_RX_Adjusted_ADC_Data()
{
  static uint16_t ADC_Data[4];
  if (NRF24L01_RxPacket(tmp_buf) == 0)
  {
    for (size_t i = 0; i < 4; i++)
    {
      ADC_Data[i] = ((uint16_t)(tmp_buf[i] << 8) | tmp_buf[i + 4]) * 1;
    }
    //* 微调
    ADC_Data[0] = ADC_Data[0];
    ADC_Data[1] = ADC_Data[1] + 75;
    ADC_Data[2] = ADC_Data[2] - 50;
    ADC_Data[3] = ADC_Data[3] + 10;

    for (size_t i = 0; i < 4; i++)
    {
      if (ADC_Data[i] % 100 < 50)
      {
        ADC_Data[i] = ADC_Data[i] - (ADC_Data[i] % 100);
      }
      if (ADC_Data[i] % 100 >= 50)
      {
        ADC_Data[i] = ADC_Data[i] + (100 - (ADC_Data[i] % 100));
      }
    }
  }
  return ADC_Data;
}

//* 摇杆控制小车逻辑
//***************************************************************************************************************

//* 摇杆数据
uint16_t *Joystick_Data()
{
  uint16_t Joystick_Value[4];

  //* 前进的俩个 ADC 采集数据 ADC1 ADC3
  //* 等于 2000 为不动

  return Joystick_Value;
}

void Car_Forward(uint16_t *data)
{
}