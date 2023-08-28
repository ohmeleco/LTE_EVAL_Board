/*
 * HARDWARE_CONFIG.c
 *
 *  Created on: May 8, 2023
 *      Author: mosavi
 */

#include "HARDWARE_CONFIG.h"


static bool 	UART_MODULE_EN=false,
				USART_MODULE_EN=false,
				TIM_MODULE_EN=false,
				SPI_MODULE_EN=false,
				I2C_MODULE_EN=false,
				RTC_MODULE_EN=false;

void HARDWARE_CONFIG_SCAN_Prepheral(void)
{
	if(DEFINE_I2C_MODULE_EN)
		UART_MODULE_EN=true;
	else
		UART_MODULE_EN=false;

	if(DEFINE_USART_MODULE_EN)
		USART_MODULE_EN=true;
	else
		USART_MODULE_EN=false;

	if(DEFINE_TIM_MODULE_EN)
		TIM_MODULE_EN=true;
	else
		TIM_MODULE_EN=false;
	if(DEFINE_I2C_MODULE_EN)
		SPI_MODULE_EN=true;
	else
		SPI_MODULE_EN=false;
	if(DEFINE_SPI_MODULE_EN)
		SPI_MODULE_EN=true;
	else
		SPI_MODULE_EN=false;
	if(DEFINE_RTC_MODULE_EN)
		RTC_MODULE_EN=true;
	else
		RTC_MODULE_EN=false;
}

bool GET_SPI_MODULE_DEFINITION(void)
{
	return SPI_MODULE_EN;
}
bool GET_I2C_MODULE_DEFINITION(void)
{
	return I2C_MODULE_EN;
}
bool GET_USART_MODULE_DEFINITION(void)
{
	return USART_MODULE_EN;
}
bool GET_UART_MODULE_DEFINITION(void)
{
	return UART_MODULE_EN;
}
bool GET_TIM_MODULE_DEFINITION(void)
{
	return TIM_MODULE_EN;
}
bool GET_RTC_MODULE_DEFINITION(void)
{
	return RTC_MODULE_EN;
}


