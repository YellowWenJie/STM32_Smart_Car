
#ifndef HC_SR04_H_
#define HC_SR04_H_

#include "stm32f4xx_hal.h"
#include "main.h"
#include "tim.h"

void for_delay_us(uint16_t nus);
void Start(void);
void start(void);
unsigned int get_stop(void);
void HC_SR04_Start(void);

#endif /* HC_SR04_H_ */
