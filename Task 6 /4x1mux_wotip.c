	#include <stdio.h>
	#include <debug.h>
	#include <ch32v00x.h>

	void GPIO_Config(void)
	{
	    GPIO_InitTypeDef GPIO_InitStructure = {0};
	    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE); // Enable clock for Port C

	    // Control: S0, S1 (input pins)
	    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;
	    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; // Input with pull-up
	    GPIO_Init(GPIOC, &GPIO_InitStructure);

	    // Output: Y (MUX output)
 	   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
     	   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; // Push-pull output
	   GPIO_Init(GPIOC, &GPIO_InitStructure);
		}

		// Incase to avoid giving input even for Selectlines 
		//void Toggle_S0_S1(void)
		//{
    			//    Toggle GPIO pins S0 (GPIO_Pin_4) and S1 (GPIO_Pin_5) using BSHR and BCR registers
			//    GPIOC->BSHR = GPIO_Pin_4 | GPIO_Pin_5;  // Set the bits (simulate high-to-low toggle)
			//    GPIOC->BCR = GPIO_Pin_4 | GPIO_Pin_5;   // Clear the bits (simulate low-to-high toggle)
		//}
		
	
	int main()
		{
 	   uint8_t  input_value = 0;
 	   uint8_t s0, s1;

 	   GPIO_Config();
	    while(1)
	    {
  		  for (uint8_t i = 0; i < 16; i++)
    	 	   {
      	                  // Set input values dynamically from 0000 to 1111 (0 to 15 in decimal)
    	                  uint8_t input0 = (i >> 0) & 1;  // Extract bit 0
    			  uint8_t input1 = (i >> 1) & 1;  // Extract bit 1
   	   	          uint8_t input2 = (i >> 2) & 1;  // Extract bit 2
   		          uint8_t input3 = (i >> 3) & 1;  // Extract bit 3

       	     // Read control lines (S0 and S1)
       	     s0 = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_4);
       	     s1 = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_5);

            // Select input based on S0 and S1
            if (s0 == RESET && s1 == RESET)
                input_value = input0; // Select I0
            else if (s0 == RESET && s1 == SET)
                input_value = input1; // Select I1
            else if (s0 == SET && s1 == RESET)
                input_value = input2; // Select I2
            else
                input_value = input3; // Select I3

            // Output the selected input value to the output pin Y
            GPIO_WriteBit(GPIOC, GPIO_Pin_6, input_value);

	            // Toggle S0 and S1 for the next iteration
            		//	Toggle_S0_S1();

			   
 	    Delay_Ms(100); // Delay before the next selection
 		   }
		}
	}
