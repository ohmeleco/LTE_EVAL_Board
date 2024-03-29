/*
 * HARDWARE_CONFIG.H
 *
 *  Created on: Jan 31, 2023
 *      Author: mosavi
 */

#ifndef USER_FILE_HARDWARE_CONFIG_H_
#define USER_FILE_HARDWARE_CONFIG_H_


#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "Default_C.h"
#include "main.h"


#ifdef HAL_UART_MODULE_ENABLED
#include "usart.h"
#define DEFINE_UART_MODULE_EN 1
#else
#define DEFINE_UART_MODULE_EN 0
#endif

#ifdef HAL_USART_MODULE_ENABLED
#include "usart.h"
#define DEFINE_USART_MODULE_EN 1
#else
#define DEFINE_USART_MODULE_EN 0
#endif

#ifdef HAL_TIM_MODULE_ENABLED
#include "tim.h"
#define DEFINE_TIM_MODULE_EN 1
#else
#define DEFINE_TIM_MODULE_EN 0
#endif

#ifdef HAL_SPI_MODULE_ENABLED
#include "spi.h"
#define DEFINE_SPI_MODULE_EN 1
#else
#define DEFINE_SPI_MODULE_EN 0
#endif

#ifdef HAL_I2C_MODULE_ENABLED
#include "i2c.h"
#define DEFINE_I2C_MODULE_EN 1
#else
#define DEFINE_I2C_MODULE_EN 0
#endif

#ifdef HAL_RTC_MODULE_ENABLED
#include "rtc.h"
#define DEFINE_RTC_MODULE_EN 1
#else
#define DEFINE_RTC_MODULE_EN 0
#endif

/* Private Typedef -----------------------------------------------------------*/
typedef struct GPIO_CTRL_PIN
{
	bool 	 SET_PIN_State;
	bool	 RESET_PIN_State;
	GPIO_TypeDef* PORT;
	uint16_t PIN;
	bool Validate_Pin;
}GPIO_CTRL_PIN;

