/*
 * MODEM.h
 *
 *  Created on: May 27, 2023
 *      Author: mosavi
 */

#ifndef USER_INCLUDE_MODEM_H_
#define USER_INCLUDE_MODEM_H_

#include "main.h"
#include "Default_C.h"
#include "HARDWARE_CONFIG.H"


//====================== EC200 Properties
#define EC200_TORN_ONOFF_Delay	3500
#define EC200_RESET_ONOFF_Delay	300

//===================== MODEM Properties
#define MODEM_TURN_ONOFF_DELAY	EC200_TORN_ONOFF_Delay
#define MODEM_RESET_DELAY		EC200_RESET_ONOFF_Delay
#define MODEM_UART_TIMEOUT_Tx	1000

typedef enum MODEM_STATUS
{
	MODEM_STATUS_UNKNOWN,
	MODEM_STATUS_TURN_ON,
	MODEM_STATUS_BUSY,
	MODEM_STATUS_IDLE,
	MODEM_STATUS_TURN_OFF,
}MODEM_STATUS;


typedef enum MODEM_GPIO_CTRL{
	MODEM_GPIO_CTRL_UNKNOWN,
	MODEM_GPIO_CTRL_NOT_Defined,
	MODEM_GPIO_CTRL_NONE,
	MODEM_GPIO_PWR_PIN,
	MODEM_GPIO_RST_PIN,
	MODEM_GPIO_RGL_PIN,
	MODEM_GPIO_PWR_RST,
	MODEM_GPIO_RGL_RST,
	MODEM_GPIO_ALL_PIN,
}MODEM_GPIO_CTRL;

typedef struct MODEM
{
	OBJ_HARDWARE 			HARDWARE_Config;
	HARDWARE_Validate_State Validation_State;
	HARDWARE_OPRATION_ERROR	OPRATION;
	MODEM_GPIO_CTRL 		GPIO_Control_Pin;
	MODEM_STATUS  			status;
	GPIO_CTRL_PIN 			MODEM_PWR;
	GPIO_CTRL_PIN 			MODEM_RST;
	GPIO_CTRL_PIN 			MODEM_RGL;
}MODEM;





bool MODEM_HARDWARE_RGL_PIN(MODEM *modem, GPIO_TypeDef* RGL_PORT,uint16_t RGL_PIN,bool SET_RGL_PIN,bool RESET_RGL_PIN);
bool MODEM_HARDWARE_PWR_PIN(MODEM *modem, GPIO_TypeDef* PWR_PORT,uint16_t PWR_PIN,bool SET_PWR_PIN,bool RESET_PWR_PIN);
bool MODEM_HARDWARE_RST_PIN(MODEM *modem, GPIO_TypeDef* RST_PORT,uint16_t RST_PIN,bool SET_RST_PIN,bool RESET_RST_PIN);
bool MODEM_HARDWARE_Init(MODEM *modem,HARDWARE_PROTOCOL HP,HARDWARE_PREPHERAL *Handler,HARDWARE_HANDLE_TYPE HHT,MODEM_GPIO_CTRL CTRL,DEVICE_TYPE Device);

bool MODEM_HARDWARE_RGL_ON_OFF(MODEM *modem,bool ON_OFF);
bool MODEM_HARDWARE_PWR_ON_OFF(MODEM *modem,bool ON_OFF);
bool MODEM_HARDWARE_RESET(MODEM *modem);
void MODEM_Identifire_Init(MODEM*modem, const char *Name, uint16_t ID);
bool MODEM_BUFFER_Init(MODEM*modem , uint16_t Buffer_Size);
DEVICE_ERROR MODEM_Validatin_Sequence(MODEM*modem);

bool MODEM_TRANSMIT_Data(MODEM* modem, OBJ_Buffer* buffer);
bool MODEM_RECIVED_Data(MODEM* modem,uint16_t Data_Size);
#endif /* USER_INCLUDE_MODEM_H_ */
