#include "HC_SR04.h"
#include "tim.h"

void for_delay_us(uint16_t nus) // ΢�뼶��ʱ��ѭ����
{
  uint16_t i;
  for (i = 0; i < nus; i++)
  {
    __NOP();
  }
}

void Start(void) // ����������ģ��
{
  HAL_GPIO_WritePin(Trig_GPIO_Port, Trig_Pin, 1); // ����
  for_delay_us(15);                               // 15us��ʱ
  HAL_GPIO_WritePin(Trig_GPIO_Port, Trig_Pin, 0); // ����
}

int Get(void)
{
  return HAL_GPIO_ReadPin(Echo_GPIO_Port, Echo_Pin); // ���Echo�ĵ�ƽ�ߵ�
}

void start(void) // ��ʼ��ʱ
{
  __HAL_TIM_SetCounter(&htim6, 0); // ��0��ʼ����
  HAL_TIM_Base_Start_IT(&htim6);   // ������ʱ�������ж�
}

unsigned int get_stop(void) // ��ȡֹ֮ͣ�������
{
  unsigned int num, dta;
  HAL_TIM_Base_Stop_IT(&htim6);       // �رն�ʱ�������ж�
  num = __HAL_TIM_GetCounter(&htim6); // ��ü���ֵ
  dta = (num * 346) / 20000;          // cmΪ��λ
  return dta;
}

void HC_SR04_Start(void)
{
  unsigned int dta;
  Start(); // ����������ģ��
  LED1_ON;

  while (!Get())
    ;      // ��Echo����0���ȴ�,��Ϊ1����
  start(); // ��ʼ��ʱ
  while (Get())
    ; // ��EchoΪ1�������ȴ�  ,��Ϊ0����
  dta = get_stop();

  if (dta < 20)
  {
    LED1_OFF;
  }

  HAL_Delay(1000); // ��ʱ
}