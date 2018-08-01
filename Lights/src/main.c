#include <stm32f30x.h>
#include "operations.h"

FlagStatus dma_complete = SET;

void draw(void (*fn)(void)) {
    while (dma_complete != SET);
    fn();   // do the stuff
    DMA_SetCurrDataCounter(DMA1_Channel5, NUM_OF_BITS);
    dma_complete = RESET;
    DMA_Cmd(DMA1_Channel5, ENABLE);
}

void DMA1_Channel5_IRQHandler() {
    if (DMA_GetITStatus(DMA1_IT_TC5) == SET) {
        DMA_Cmd(DMA1_Channel5, DISABLE);
        DMA_ClearITPendingBit(DMA1_IT_TC5);
        dma_complete = SET;
    }
}

void doStuff() {
    // orange : rgb(127, 50, 0)
    for (uint16_t i = 0; i < 72; i++) setLED(i, 15, 5, 0);
    //print_sign(r_turn, 16, 30, , 0);
    //print_sign(r_light, 16, 15, 0, 0);
    //shiftLeft(false);
    //shiftLeft(false);
}

int main() {
    Peripheral_Config();
    TIM_start();

    //writeText("KADI");
    clear();
    draw(doStuff);
    //while (checkIfTextIsPresent(true)) {
      //  draw(doStuff);
    //}

    while(1) {
    }
    return 0;
}