typedef enum HARDWARE_Validate_State
{
	HARDWARE_VALIDATION_UNCHECKED,
	HARDWARE_VALIDATION_UNKNOWN,
	HARDWARE_VALIDATION_OK,
	HARDWARE_VALIDATION_ERROR,
}HARDWARE_Validate_State;
typedef enum HARDWARE_OPRATION_ERROR
{
	HARDWARE_OPRATION_UNKNOWN,
	HARDWARE_OPRATION_FEIL,
	HARDWARE_OPRATION_BUFFER_FEIL,
	HARDWARE_OPRATION_VALIDATION_Error,
	HARDWARE_OPRATION_WRITE_DONE,
	HARDWARE_OPRATION_READ_DONE,
	HARDWARE_OPRATION_BUFFER_NOTenough_Space,
	HARDWARE_OPRATION_READ_NOTenough_Space,
	HARDWARE_OPRATION_READ_Address_NOT_VAlid,
	HARDWARE_OPRATION_WRITE_NOTenough_Space,
	HARDWARE_OPRATION_WRITE_Address_NOT_VAlid,
	HARDWARE_OPRATION_READ_SIZE_ERROR,
	HARDWARE_OPRATION_WRITE_SIZE_ERROR,
	HARDWARE_OPRATION_WRITE_HW_ERROR,
	HARDWARE_OPRATION_READ_HW_ERROR,
	HARDWARE_OPRATION_GPIO_CTRL_NotDefined,
	HARDWARE_OPRATION_Transmit_Done,
	HARDWARE_OPRATION_Recive_Done,
}HARDWARE_OPRATION_ERROR;
typedef enum DEVICE_ERROR
{
	DEVICE_ERROR_UNKNOWN,
	DECIVE_ERROR_MEMORY_SIZE_ERROR,
	DECIVE_ERROR_MEMORY_ADDRESS_ERROR,
	DECIVE_ERROR_BUFFE_INIT_FAIL,
	DECIVE_ERROR_IDENTIFIER_INIT_FAIL,
	DEVICE_ERROR_DEVICE_TYPE_NOT_Recognized,
	DEVICE_ERROR_MEMORY_TYPE_NOT_Recognized,
	DEVICE_ERROR_MODEM_TYPE_NOT_Recognized,
	DEVICE_ERROR_EEPROM_INTERNAL_ERROR,
	DEVICE_ERROR_FLASH_INTERNAL_ERROR,
	DEVICE_ERROR_SDCARD_INTERNAL_ERROR,
	DEVICE_ERROR_SRAM_INTERNAL_ERROR,
	DEVICE_ERROR_SDRAM_INTERNAL_ERROR,
	DEVICE_ERROR_DRAM_INTERNAL_ERROR,
	DEVICE_ERROR_USBFLASH_INTERNAL_ERROR,
	DEVICE_ERROR_QUECTEL_INTERNAL_ERROR,
	DEVICE_ERROR_SIMCOM_INTERNAL_ERROR,
	DEVICE_ERROR_ESPWIFI_INTERNAL_ERROR,
	DEVICE_ERROR_ESPBLUETOTH_INTERNAL_ERROR,
	DEVICE_ERROR_ISM_RADIO_INTERNAL_ERROR,
	DEVICE_ERROR_ISM_NRF_INTERNAL_ERROR,
	DEVICE_ERROR_PROTOCOL_NOT_FOUDND,
	DEVICE_ERROR_PROTOCOL_NOT_CORRECT,
	DEVICE_ERROR_PROTOCOL_USB_INTERNAL_ERROR,
	DEVICE_ERROR_PROTOCOL_I2C_INTERNAL_ERROR,
	DEVICE_ERROR_PROTOCOL_USART_INTERNAL_ERROR,
	DEVICE_ERROR_PROTOCOL_USART_NOT_ASSIGNET,
	DEVICE_ERROR_PROTOCOL_SPI_INTERNAL_ERROR,
	DEVICE_ERROR_PROTOCOL_ETHERNET_INTERNAL_ERROR,
	DEVICE_ERROR_PROTOCOL_SDIO_INTERNAL_ERROR,
	DEVICE_ERROR_HANDLE_TYPE_NOT_FOUND,
	DEVICE_ERROR_HANDLE_DMA_INTERNAL_ERROR,
	DEVICE_ERROR_HANDLE_DMA_TIMER_INTERNAL_ERROR,
	DEVICE_ERROR_HANDLE_IT_INTERNAL_ERROR,
	DEVICE_ERROR_HANDLE_IT_TIMER_INTERNAL_ERROR,
	DEVICE_ERROR_HANDLE_POLLING_INTERNAL_ERROR,
	DEVICE_ERROR_HANDLE_POLING_TIMER_INTERNAL_ERROR,
	DEVICE_ERROR_NO_EEROR_REPORTED,
	DEVICE_ERROR_CTRL_GPIO_NOT_DEFINED,
	DEVICE_ERROR_CTRL_GPIO_NOT_COMPATIBLE,
	DEVICE_ERROR_CTRL_GPIO_SET_RESET_ERROR,
}DEVICE_ERROR;
typedef enum DEVICE_TYPE
{
	DEVICE_TYPE_UNKNOWN,
	DEVICE_TYPE_MEMORY_EEPROM,
	DEVICE_TYPE_MEMORY_FLASH,
	DEVICE_TYPE_MEMORY_SDCARD,
	DEVICE_TYPE_MEMORY_SRAM,
	DEVICE_TYPE_MEMORY_SDRAM,
	DEVICE_TYPE_MEMORY_DRAM,
	DEVICE_TYPE_USB_FLASH,
	DEVICE_TYPE_MODEM,
	DEVICE_TYPE_MODEM_QUECTEL,
	DEVICE_TYPE_MODEM_SIMCOM,
	DEVICE_TYPE_ESP8266,
	DEVICE_TYPE_ESP8266_WIFI,
	DEVICE_TYPE_ESP8266_BLUETOOTH,
	DEVICE_TYPE_ISM_RADIO,
	DEVICE_TYPE_ISM_NRF,
}DEVICE_TYPE;

