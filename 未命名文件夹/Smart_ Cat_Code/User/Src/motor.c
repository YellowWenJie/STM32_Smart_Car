/*
 * motor.c
 *
 *  Created on: Jan 21, 2024
 *      Author: YellowWenJie
 */

#include "motor.h"
#include "tim.h"

int Speed = 0;

/*
 *	设置正反�?
 */
void Motor(Motor_Single motor_single, uint8_t num)
{

  switch (motor_single)
  {
  case Front_Left:
    if (num == 1)
    {
      HAL_GPIO_WritePin(Front_AIN1_GPIO_Port, Front_AIN1_Pin, GPIO_PIN_RESET); // 0
      HAL_GPIO_WritePin(Front_AIN2_GPIO_Port, Front_AIN2_Pin, GPIO_PIN_SET);   // 1
    }
    else
    {
      HAL_GPIO_WritePin(Front_AIN1_GPIO_Port, Front_AIN1_Pin, GPIO_PIN_SET);   // 1
      HAL_GPIO_WritePin(Front_AIN2_GPIO_Port, Front_AIN2_Pin, GPIO_PIN_RESET); // 0
    }
    break;

  case Front_Right:
    if (num == 1)
    {
      HAL_GPIO_WritePin(Front_BIN1_GPIO_Port, Front_BIN1_Pin, GPIO_PIN_RESET); // 0
      HAL_GPIO_WritePin(Front_BIN2_GPIO_Port, Front_BIN2_Pin, GPIO_PIN_SET);   // 1
    }
    else
    {
      HAL_GPIO_WritePin(Front_BIN1_GPIO_Port, Front_BIN1_Pin, GPIO_PIN_SET);   // 1
      HAL_GPIO_WritePin(Front_BIN2_GPIO_Port, Front_BIN2_Pin, GPIO_PIN_RESET); // 0
    }
    break;

  case Back_Left:
    if (num == 1)
    {
      HAL_GPIO_WritePin(Back_AIN1_GPIO_Port, Back_AIN1_Pin, GPIO_PIN_SET);   // 0
      HAL_GPIO_WritePin(Back_AIN2_GPIO_Port, Back_AIN2_Pin, GPIO_PIN_RESET); // 1
    }
    else
    {
      HAL_GPIO_WritePin(Back_AIN1_GPIO_Port, Back_AIN1_Pin, GPIO_PIN_RESET); // 1
      HAL_GPIO_WritePin(Back_AIN2_GPIO_Port, Back_AIN2_Pin, GPIO_PIN_SET);   // 0
    }
    break;

  case Back_Right:
    if (num == 1)
    {
      HAL_GPIO_WritePin(Back_BIN1_GPIO_Port, Back_BIN1_Pin, GPIO_PIN_RESET); // 1
      HAL_GPIO_WritePin(Back_BIN2_GPIO_Port, Back_BIN2_Pin, GPIO_PIN_SET);   // 0
    }
    else
    {
      HAL_GPIO_WritePin(Back_BIN1_GPIO_Port, Back_BIN1_Pin, GPIO_PIN_SET);   // 0
      HAL_GPIO_WritePin(Back_BIN2_GPIO_Port, Back_BIN2_Pin, GPIO_PIN_RESET); // 1
    }
    break;
  }
}

/*
 *	绝对�?
 */
int myabs(int num)
{
  int temp;
  if (num < 0)
    temp = -num;
  else
    temp = num;
  return temp;
}

/*
 *	设置电机速度以及真反�?
 */
void Set_Pwm(Motor_Single motor_single, int pwm)
{

  int pwmb_abs;
  if (pwm > 0 && pwm <= 8400)
  {
    Motor(motor_single, 1);
  }
  else if (pwm < 0 && pwm >= -8400)
  {
    Motor(motor_single, 0);
  }

  pwmb_abs = myabs(pwm);
  switch (motor_single)
  {
  case Front_Left:
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, pwmb_abs);
    break;

  case Front_Right:
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, pwmb_abs);
    break;
  case Back_Left:
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, pwmb_abs);
    break;
  case Back_Right:
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, pwmb_abs);
    break;
  }
}

/*
 *	设置速度
 ! 速度只能为正
 */
void Set_Speed(int speed)
{
  Speed = myabs(speed);
}

/*
 *	控制方向
 */
void Directional_Control(Directional direction)
{
  switch (direction)
  {
  case Directional_Front: //* 前进
    Set_Pwm(Front_Left, Speed);
    Set_Pwm(Front_Right, Speed);
    Set_Pwm(Back_Left, Speed);
    Set_Pwm(Back_Right, Speed);
    break;

  case Directional_Back: //* 后退
    Set_Pwm(Front_Left, -Speed);
    Set_Pwm(Front_Right, -Speed);
    Set_Pwm(Back_Left, -Speed);
    Set_Pwm(Back_Right, -Speed);
    break;

  case Directional_Left: //* 左移
    Set_Pwm(Front_Left, -Speed);
    Set_Pwm(Front_Right, Speed);
    Set_Pwm(Back_Left, Speed);
    Set_Pwm(Back_Right, -Speed);
    break;

  case Directional_Right: //* 右移
    Set_Pwm(Front_Left, Speed);
    Set_Pwm(Front_Right, -Speed);
    Set_Pwm(Back_Left, -Speed);
    Set_Pwm(Back_Right, Speed);
    break;

  case Directional_Front_Left: //* 左前平移
    Set_Pwm(Front_Left, 0);
    Set_Pwm(Front_Right, Speed);
    Set_Pwm(Back_Left, Speed);
    Set_Pwm(Back_Right, 0);
    break;

  case Directional_Front_Right: //* 右前平移
    Set_Pwm(Front_Left, Speed);
    Set_Pwm(Front_Right, 0);
    Set_Pwm(Back_Left, 0);
    Set_Pwm(Back_Right, Speed);
    break;

  case Directional_Back_Left: //* 左后平移
    Set_Pwm(Front_Left, -Speed);
    Set_Pwm(Front_Right, 0);
    Set_Pwm(Back_Left, 0);
    Set_Pwm(Back_Right, -Speed);
    break;

  case Directional_Back_Right: //* 右后平移
    Set_Pwm(Front_Left, 0);
    Set_Pwm(Front_Right, -Speed);
    Set_Pwm(Back_Left, -Speed);
    Set_Pwm(Back_Right, 0);
    break;

  default:
    break;
  }
}
