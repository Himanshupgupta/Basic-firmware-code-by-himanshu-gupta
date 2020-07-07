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
	RCC->AHB1ENR |=1;
	GPIO->MODER  |=0x400;
	while(1)
	{
	GPIOA->ODR  |=0x20; //GPIO->BSRR =0x20; SET PA5
	delay(10);
	GPIOA->ODR  &=~0x20; //GPIO->BSRR =0x200000; RESET PA5
	delay(10);
	}
}

int delay(int ms)
{
	int i;
	for(;ms>0;ms--)
	for(i=0;i<3195;i);
	return 0;
}

/*
int delay(int ms)
{
int i,j;
for(i=0;i<ms;i++)
for(j=0;j<3195;j++);	
}*/