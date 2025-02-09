#include "ch32v003fun.h"  // Include CH32V003 RISC-V support
#include <stdint.h>

// Define GPIO pins
#define D0 PC0
#define D1 PC1
#define D2 PC2
#define D3 PC3
#define S0 PC4
#define S1 PC5
#define Y  PC6  // Output

void GPIO_Init(void) {
    // Enable GPIO ports
    RCC->APB2PCENR |= RCC_APB2Periph_GPIOC;

    // Configure Data inputs (D0-D3) as input
    GPIOC->CFGLR &= ~(0xF << (D0 * 4)); // PC0 Input
    GPIOC->CFGLR &= ~(0xF << (D1 * 4)); // PC1 Input
    GPIOC->CFGLR &= ~(0xF << (D2 * 4)); // PC2 Input
    GPIOC->CFGLR &= ~(0xF << (D3 * 4)); // PC3 Input

    // Configure Select inputs (S0, S1) as input
    GPIOC->CFGLR &= ~(0xF << (S0 * 4)); // PC4 Input
    GPIOC->CFGLR &= ~(0xF << (S1 * 4)); // PC5 Input

    // Configure Output (Y) as output push-pull
    GPIOC->CFGLR &= ~(0xF << (Y * 4));  // Clear PC6 settings
    GPIOC->CFGLR |= (0x3 << (Y * 4));   // Set PC6 as output push-pull
}

uint8_t Read_MUX_Output(void) {
    uint8_t sel0 = (GPIOC->INDR & (1 << S0)) ? 1 : 0;
    uint8_t sel1 = (GPIOC->INDR & (1 << S1)) ? 1 : 0;
    uint8_t data = 0;

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
    GPIO_Init();   // Configure GPIO

    while (1) {
        uint8_t output = Read_MUX_Output();
        Set_Output(output);
    }
}

