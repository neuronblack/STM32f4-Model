#ifndef __USART_H 
#define __USART_H
#include "stm32f4xx.h" 
 extern u8 RxData[30];
 extern u16 RX_STA;
 void USART_Init(u32 pclk2,u32 bound);
#endif