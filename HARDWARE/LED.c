#include "stm32f4xx.h"    
#include "LED.h"
int ledpinA=6;
int ledpinB=7;
void LED_Init(){
	RCC->AHB1ENR|=1<<0;
	GPIOA->MODER&=~(3<<(2*ledpinA));
	GPIOA->MODER|=1<<(2*ledpinA);
	GPIOA->OSPEEDR&=~(3<<(2*ledpinA));
	GPIOA->OSPEEDR|=2<<(2*ledpinA);
	GPIOA->OTYPER&=~(1<<ledpinA);
	
	RCC->AHB1ENR|=1<<0;
	GPIOA->MODER&=~(3<<(2*ledpinB));
	GPIOA->MODER|=1<<(2*ledpinB);
	GPIOA->OSPEEDR&=~(3<<(2*ledpinB));
	GPIOA->OSPEEDR|=2<<(2*ledpinB);
	GPIOA->OTYPER&=~(1<<ledpinB);

}// Device header
