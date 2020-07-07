include "stm32f4xx.h"

void delay(int ms);
int main(void)
{
	//Init. PA5
	RCC->AHB1ENR  =0;           //Clock enabled for PORT A
	GPIOA->MODER  =0x400;       //SET PA5 as GPIO PIN
	
	//Init. Timer2
	RCC->APB1ENR  =1;           //Enable clock for Timer2
	TIM2->ARR     =1000-1;   
	TIM2->PSC     =16000-1;     //Timer2 become 1MHZ
	TIM2->CNT     =0;           //Clear Timer counter
	TIM2->CR1     =1;           //Enable timer2
	
	while(1)
	{
	GPIOA->ODR  ^=0x20;        //Toggle LED at PA5 
	delay(10);
	}
	
}

void delay(int ms)
{
	int i;
	for(i=0;i<ms;i++)
	while(!(TIM2->SR & 1));
	TIM2->SR &=~1;
}