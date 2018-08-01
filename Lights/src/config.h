#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <stm32f30x.h>
#include "layout.h"

// signal generation parameters
#define GPIO_PWM_PIN        GPIO_Pin_3
#define PWM_TIM_PRESCALER   3
#define PWM_TIM_PERIOD      60
#define PWM_HIGH_WIDTH      25
#define PWM_LOW_WIDTH       3

//Prototypes
void Peripheral_Config();
void RCC_Config();
void GPIO_Config();
void TIM_Config();
void DMA_Config();

void TIM_Interrupt_Config();
void TIM_Interrupt_Enable();
void TIM_start();
void TIM_stop();


#endif
