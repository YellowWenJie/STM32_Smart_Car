#include "HC_SR04.h"
#include "tim.h"

void for_delay_us(uint16_t nus) // 微秒级延时（循环）
{
  uint16_t i;
  for (i = 0; i < nus; i++)
  {
    __NOP();
  }
}

void Start(void) // 启动超声波模块
{
  HAL_GPIO_WritePin(Trig_GPIO_Port, Trig_Pin, 1); // 拉高
  for_delay_us(15);                               // 15us延时
  HAL_GPIO_WritePin(Trig_GPIO_Port, Trig_Pin, 0); // 拉低
}

int Get(void)
{
  return HAL_GPIO_ReadPin(Echo_GPIO_Port, Echo_Pin); // 获得Echo的电平高低
}

void start(void) // 开始计时
{
  __HAL_TIM_SetCounter(&htim6, 0); // 清0开始计数
  HAL_TIM_Base_Start_IT(&htim6);   // 开启定时器更新中断
}

unsigned int get_stop(void) // 获取停止之后的数据
{
  unsigned int num, dta;
  HAL_TIM_Base_Stop_IT(&htim6);       // 关闭定时器更新中断
  num = __HAL_TIM_GetCounter(&htim6); // 获得计数值
  dta = (num * 346) / 20000;          // cm为单位
  return dta;
}

void HC_SR04_Start(void)
{
  unsigned int dta;
  Start(); // 启动超声波模块
  LED1_ON;

  while (!Get())
    ;      // 当Echo返回0，等待,变为1继续
  start(); // 开始计时
  while (Get())
    ; // 当Echo为1计数并等待  ,变为0继续
  dta = get_stop();

  if (dta < 20)
  {
    LED1_OFF;
  }

  HAL_Delay(1000); // 延时
}