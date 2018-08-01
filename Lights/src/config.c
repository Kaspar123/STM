#include "config.h"

void Peripheral_Config() {
    RCC_Config();
    GPIO_Config();
    //TIM_Interrupt_Config();
    //TIM_Interrupt_Enable();
    DMA_Config();
    TIM_Config();
    DMA_Interrupt_Config();
    DMA_Interrupt_Enable();
}

void RCC_Config() {
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA | RCC_AHBPeriph_DMA1, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_1);
}

void GPIO_Config() {
    GPIO_InitTypeDef gpio;
    gpio.GPIO_Pin = GPIO_PWM_PIN;
    gpio.GPIO_Mode = GPIO_Mode_AF;
    gpio.GPIO_OType = GPIO_OType_PP;
    gpio.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &gpio);

    gpio.GPIO_Pin = GPIO_Pin_2;
    gpio.GPIO_Mode = GPIO_Mode_OUT;

    GPIO_Init(GPIOA, &gpio);

}

void DMA_Interrupt_Config() {
    NVIC_InitTypeDef interrupt;
    interrupt.NVIC_IRQChannel= DMA1_Channel5_IRQn;
    interrupt.NVIC_IRQChannelPreemptionPriority = 0;
    interrupt.NVIC_IRQChannelSubPriority = 0;
    interrupt.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&interrupt);
}

void TIM_Interrupt_Config() {
    NVIC_InitTypeDef interrupt;
    interrupt.NVIC_IRQChannel = TIM2_IRQn;
    interrupt.NVIC_IRQChannelPreemptionPriority = 0;
    interrupt.NVIC_IRQChannelSubPriority = 0;
    interrupt.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&interrupt);
}

void DMA_Interrupt_Enable() {
    DMA_ClearITPendingBit(DMA1_IT_TC5);
    DMA_ITConfig(DMA1_Channel5, DMA_IT_TC, ENABLE);
}

void TIM_Interrupt_Enable() {
    TIM_ClearITPendingBit(TIM2, TIM_IT_Update | TIM_IT_CC1);
    TIM_ITConfig(TIM2, TIM_IT_CC1, ENABLE);
}

void TIM_start() {
    TIM_Cmd(TIM2, ENABLE);
}

void TIM_stop() {
    TIM_Cmd(TIM2, DISABLE);
}

void TIM_Config() {
    TIM_TimeBaseInitTypeDef timerBase;
    TIM_OCInitTypeDef compare, compare2;

    /* PWM Time base configuration */
    timerBase.TIM_Period = PWM_TIM_PERIOD;
    timerBase.TIM_Prescaler = PWM_TIM_PRESCALER;
    timerBase.TIM_ClockDivision = 0;
    timerBase.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM2, &timerBase);

    /* PWM1 Mode configuration: Channel4 */
    compare.TIM_OCMode = TIM_OCMode_PWM1;
    compare.TIM_OutputState = TIM_OutputState_Enable;
    compare.TIM_Pulse = 0;       // this will be changed
    compare.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OC4Init(TIM2, &compare);

    /* Timer mode for interrupt */
    compare2.TIM_OCMode = TIM_OCMode_Timing;
    compare2.TIM_OutputState = TIM_OutputState_Enable;
    compare2.TIM_Pulse = PWM_LOW_WIDTH;        // ISR will be called here
    compare2.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OC1Init(TIM2, &compare2);

    TIM_DMACmd(TIM2, TIM_DMA_CC1, ENABLE);
    DMA_Cmd(DMA1_Channel5, DISABLE);
}

void DMA_Config() {
    DMA_InitTypeDef dma;
    DMA_DeInit(DMA1_Channel5);

    dma.DMA_M2M = DMA_M2M_Disable;
    dma.DMA_Mode = DMA_Mode_Normal;
    //dma.DMA_Mode = DMA_Mode_Circular;
    dma.DMA_Priority = DMA_Priority_Medium;
    dma.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
    dma.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Word;
    dma.DMA_MemoryInc = DMA_MemoryInc_Enable;
    dma.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    dma.DMA_DIR = DMA_DIR_PeripheralDST;
    dma.DMA_BufferSize = NUM_OF_BITS;

    dma.DMA_MemoryBaseAddr = (uint32_t) pulses;
    dma.DMA_PeripheralBaseAddr = (uint32_t) &TIM2->CCR4;
    DMA_Init(DMA1_Channel5, &dma);
}
