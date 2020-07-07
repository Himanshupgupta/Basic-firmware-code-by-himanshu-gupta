//Timer2 connected to APB1 RCC_APB1ENR SET bit 0
//Want to toggle LED 20ms 

#include "stm32f4xx"

void delay(int ms);
int main(void);
{
	//Configure the LED
	RCC->AHB1ENR =1; 
	GPIOA->MODER =0x400;
	
	//Configure SysTick
	SysTick->LOAD  =16000-1;     //Load the register for 1ms
	SysTick->VALUE =0;            //SET The value of count register
	SysTick->CTRL  =5;            //Enable SysTick

	while(1)
	{
	GPIOA->ODR ^=0x20;
	delay(10);
	}
}

void delay(int ms)
{
	for(i=0;i<n;i++)
	//wait for count flag to SET
	while(SysTick->CTRL & 10000);	
}