//USART2 bit 17 RCC_APB1ENR
//Set baud rate 9600bps 0x683
//USART_SR Status Register bit7
//buffer register USART_DR
//USART_CR1 bit 3
//USART2 TX conected to PA2

#include "stm32f4xx.h"

void USART2_Init(void);
void USART_TX(char ch)
int main(void)
{
	USART2_Init();
	USART_TX(Hi);
}

void USART2_Init(void)
{
	RCC->AHB1ENR |=1;         //Enable clock of port A
	GPIOA->MODER |=0x20;      //Set PA2 as Alternate Function Register
	RCC->APB1ENR |=0x20000;	  //Enable clock for usart2
	USART->BRR   |=0X683;     //Set baud rate 9600bps
	GPIOA->AFRL  |=0x700; 
	USART->CR1   |=0x008;	  //Enable TX
	USART->CR1   |=0x2000;    //Enable USART
}

void USART_TX(char ch)
{
	while(!USART->SR & 0x80)
	USART2->DR =ch&0xFF;
}