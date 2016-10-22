#include "NVIC.h"
#include "stm32f4xx.h"                  // Device header
void NVIC_SetMode(u8 NVIC_Group){
	u32 temp,temp1;	  
	temp1=(~NVIC_Group)&0x07;
	temp1<<=8;
	temp=SCB->AIRCR;
	temp&=0X0000F8FF;
	temp|=0X05FA0000;
	temp|=temp1;	   
	SCB->AIRCR=temp;
}
void NVIC_Priority(u8 preemption,u8 sub,u8 NVIC_Channel,u8 NVIC_Group){
	u32 temp;
	NVIC_SetMode(NVIC_Group);
	temp=preemption<<(4-NVIC_Group);
	temp|=sub>>NVIC_Group;
	temp&=0x0f;
	NVIC->ISER[NVIC_Channel/32]|=1<<(NVIC_Channel%32);
	NVIC->IP[NVIC_Channel]&=~(15<<4);
	NVIC->IP[NVIC_Channel]|=temp<<4;
	
}