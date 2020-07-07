//Timer2 connected to APB1 RCC_APB1ENR SET bit 0
//Want to toggle LED 20ms 

#include "stm32f4xx"

int main(void);
{
	//Configure the LED
	RCC->AHB1ENR =1;
	GPIOA->MODER =0x400;
	
	//Configure SysTick
	SysTick->LOAD  =320000-1;     //Load the register for 20ms
	SysTick->VALUE =0;            //SET The value of count register
	SysTick->CTRL  =5;            //Enable SysTick

	while(1)
	{
	if(SysTick->CTRL & 10000);    //Check if count flag is set
	GPIOA->ODR ^=0x20;
	}
}