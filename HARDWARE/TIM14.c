#include "stm32f4xx.h"                  // Device header
#include "TIM14.h"

void TIM14_Init(u16 arr,u16 psc){
	RCC->APB1ENR|=1<<8;
	RCC->AHB1ENR|=1<<0;
	
	GPIOA->MODER&=~(3<<14);
	GPIOA->MODER|=2<<14;
	GPIOA->PUPDR&=~(3<<14);
	GPIOA->PUPDR|=1<<14;
	GPIOA->OTYPER&=~(1<<7);
	GPIOA->OSPEEDR&=~(3<<14);
	GPIOA->OSPEEDR|=2<<14;
	GPIOA->AFR[0]&=~(15<<28);
	GPIOA->AFR[0]|=9<<28;
	
	TIM14->ARR=arr;
	TIM14->PSC=psc;
	
	TIM14->CCMR1&=~(8<<4);
	TIM14->CCMR1|=6<<4;
	TIM14->CCMR1|=1<<3;
	TIM14->CCER|=1<<1;
	TIM14->CCER|=1<<0;
	TIM14->CR1|=1<<7;
	TIM14->CR1|=1<<0;

}