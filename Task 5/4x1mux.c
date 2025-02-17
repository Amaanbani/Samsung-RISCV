#include "ch32v00x.h"  // Include CH32V003 RISC-V support
#include <stdint.h>

// Define GPIO pins
#define D0 GPIO_Pin_0
#define D1 GPIO_Pin_1
#define D2 GPIO_Pin_2
#define D3 GPIO_Pin_3
#define S0 GPIO_Pin_4
#define S1 GPIO_Pin_5
#define Y  GPIO_Pin_6  // Output

void My_GPIO_Init(void) {  // Renamed to avoid conflict with library function
    // Enable GPIOC clock
    RCC->APB2PCENR |= RCC_APB2Periph_GPIOC;

    GPIO_InitTypeDef GPIO_InitStructure;

    // Configure Data inputs (D0-D3) as input pull-down
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;  // Input with pull-down resistor
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_InitStructure.GPIO_Pin = D0 | D1 | D2 | D3;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    // Configure Select inputs (S0, S1) as input pull-down
    GPIO_InitStructure.GPIO_Pin = S0 | S1;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    // Configure Output (Y) as output push-pull
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // Output push-pull
    GPIO_InitStructure.GPIO_Pin = Y;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
}

uint8_t Read_MUX_Output(void) {
    uint8_t sel0 = (GPIOC->INDR & (1 << S0)) ? 1 : 0;
    uint8_t sel1 = (GPIOC->INDR & (1 << S1)) ? 1 : 0;
    uint8_t data = 0;

    // Select the corresponding data pin (D0-D3) based on S0 and S1
    switch ((sel1 << 1) | sel0) {
        case 0b00: data = (GPIOC->INDR & (1 << D0)) ? 1 : 0; break;
        case 0b01: data = (GPIOC->INDR & (1 << D1)) ? 1 : 0; break;
        case 0b10: data = (GPIOC->INDR & (1 << D2)) ? 1 : 0; break;
        case 0b11: data = (GPIOC->INDR & (1 << D3)) ? 1 : 0; break;
    }

    return data;
}

void Set_Output(uint8_t value) {
    if (value) {
        GPIOC->BSHR = (1 << Y); // Set output high
    } else {
        GPIOC->BSHR = (1 << (Y + 16)); // Set output low
    }
}

int main(void) {
    SystemInit();  // Initialize system
    My_GPIO_Init();   // Configure GPIO

    while (1) {
        uint8_t output = Read_MUX_Output();
        Set_Output(output);
    }
}
