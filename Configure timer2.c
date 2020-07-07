//Timer2 connected to APB1 RCC_APB1ENR SET bit 0
//

#include "stm32f4xx"


int main(void);
{
	//Configure the LED
	RCC->AHB1ENR =1; 
	GPIOA->MODER =0x400;
	
	//Configure Timer2
	RCC->APB1ENR  =0;        //SET Clock to timer2
	TIM2->ARR     =16000-1;
	TIM2->CNT     =0;
	TIM2->PSC     =1000-1;
	
	while(1)
	{
	GPIOA->ODR ^=0x20;
	delay(10);
	}
}

