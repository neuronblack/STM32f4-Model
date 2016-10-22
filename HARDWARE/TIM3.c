#include "TIM3.h"
#include "stm32f4xx.h"                  // Device header
#include "sys.h"
void TIM3_Init(u16 arr,u16 psc){
	RCC->APB1ENR|=1<<1;
	TIM3->ARR=arr;
	TIM3->PSC=psc;
	TIM3->DIER|=0x01;
	TIM3->CR1|=0x01;
	MY_NVIC_Init(1,1,TIM3_IRQn,2);
}
void TIM3_IRQHandler(){
	if(TIM3->SR&0x001){
	GPIOA->ODR^=1<<6;
	}
	TIM3->SR&=~(1<<0);
	
}