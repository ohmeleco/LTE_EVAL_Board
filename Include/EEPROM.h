/*
 * EEPROM.h
 *
 *  Created on: May 6, 2023
 *      Author: mosavi
 */

#ifndef USER_INCLUDE_EEPROM_H_
#define USER_INCLUDE_EEPROM_H_

#include "main.h"
#include "Default_C.h"
#include "HARDWARE_CONFIG.H"

//===== AT24C512 ===========
#define AT24C512_Size_Inbyte		65536
#define AT24C512_Size_InKbyte		128
#define AT24C512_PAGEWrite_Byte		128
#define AT24C512_ADDRESS_Byte		2
#define AT24C512_DEFAULT_ADDRESS	0xA0	//ALL address pin set to ground
//===== AT24C512 ===========
//===== BOARD SUPPORT PACKAGE =============
#define EEPROM_ADRESS_Byte AT24C512_ADDRESS_Byte
#define EEPROM_PAGEWRITE_DELAY_ms	5
#define EEPROM_Default_Timeout		10
//------------------------------------
#define EEPROM_PWR_Ctrl				1	//1: if you have a PIN to turn on/off EEPROM power PIN set this to one.
#define EEPROM_PWR_Enable			1	// if your E2PROM power pin is on by set a pin to one
#define EEPROM_PWR_Disable			0	// if your E2PROM power pin is off by set a pin to zero
#define EEPROM_PWR_PIN				I2C1_EN_Pin
#define EEPROM_PWR_PORT				I2C1_EN_GPIO_Port
#define EEPROM_WP_Ctrl				1	//1: if you have Write Protected Pin
#define EEPROM_WP_Enable			1
#define EEPROM_WP_DISABLE			0
#define EEPROM_WP_PIN				I2C1_WP_Pin
#define EEPROM_WP_PORT				I2C1_WP_GPIO_Port
//===== BOARD SUPPORT PACKAGE =============
typedef struct EEPROM
{
	OBJ_HARDWARE 	HARDWARE_Config;
	uint8_t 		EEPROM_ADDRESS;
	uint16_t 		Data_Size;
	uint16_t 		PAGE_Size_InByte;
	uint16_t 		SIZE_InKbit;
	uint32_t		Size_InByte;
	HARDWARE_Validate_State Validation_State;
	HARDWARE_OPRATION_ERROR	OPRATION;
}EEPROM;


bool EEPROM_HARDWARE_Init(EEPROM *e2prom,uint16_t E2PROM_Device_Address,uint16_t PAGE_Size,HARDWARE_PROTOCOL HP,HARDWARE_PREPHERAL *Handler,HARDWARE_HANDLE_TYPE HHT);
bool EEPROM_BUFFER_Init(EEPROM*e2prom , uint16_t Buffer_Size,uint8_t Number_Of_ADDRESS_Bytes);
void EEPROM_Identifire_Init(EEPROM*e2prom, const char *Name, uint16_t ID, uint32_t Size_InByte,uint16_t Size_InKByte,uint8_t Address);
DEVICE_ERROR EEPROM_Validatin_Sequence(EEPROM *e2prom);
bool EEPROM_OPRATION_CHECK(EEPROM*e2prom,bool OP_Type,uint16_t Address);

bool EEPROM_Write_Data(EEPROM *e2prom,uint8_t *DATA,uint16_t Size);
bool EEPROM_Send_Data(EEPROM *e2prom,uint16_t Address);
bool EEPROM_Read_Data(EEPROM *e2prom,uint16_t Address,uint32_t Size);

#endif /* USER_INCLUDE_EEPROM_H_ */
