#ifndef __NVIC_h
#define __NVIC_h
#include "stm32f4xx.h"  
void NVIC_SetMode(u8);
void NVIC_Priority(u8 preemption,u8 sub,u8 NVIC_Channel,u8 NVIC_Group);
#endif