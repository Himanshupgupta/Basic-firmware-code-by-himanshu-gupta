//LED Connected at PA5
//GPIO PORT A Connected to AHB1 BUS
//NEED to set PA5 as Output
//RCC_AHB1ENR (Enable clock-->First bit for port A)
//GPIOx_MODER (Enable PA5 as GPIO-->01 AS GPIO)
//GPIOx_ODR   (read or write the status of ports-->)
//GPIO->BSRR (SET or RESET THE GPIO PINS)

#include "stm32f4xx.h"

int main()
{
	RCC->AHB1ENR    =1;              //Enable clock access to PA5
	GPIOA->MODER    =0x400;          //SET PA5 as GPIO mode
	RCC->AHB1ENR   |=4;              //Enable clock access to PC13
				
	RCC->APB2ENR    =0x4000;           //Enable clock access to SYSCFG(External Interrupt)
	SYSCFG->EXTICR4 =0x20;             //Select PORTC for EXTI 
	EXTI->IMR       =0x2000;           //Unmask the EXTI13
	EXTI->FTSR      =0x2000;           //Select Falling edge trigger to EXTI13
	
	while(1)
	{
	while(!(EXTI->PR & 0x2000));
	GPIOA->BSRR =0x20;
	delay(10);
	GPIOA->BSRR &=~0x20;
	delay(10);
	EXTI->PR  =0x2000;                 //Clear PR register
	}		
}


int delay(int ms)
{
	int i;
	for(;ms>0;ms--)
	for(i=0;i<3195;i);
	return 0;
}
