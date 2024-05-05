/*
 * motor.h
 *
 *  Created on: Jan 21, 2024
 *      Author: YellowWenJie
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include "stm32f4xx_hal.h"
#include "main.h"

typedef enum
{
  Front_Left,
  Front_Right,
  Back_Left,
  Back_Right
} Motor_Single;

typedef enum
{
  // 前进
  Directional_Front,
  // 后退
  Directional_Back,

  // 左平�?
  Directional_Left,

  // 右平�?
  Directional_Right,

  // 左前平移
  Directional_Front_Left,

  // 右前平移
  Directional_Front_Right,

  // 左后平移
  Directional_Back_Left,

  // 右后平移
  Directional_Back_Right,

} Directional;

int myabs(int num);
void Motor(Motor_Single motor_single, uint8_t num);
void Set_Pwm(Motor_Single motor_single, int pwm);
void Set_Speed(int speed);
void Directional_Control(Directional direction);
extern int Speed;

#endif /* MOTOR_MOTOR_H_ */
