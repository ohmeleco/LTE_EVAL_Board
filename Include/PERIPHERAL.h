/*
 * Prepheral.h
 *
 *  Created on: Aug 24, 2023
 *      Author: Acer
 */

#ifndef USER_INCLUDE_PERIPHERAL_H_
#define USER_INCLUDE_PERIPHERAL_H_

#include "Default_C.h"
#include "main.h"

#define Information_Size 	 		 32
#define HAL_NAME_Size 	 	 		 10
#define PERIPHERAL_List_Default_Size 10
typedef enum PERIPHERAL_TYPE
{
	PERIPHERAL_TYPE_NONE,
	PERIPHERAL_TYPE_GPIO_INPUT,
	PERIPHERAL_TYPE_GPIO_OUTPUT,
	PERIPHERAL_TYPE_GPIO_EXTI,
	PERIPHERAL_TYPE_TIMER_ONE_SHOUT,
	PERIPHERAL_TYPE_TIMER_PERIODIC,
	PERIPHERAL_TYPE_TIMER_OC,
	PERIPHERAL_TYPE_TIMER_IC,
	PERIPHERAL_TYPE_ADC,
	PERIPHERAL_TYPE_DAC,
	PERIPHERAL_TYPE_I2C,
	PERIPHERAL_TYPE_SPI,
	PERIPHERAL_TYPE_UART,
	PERIPHERAL_TYPE_SDIO,
	PERIPHERAL_TYPE_USB,
	PERIPHERAL_TYPE_ETH,
	PERIPHERAL_TYPE_RTC,
	PERIPHERAL_TYPE_QSPI,
	PERIPHERAL_TYPE_FSMC,
} PERIPHERAL_TYPE;

typedef struct PERIPHERAL_Str
{
	PERIPHERAL_TYPE PERIPHERAL;
	OBJ_Identifier ID;
	uint8_t index;
	char Peripheral_Info [Information_Size];
	char HAL_Name[HAL_NAME_Size];
}PERIPHERAL_Str;

bool OBJ_Peripheral_init(PERIPHERAL_TYPE type,char* ID_Name,uint16_t ID ,char* Info_txt,char*HAL_Name);
PERIPHERAL_Str* GET_Peripheral_List(void);
uint8_t 		Get_Peripheral_Conter(void);
bool EDIT_Peripheral_List_Info_txt(char* HAL_Name,char* Info_text);
bool Get_Peripheral_index(char* HAL_Name, uint8_t *Index);
bool EDIT_Peripheral_List_Info_ByIndex(uint8_t Index,char* Info_text);
#endif /* USER_INCLUDE_PERIPHERAL_H_ */
