#include "stm32f4xx.h"                  // Device header
#include "DELAY.h"
static u16 us=0;
static u16  ms=0;
void delayinit(int sys){
	SysTick->CTRL&=~(1<<2);
	us=sys/8;
	ms=us*1000;
}
void delayus(int time){
	int temp;
	SysTick->LOAD=us*time;
	SysTick->VAL=0x00;
	SysTick->CTRL=0x01;
	do{
		temp=SysTick->CTRL;
	}while((temp&0x01)&&!(temp&1<<16));
	SysTick->CTRL=0x00;      	 			
	SysTick->VAL =0X00; 
	
}
void delaynms(int time){
	int temp;
	SysTick->LOAD=ms*time;
	SysTick->VAL=0x00;
	SysTick->CTRL=0x01;
	do{
		temp=SysTick->CTRL;
	}while((temp&0x01)&&!(temp&1<<16));
	SysTick->CTRL=0x00;      	 			
	SysTick->VAL =0X00; 
}
void delayms(int time){
	int num=time/540;
	int last=time%540;
	while(num){
		num--;
		delaynms(540);
	}
	delaynms(last);
}