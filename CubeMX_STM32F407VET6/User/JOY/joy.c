/*
 * joy.c
 *
 *  Created on: Feb 4, 2024
 *      Author: YellowWenJie
 */
#include "joy.h"
#include "../NRF24L01/nrf24l01.h"
#include "stdio.h"
#include "../Motor/motor.h"

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
    ADC_Data[2] = (ADC_Data[2] > 0) ? ADC_Data[2] - 50 : 0;
    ADC_Data[3] = ADC_Data[3] + 10;
    //* 误差取整
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

    // //* 调整方向
    // ADC_Data[0] = ADC_Data[0];

    // ADC_Data[1] = 4000 - ADC_Data[1];

    // ADC_Data[2] = ADC_Data[2];

    // ADC_Data[3] = 4000 - ADC_Data[3];

    // for (size_t i = 0; i < 4; i++)
    // {
    //   ADC_Data[i] = ADC_Data[i] * 2;
    // }
  }

  return ADC_Data;
}

//* 摇杆控制小车逻辑
//***************************************************************************************************************

//* 小车前进
void Car_Direction(void)
{
  uint16_t *ADC_Value = NRF24Lo1_RX_Adjusted_ADC_Data();

  uint16_t speed;
  speed = ADC_Value[1];

  Directional_Control(Directional_Front);

  // //* 停止
  // if ((ADC_Value[1] == 4000 && ADC_Value[3] == 4000) || (ADC_Value[0] == ADC_Value[1] == ADC_Value[2] == ADC_Value[3] == 0))
  // {
  //   speed = 0;
  // }

  // //* 前进
  // else if (ADC_Value[1] > 4000 || ADC_Value[3] > 4000)
  // {
  //   Directional_Control(Directional_Front);
  //   speed = 8000 - ADC_Value[1] + ADC_Value[3];
  // }

  // //* 后退
  // else if (ADC_Value[1] < 4000 || ADC_Value[3] < 4000)
  // {
  //   Directional_Control(Directional_Back);
  //   speed = 8000 - ADC_Value[1] - ADC_Value[3];
  // }

  Set_Speed(speed);

  // HAL_Delay(1000);
  // Set_Pwm(Front_Left, 2000);
  // HAL_Delay(1000);
  // Set_Pwm(Front_Left, 0);

  // HAL_Delay(1000);
  // Set_Pwm(Front_Right, 2000);
  // HAL_Delay(1000);
  // Set_Pwm(Front_Right, 0);

  // HAL_Delay(1000);
  // Set_Pwm(Back_Left, 2000);
  // HAL_Delay(1000);
  // Set_Pwm(Back_Left, 0);

  // HAL_Delay(1000);
  // Set_Pwm(Back_Right, 2000);
  // HAL_Delay(1000);
  // Set_Pwm(Back_Right, 0);
}
