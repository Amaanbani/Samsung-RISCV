#include "ch32v00x.h"  // Include CH32V003 RISC-V support
#include <stdint.h>
#include <stdio.h>

#define D0 0
#define D1 1
#define D2 2
#define D3 3
#define S0 4
#define S1 5
#define Y  6

// Renamed to avoid conflict with the SDK's GPIO_Init
void My_GPIO_Init(void) {
    // Enable GPIOC clock
    RCC->APB2PCENR |= RCC_APB2Periph_GPIOC;

    // Configure PC6 (Y) as output
    GPIOC->CFGLR &= ~(0xF << (Y * 4));  // Clear previous configuration
    GPIOC->CFGLR |= (0x3 << (Y * 4));   // Output push-pull
}

// Simulated input variables
uint8_t simulated_D[4] = {0, 0, 0, 0};  // Simulated Data inputs (D0-D3)
uint8_t simulated_S[2] = {0, 0};        // Simulated Select inputs (S0-S1)

uint8_t Read_MUX_Output(void) {
    uint8_t sel = (simulated_S[1] << 1) | simulated_S[0];
    return simulated_D[sel];  // Select the corresponding input
}

void Set_Output(uint8_t value) {
    if (value) {
        GPIOC->BSHR = (1 << Y); // Set output high
    } else {
        GPIOC->BSHR = (1 << (Y + 16)); // Set output low
    }
}

// Delay function (busy-wait loop instead of usleep)
void delay(uint32_t time) {
    while (time--) {
        __NOP();  // No operation instruction for delay (useful for small delays)
    }
}

void Simulate_Input_Toggle(void) {
    for (uint8_t i = 0; i < 4; i++) {
        for (uint8_t j = 0; j < 4; j++) {
            // Toggle selection lines (S0, S1)
            simulated_S[0] = j & 0x01;
            simulated_S[1] = (j >> 1) & 0x01;

            // Toggle data inputs (D0-D3)
            simulated_D[0] = (i & 0x01) ? 1 : 0;
            simulated_D[1] = (i & 0x02) ? 1 : 0;
            simulated_D[2] = (i & 0x04) ? 1 : 0;
            simulated_D[3] = (i & 0x08) ? 1 : 0;

            // Read MUX output and set LED accordingly
            uint8_t output = Read_MUX_Output();
            Set_Output(output);

            // Print simulated state (for debugging)
            printf("D: [%d %d %d %d] | S: [%d %d] => Y: %d\n",
                   simulated_D[3], simulated_D[2], simulated_D[1], simulated_D[0],
                   simulated_S[1], simulated_S[0], output);

            delay(1000000); // 5-second delay (tune the value based on your MCU clock speed)
        }
    }
}

int main(void) {
    SystemInit();    // Initialize the system (set up the MCU)
    My_GPIO_Init();  // Initialize GPIOs (renamed)

    while (1) {
        Simulate_Input_Toggle();
    }
}