typedef enum HARDWARE_PROTOCOL
{
	HARDWARE_PROTOCOL_UNKNOWN,
	HARDWARE_PROTOCOL_USART,
	HARDWARE_PROTOCOL_I2C,
	HARDWARE_PROTOCOL_SPI,
	HARDWARE_PROTOCOL_USB,
	HARDWARE_PROTOCOL_ETHERNET,
	HARDWARE_PROTOCOL_SDIO,
}HARDWARE_PROTOCOL;

typedef enum HARDWARE_HANDLE_TYPE
{
	Hardware_Handle_UNKNOWN,
	Hardware_Handle_NORMAL,
	Hardware_Handle_DMA,
	Hardware_Handle_DMA_Timer,
	Hardware_Handle_IT,
	Hardware_Handle_IT_Timer,
	Hardware_Handle_Polling,
	Hardware_Handle_Polling_Timer,
}HARDWARE_HANDLE_TYPE;

typedef struct HARDWARE_CONFIG{
	HARDWARE_PROTOCOL 	 Hardware_Protocol;
	HARDWARE_HANDLE_TYPE Hardware_Handle;
	DEVICE_TYPE			 Device;
}HARDWARE_CONFIG;


typedef union HARDWARE_PREPHERAL
{
	#ifdef	HAL_UART_MODULE_ENABLED
	UART_HandleTypeDef  *USART;
	#endif

	#ifdef HAL_I2C_MODULE_ENABLED
	I2C_HandleTypeDef	*I2C;
	#endif

	#ifdef HAL_SPI_MODULE_ENABLED
	SPI_HandleTypeDef	*SPI;
	#endif
}HARDWARE_PREPHERAL;

typedef struct BUFFER_FLOW_CONTROL
{
	OBJ_Buffer *buffer_ptr;
	uint16_t 	DATA_Counter;
	uint16_t 	SHADOW_DATA_Counter;
	uint16_t 	Counter;
	volatile bool Data_Recived;
}BUFFER_FLOW_CONTROL;


typedef struct BUFFER_CTRL
{
	uint16_t Wr_PTr;
	uint16_t Rd_PTr;
	bool 	 Wr_OverFlow_Flag;
	bool 	 Rd_OverFlow_Flag;
	bool 	 BUFFER_Valid;
	uint16_t Bank_Size;
	uint8_t  Bank_Number;
	uint8_t	 Wr_Bank_Ptr;
	uint8_t	 Rd_Bank_Ptr;
}BUFFER_CTRL;

typedef struct OBJ_HARDWARE
{
	OBJ_Buffer 			Buffer;
	OBJ_Identifier 		ID;
	HARDWARE_CONFIG		Hardware_Config;
	BUFFER_CTRL			Buffer_Ctrl;
	BUFFER_FLOW_CONTROL	Flow_Ctrl;
	HARDWARE_PREPHERAL  HAL_PREPHERAL;
	bool 				HARDWARE_Validate;
	DEVICE_ERROR		ERROR;
}OBJ_HARDWARE;



/* Private Typedef -----------------------------------------------------------*/
void HARDWARE_CONFIG_SCAN_Prepheral(void);
bool GET_SPI_MODULE_DEFINITION(void);
bool GET_I2C_MODULE_DEFINITION(void);
bool GET_UART_MODULE_DEFINITION(void);
bool GET_UART_MODULE_DEFINITION(void);
bool GET_TIM_MODULE_DEFINITION(void);
bool GET_RTC_MODULE_DEFINITION(void);

#ifdef __cplusplus
}
#endif
#endif /* USER_FILE_HARDWARE_CONFIG_H_ */
