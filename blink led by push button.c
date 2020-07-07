//By Pressing PUSH BUTTON OFF the LED 
//PUSH BUTTON TO PC13(Need as input)
//LED Connected at PA5
//GPIO PORT A Connected to AHB1 BUS
//NEED to set PA5 as Output

//RCC_AHB1ENR (Enable clock-->First bit for port A)
//GPIOx_MODER (Enable PA5 as GPIO-->01 AS GPIO)
//GPIOx_ODR   (read or write the status of ports-->)
//GPIO->BSRR (SET or RESET THE GPIO PINS)
//user button connected to PC13 Active high state

#include "stm32f4xx.h"

int main()
{
	RCC->AHB1ENR |=1;
	RCC->AHB1ENR |=0x4;
	GPIO->MODER  |=0x400;
	
	while(1)
	{
	if(GPIOC->IDR & 0x2000)
		GPIOA->BSRR =0x200000; //RESET PA5
	else
		GPIOA->BSRR =0x20; //SET PA5
	}
	}
}
