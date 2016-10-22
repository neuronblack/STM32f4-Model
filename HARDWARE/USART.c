#include "USART.h"
#include "stm32f4xx.h"  
#include "stdio.h"
#include "sys.h"
#include "NVIC.h"// Device header
u8 RxData[30];
u16 RX_STA=0;
void USART_Init(u32 pclk2,u32 bound){
  u16 manissa;
	float temp;
	u16 fraction;
	temp=(float)(pclk2*1000000)/(bound*16);
	manissa=temp;
	fraction=(temp-manissa)*16;
	manissa<<=4;
	manissa+=fraction;
	RCC->AHB1ENR|=1<<0;	
	RCC->APB2ENR|=1<<4;
	GPIOA->MODER&=~(15<<18);
	GPIOA->MODER|=10<<18;
	GPIOA->AFR[1]&=~(15<<1);
	GPIOA->AFR[1]&=~(15<<2);
	GPIOA->AFR[1]|=7<<8;
	GPIOA->AFR[1]|=7<<4;
	USART1->BRR=manissa;
	
	NVIC_Priority(3,3,USART1_IRQn,2);
	USART1->CR1|=1<<2;
	USART1->CR1|=1<<5;
	
	USART1->CR1&=~(1<<15);
	USART1->CR1|=1<<3;
	USART1->CR1|=1<<13;
}


int fputc(int ch, FILE *f)
{      
	while((USART1->SR&0X40)==0);
	USART1->DR = (u8) ch;      
	return ch;
}