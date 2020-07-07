//Make PA1 as analog input


include "stm32f4xx.h"

int main(void)
{
//Config. PA1 as analog input
RCC->AHB1ENR  =1;         // Enable clock access for port AHB1ENR
GPIOA->MODER  =0xC;       //Set PA1 as Analog pin

//Config. ADC1
RCC->APB2ENR  =0x100;     //Enable clock ccess to ADC1
ADC1->CR2     =0;         //Init ADC with value=0
ADC->SQR3     =1;         //Enable scanner
ADC1->CR2    !=1;         //Enable ADC
}

while(1)
{
ADC->CR2    =0x40000000;  //Start ADC Conversion
while(!(ADC->SR & 2));
ADC->SR   &=~2;
double(Analog_value)= ADC->DR;   //Read the analog value
}