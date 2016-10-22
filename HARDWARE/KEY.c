#include "stm32f4xx.h"                  // Device header
#include "KEY.H"
int key0=4;
void KEY_Init(){
	RCC->AHB1ENR|=1<<4;
	GPIOE->PUPDR&=~(3<<(2*key0));
	GPIOE->PUPDR|=1<<(2*key0);
}
