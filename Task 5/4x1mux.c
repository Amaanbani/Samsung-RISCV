#include <stdio.h>
#include <debug.h>
#include <ch32v00x.h>

void GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE); // Enable clock for Port C

    // Inputs: I0, I1, I2, I3
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    // Control: S0, S1
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    // Output: Y (MUX Output)
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
}

int main()
{
    uint8_t input_value = 0;
    uint8_t s0, s1;

    GPIO_Config();
    while(1)
    {
        // Read control lines
        s0 = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_4);
        s1 = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_5);

        // Select input based on S0 and S1
        if (s0 == RESET && s1 == RESET)
            input_value = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_0); // I0
        else if (s0 == RESET && s1 == SET)
            input_value = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_1); // I1
        else if (s0 == SET && s1 == RESET)
            input_value = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_2); // I2
        else
            input_value = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_3); // I3

        // Output selected input to Y
        GPIO_WriteBit(GPIOC, GPIO_Pin_6, input_value);

        Delay_Ms(100);// Delay before next check
    }
}
