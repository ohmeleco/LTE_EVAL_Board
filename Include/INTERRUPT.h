/*
 * INTERRUPT.h
 *
 *  Created on: Aug 24, 2023
 *      Author: Acer
 */

#ifndef USER_INCLUDE_INTERRUPT_H_
#define USER_INCLUDE_INTERRUPT_H_
#include "main.h"
#include "Default_C.h"


#define Default_Interrupt_Size	16


typedef enum INTERRUPT_Type
{
	Interrupt_Type_None,
	Interrupt_Type_EXTI,
	Interrupt_Type_Timer,
	Interrupt_Type_UART,
	Interrupt_Type_UART_DMA,
	Interrupt_Type_I2C,
	Interrupt_Type_I2C_DMA,
	Interrupt_Type_SPI,
	Interrupt_Type_SPI_DMA,
	Interrupt_Type_ADC,
	Interrupt_Type_ADC_DMA,
}INTERRUPT_Type;

typedef enum INTERRUPT_MODE
{
	INTERRUPT_MODE_TIMER_OVF,
	INTERRUPT_MODE_TIMER_RICH_HALF,
	INTERRUPT_MODE_UART_RX_OVF,
	INTERRUPT_MODE_UART_RX_RICH_HALF,
	INTERRUPT_MODE_UART_TX_OVF,
	INTERRUPT_MODE_UART_TX_RICH_HALF,
	INTERRUPT_MODE_EXTI,
	INTERRUPT_MODE_EXTI_RISING,
	INTERRUPT_MODE_EXTI_FALLING,
	INTERRUPT_MODE_ADC,
	INTERRUPT_MODE_DAC,
	INTERRUPT_MODE_SPI_TX_OVF,
	INTERRUPT_MODE_SPI_RX_OVF,
}INTERRUPT_MODE;

typedef struct INTERRUPT_Struct
{
	volatile bool Interrupt;
	uint8_t HAL_Number;
	OBJ_Identifier ID;
	INTERRUPT_Type type;
	INTERRUPT_MODE MODE;
	uint8_t Priority_Main;
	uint8_t Priority_Sub ;
}INTERRUPT_Struct;

bool OBJ_Interrupt_init(INTERRUPT_Type type,char* ID_Name,uint16_t ID_Number,uint8_t Priority_Main,uint8_t Priority_Sub,uint8_t HAL_Number);
uint8_t Get_Interrupt_Conter(void);
INTERRUPT_Struct* Get_Interrupt_List(void);

#endif /* USER_INCLUDE_INTERRUPT_H_ */
