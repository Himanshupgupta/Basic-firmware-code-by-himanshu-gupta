//USART2 bit 17 RCC_APB1ENR
//Set baud rate 9600bps 0x683
//USART_SR Status Register bit7
//buffer register USART_DR
//USART_CR1 bit 3
//USART2 TX conected to PA2

#include "stm32f4xx.h"
#include<stdio.h>

void USART2_Init(void);
void USART_TX(char ch)
int main(void)
{
	char Variable;
	USART2_Init();
	Variable=USART_RX();
	printf(%c,variable);
}

void USART2_Init(void)
{
	RCC->AHB1ENR |=1;         //Enable clock of port A
	GPIOA->MODER |=0x80;      //Set PA3 as Alternate Function Register
	RCC->APB1ENR |=0x20000;	  //Enable clock for usart2
	USART->BRR   |=0x683;     //Set baud rate 9600bps
	GPIOA->AFRL  |=0x700; 
	USART->CR1    =0x004;	  //Enable RX
	USART->CR1   |=0x2000;    //Enable USART
}

char USART_RX(void)
{
	while(!USART->SR & 0x20) //Wait for data to come into data register
	return USART->DR;
}