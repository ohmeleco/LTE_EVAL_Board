/*
 * MODEM.c
 *
 *  Created on: May 27, 2023
 *      Author: mosavi
 */
#include "MODEM.h"

bool MODEM_HARDWARE_Init(MODEM *modem, HARDWARE_PROTOCOL HP,HARDWARE_PREPHERAL *Handler,HARDWARE_HANDLE_TYPE HHT,MODEM_GPIO_CTRL CTRL,DEVICE_TYPE Device)
{
	HARDWARE_CONFIG_SCAN_Prepheral();
	switch(HP)
	{
		case(HARDWARE_PROTOCOL_USART):
		{
			modem->HARDWARE_Config.Hardware_Config.Hardware_Protocol=HARDWARE_PROTOCOL_USART;
			if(DEFINE_USART_MODULE_EN || DEFINE_UART_MODULE_EN)
			{
				modem->HARDWARE_Config.HAL_PREPHERAL.USART=Handler->USART;
			}
			else
			{
				modem->HARDWARE_Config.ERROR=DEVICE_ERROR_PROTOCOL_USART_NOT_ASSIGNET;
			}
			break;
		}
		default:
		{
			modem->HARDWARE_Config.ERROR=DEVICE_ERROR_PROTOCOL_NOT_FOUDND;
			return false;
			break;
		}
	}
	if(HHT!=Hardware_Handle_UNKNOWN)
	{
		modem->HARDWARE_Config.Hardware_Config.Hardware_Handle=HHT;
	}
	else
	{
		__NOP();
		modem->HARDWARE_Config.ERROR=DEVICE_ERROR_HANDLE_TYPE_NOT_FOUND;
		return false;
	}
	if(CTRL!=MODEM_GPIO_CTRL_UNKNOWN)
	{
		modem->GPIO_Control_Pin=CTRL;
		if(Device == DEVICE_TYPE_MODEM || Device == DEVICE_TYPE_MODEM_QUECTEL || DEVICE_TYPE_MODEM_SIMCOM  )
			modem->HARDWARE_Config.Hardware_Config.Device=Device;
		else
		{
			modem->HARDWARE_Config.ERROR=DEVICE_ERROR_DEVICE_TYPE_NOT_Recognized;
			return false;
		}
		modem->HARDWARE_Config.HARDWARE_Validate = true;
	}
	else
		modem->GPIO_Control_Pin=MODEM_GPIO_CTRL_NOT_Defined;

	return true;
}
bool MODEM_HARDWARE_RST_PIN(MODEM *modem, GPIO_TypeDef *RST_PORT,uint16_t RST_PIN,bool SET_RST_PIN,bool RESET_RST_PIN)
{
	if(modem->GPIO_Control_Pin== MODEM_GPIO_CTRL_NONE)
	{
		modem->MODEM_RST.Validate_Pin=true;
		return true;
	}
	if(modem->GPIO_Control_Pin== MODEM_GPIO_CTRL_UNKNOWN)
		return false;
	if(RESET_RST_PIN ==SET_RST_PIN)
	{
		modem->HARDWARE_Config.ERROR=DEVICE_ERROR_CTRL_GPIO_SET_RESET_ERROR;
		return false;
	}
	else
	{
		// Validate Pin
		modem->MODEM_RST.RESET_PIN_State=RESET_RST_PIN;
		modem->MODEM_RST.SET_PIN_State	=SET_RST_PIN;
		modem->MODEM_RST.PORT =RST_PORT;
		modem->MODEM_RST.PIN  =RST_PIN;
		modem->MODEM_RST.Validate_Pin=true;
	}
	return true;
}
bool MODEM_HARDWARE_PWR_PIN(MODEM *modem, GPIO_TypeDef *PWR_PORT,uint16_t PWR_PIN,bool SET_PWR_PIN,bool RESET_PWR_PIN)
{
	//puts your  validation code here
	if(modem->GPIO_Control_Pin== MODEM_GPIO_CTRL_NONE)
	{
		modem->MODEM_PWR.Validate_Pin=true;
		return true;
	}
	if(modem->GPIO_Control_Pin== MODEM_GPIO_CTRL_UNKNOWN)
		return false;
	if(RESET_PWR_PIN ==SET_PWR_PIN) // both states are the same.
	{
		modem->HARDWARE_Config.ERROR=DEVICE_ERROR_CTRL_GPIO_SET_RESET_ERROR;
		return false;
	}
	else
	{
		// Validate Pin
		modem->MODEM_PWR.RESET_PIN_State=RESET_PWR_PIN;
		modem->MODEM_PWR.SET_PIN_State	=SET_PWR_PIN;
		modem->MODEM_PWR.PORT =PWR_PORT;
		modem->MODEM_PWR.PIN  =PWR_PIN;
		modem->MODEM_PWR.Validate_Pin=true;
	}
	return true;
}
bool MODEM_HARDWARE_RGL_PIN(MODEM *modem, GPIO_TypeDef *RGL_PORT,uint16_t RGL_PIN,bool SET_RGL_PIN,bool RESET_RGL_PIN)
{
	//puts your  validation code here
	if(modem->GPIO_Control_Pin== MODEM_GPIO_CTRL_NONE)
	{
		modem->MODEM_RGL.Validate_Pin=true;
		return true;
	}
	if(modem->GPIO_Control_Pin== MODEM_GPIO_CTRL_UNKNOWN)
		return false;
	if(RESET_RGL_PIN ==SET_RGL_PIN )
	{
		modem->HARDWARE_Config.ERROR=DEVICE_ERROR_CTRL_GPIO_SET_RESET_ERROR;
		return false;
	}
	else
	{
		// Validate Pin
		modem->MODEM_RGL.RESET_PIN_State=RESET_RGL_PIN;
		modem->MODEM_RGL.SET_PIN_State	=SET_RGL_PIN;
		modem->MODEM_RGL.PORT =RGL_PORT;
		modem->MODEM_RGL.PIN  =RGL_PIN;
		modem->MODEM_RGL.Validate_Pin=true;
	}
	return true;
}
bool MODEM_HARDWARE_RGL_ON_OFF(MODEM *modem,bool ON_OFF)	// true:On
{
	if(modem->Validation_State != HARDWARE_VALIDATION_OK)
		return false;
	if(modem->GPIO_Control_Pin==MODEM_GPIO_RGL_PIN || modem->GPIO_Control_Pin == MODEM_GPIO_RGL_RST || modem->GPIO_Control_Pin == MODEM_GPIO_ALL_PIN)
	{
		if(ON_OFF)
			HAL_GPIO_WritePin(modem->MODEM_RGL.PORT, modem->MODEM_RGL.PIN, modem->MODEM_RGL.SET_PIN_State);
		else
			HAL_GPIO_WritePin(modem->MODEM_RGL.PORT, modem->MODEM_RGL.PIN, modem->MODEM_RGL.RESET_PIN_State);
		return true;
	}
	else
	{
		modem->OPRATION=HARDWARE_OPRATION_GPIO_CTRL_NotDefined;
		return false;
	}
	return false;
}
bool MODEM_HARDWARE_PWR_ON_OFF(MODEM *modem,bool ON_OFF)	// true:On
{
	//puts your  validation code here
	if(modem->Validation_State != HARDWARE_VALIDATION_OK)
		return false;
	if(modem->GPIO_Control_Pin==MODEM_GPIO_PWR_PIN || modem->GPIO_Control_Pin == MODEM_GPIO_PWR_RST || modem->GPIO_Control_Pin == MODEM_GPIO_ALL_PIN)
	{
		if(ON_OFF)
		{
			HAL_GPIO_WritePin(modem->MODEM_PWR.PORT, modem->MODEM_PWR.PIN, modem->MODEM_PWR.SET_PIN_State);
			HAL_Delay(MODEM_TURN_ONOFF_DELAY);
			HAL_GPIO_WritePin(modem->MODEM_PWR.PORT, modem->MODEM_PWR.PIN, modem->MODEM_PWR.RESET_PIN_State);
		}
		else
		{
			HAL_GPIO_WritePin(modem->MODEM_PWR.PORT, modem->MODEM_PWR.PIN, modem->MODEM_PWR.SET_PIN_State);
			HAL_Delay(MODEM_TURN_ONOFF_DELAY);
			HAL_GPIO_WritePin(modem->MODEM_PWR.PORT, modem->MODEM_PWR.PIN, modem->MODEM_PWR.RESET_PIN_State);
			HAL_Delay(MODEM_TURN_ONOFF_DELAY);
			HAL_GPIO_WritePin(modem->MODEM_PWR.PORT, modem->MODEM_PWR.PIN, modem->MODEM_PWR.SET_PIN_State);
		}
		return true;
	}
	else
	{
		modem->OPRATION=HARDWARE_OPRATION_GPIO_CTRL_NotDefined;
		return false;
	}
	return false;
}
bool MODEM_HARDWARE_RESET(MODEM *modem)
{
	if(modem->Validation_State != HARDWARE_VALIDATION_OK)
		return false;
	if(modem->GPIO_Control_Pin==MODEM_GPIO_RST_PIN || modem->GPIO_Control_Pin == MODEM_GPIO_PWR_RST ||
	 modem->GPIO_Control_Pin == MODEM_GPIO_RGL_RST || modem->GPIO_Control_Pin == MODEM_GPIO_ALL_PIN)

	{
		HAL_GPIO_WritePin(modem->MODEM_RST.PORT, modem->MODEM_RST.PIN, modem->MODEM_RST.SET_PIN_State);
		HAL_Delay(MODEM_RESET_DELAY);
		HAL_GPIO_WritePin(modem->MODEM_RST.PORT, modem->MODEM_RST.PIN, modem->MODEM_RST.RESET_PIN_State);
		return true;
	}
	else
	{
		modem->OPRATION=HARDWARE_OPRATION_GPIO_CTRL_NotDefined;
		return false;
	}
	return false;
}
void MODEM_Identifire_Init(MODEM*modem, const char *Name, uint16_t ID)
{
	if(ID)
		OBJ_Identifier_Initialize(&modem->HARDWARE_Config.ID, ID, Name);

}
bool MODEM_BUFFER_Init(MODEM*modem , uint16_t Buffer_Size)
{
	if(Buffer_Size)
	{
		OBJ_Buffer_Initialize(&modem->HARDWARE_Config.Buffer, Buffer_Size);
		return true;
	}
	else
		return false;
}
DEVICE_ERROR MODEM_Validatin_Sequence(MODEM*modem)
{
	if(modem->HARDWARE_Config.HARDWARE_Validate == false)
	{
		modem->Validation_State=HARDWARE_VALIDATION_ERROR;
		return modem->HARDWARE_Config.ERROR;
	}
	if(modem->HARDWARE_Config.Buffer.FLAG_Saved_Buffer==false)
	{
		modem->HARDWARE_Config.ERROR=DECIVE_ERROR_BUFFE_INIT_FAIL;
		modem->Validation_State=HARDWARE_VALIDATION_ERROR;
		return DECIVE_ERROR_BUFFE_INIT_FAIL;
	}
	if(modem->HARDWARE_Config.ID.IS_VALID==false)
	{
		modem->HARDWARE_Config.ERROR=DECIVE_ERROR_IDENTIFIER_INIT_FAIL;
		modem->Validation_State=HARDWARE_VALIDATION_ERROR;
		return DECIVE_ERROR_IDENTIFIER_INIT_FAIL;
	}
	switch(modem->GPIO_Control_Pin)
	{
		case(MODEM_GPIO_ALL_PIN):
		{
			if(!(modem->MODEM_RST.Validate_Pin && modem->MODEM_PWR.Validate_Pin && modem->MODEM_RGL.Validate_Pin))
			{
				modem->HARDWARE_Config.ERROR = DEVICE_ERROR_CTRL_GPIO_NOT_COMPATIBLE;
				modem->Validation_State=HARDWARE_VALIDATION_ERROR;
				return DEVICE_ERROR_CTRL_GPIO_NOT_COMPATIBLE;
			}
			break;
		}
		case(MODEM_GPIO_CTRL_NONE):
		{
			__NOP();
			break;
		}
		case(MODEM_GPIO_PWR_PIN):
		{
			if(!modem->MODEM_PWR.Validate_Pin)
			{
				modem->HARDWARE_Config.ERROR = DEVICE_ERROR_CTRL_GPIO_NOT_DEFINED;
				modem->Validation_State=HARDWARE_VALIDATION_ERROR;
				return DEVICE_ERROR_CTRL_GPIO_NOT_DEFINED;
			}

			break;
		}
		case(MODEM_GPIO_RST_PIN):
		{
			if(!modem->MODEM_RST.Validate_Pin)
			{
				modem->HARDWARE_Config.ERROR = DEVICE_ERROR_CTRL_GPIO_NOT_DEFINED;
				modem->Validation_State=HARDWARE_VALIDATION_ERROR;
				return DEVICE_ERROR_CTRL_GPIO_NOT_DEFINED;
			}
			break;
		}
		case(MODEM_GPIO_RGL_PIN):
		{
			if(!modem->MODEM_RGL.Validate_Pin)
			{
				modem->HARDWARE_Config.ERROR = DEVICE_ERROR_CTRL_GPIO_NOT_DEFINED;
				modem->Validation_State=HARDWARE_VALIDATION_ERROR;
				return DEVICE_ERROR_CTRL_GPIO_NOT_DEFINED;
			}
			break;
		}
		case(MODEM_GPIO_PWR_RST):
		{
			if(!(modem->MODEM_PWR.Validate_Pin && modem->MODEM_RST.Validate_Pin))
			{
				modem->Validation_State=HARDWARE_VALIDATION_ERROR;
				modem->HARDWARE_Config.ERROR = DEVICE_ERROR_CTRL_GPIO_NOT_COMPATIBLE;
				return DEVICE_ERROR_CTRL_GPIO_NOT_COMPATIBLE;
			}
			break;
		}
		case(MODEM_GPIO_RGL_RST):
		{
			if(!(modem->MODEM_RGL.Validate_Pin && modem->MODEM_RST.Validate_Pin))
			{
				modem->Validation_State=HARDWARE_VALIDATION_ERROR;
				modem->HARDWARE_Config.ERROR = DEVICE_ERROR_CTRL_GPIO_NOT_COMPATIBLE;
				return DEVICE_ERROR_CTRL_GPIO_NOT_COMPATIBLE;
			}
			break;
		}
		default:
		{
			modem->Validation_State=HARDWARE_VALIDATION_ERROR;
			modem->HARDWARE_Config.ERROR = DEVICE_ERROR_CTRL_GPIO_NOT_DEFINED;
			return DEVICE_ERROR_CTRL_GPIO_NOT_DEFINED;
			break;
		}
	}
	modem->Validation_State=HARDWARE_VALIDATION_OK;
	return DEVICE_ERROR_NO_EEROR_REPORTED;
}
bool MODEM_TRANSMIT_Data(MODEM* modem, OBJ_Buffer* buffer)
{
	if(buffer->FLAG_Saved_Buffer==false)
	{
		modem->OPRATION=HARDWARE_OPRATION_BUFFER_FEIL;
		return false;
	}
	if(modem->Validation_State == HARDWARE_VALIDATION_OK)
	{
		if(modem->HARDWARE_Config.Hardware_Config.Hardware_Protocol==HARDWARE_PROTOCOL_USART)
		{
			// Selected  Protocol is USART
			if(modem->HARDWARE_Config.Hardware_Config.Hardware_Handle==Hardware_Handle_NORMAL)
			{
				// UART in Normal Mode
				if(HAL_UART_Transmit(modem->HARDWARE_Config.HAL_PREPHERAL.USART, (uint8_t*)buffer->Buffer, buffer->Buffer_Size,MODEM_UART_TIMEOUT_Tx)!=HAL_OK)
				{
					modem->HARDWARE_Config.ERROR=DEVICE_ERROR_PROTOCOL_USART_INTERNAL_ERROR;
				}
				else
				{
					modem->OPRATION=HARDWARE_OPRATION_Transmit_Done;

				}
			}
			if(modem->HARDWARE_Config.Hardware_Config.Hardware_Handle==Hardware_Handle_DMA_Timer)
			{
				// UART in DMA Mode
				if(HAL_UART_Transmit_DMA(modem->HARDWARE_Config.HAL_PREPHERAL.USART, (uint8_t*)buffer->Buffer, buffer->Buffer_Size)!=HAL_OK)
				{
					modem->HARDWARE_Config.ERROR=DEVICE_ERROR_PROTOCOL_USART_INTERNAL_ERROR;
				}
				else
				{
					modem->OPRATION=HARDWARE_OPRATION_Transmit_Done;
				}
			}
		}
	}
	else
	{
		modem->OPRATION=HARDWARE_OPRATION_VALIDATION_Error;
		return false;
	}
	return true;
}
bool MODEM_RECIVED_Data(MODEM* modem,uint16_t Data_Size)
{
	if(modem->HARDWARE_Config.Buffer.FLAG_Saved_Buffer==false)
	{
		modem->OPRATION=HARDWARE_OPRATION_BUFFER_FEIL;
		return false;
	}
	if(modem->HARDWARE_Config.Buffer.Buffer_Size <= Data_Size )
	{
		modem->OPRATION=HARDWARE_OPRATION_BUFFER_NOTenough_Space;
		return false;
	}
	if(modem->Validation_State == HARDWARE_VALIDATION_OK)
	{
		if(modem->HARDWARE_Config.Hardware_Config.Hardware_Protocol==HARDWARE_PROTOCOL_USART)
		{
			// Selected  Protocol is USART
			if(modem->HARDWARE_Config.Hardware_Config.Hardware_Handle==Hardware_Handle_NORMAL)
			{
				// UART in Normal Mode
				if(HAL_UART_Receive(modem->HARDWARE_Config.HAL_PREPHERAL.USART, (uint8_t*)modem->HARDWARE_Config.Buffer.Buffer, Data_Size,MODEM_UART_TIMEOUT_Tx)!=HAL_OK)
				{
					modem->HARDWARE_Config.ERROR=DEVICE_ERROR_PROTOCOL_USART_INTERNAL_ERROR;
				}
				else
				{
					modem->OPRATION=HARDWARE_OPRATION_Transmit_Done;

				}
			}
			if(modem->HARDWARE_Config.Hardware_Config.Hardware_Handle==Hardware_Handle_DMA_Timer)
			{
				// UART in DMA Mode
				if(Data_Size) 	// if Data_Size is zero value
				{
					if(HAL_UART_Receive_DMA(modem->HARDWARE_Config.HAL_PREPHERAL.USART, (uint8_t*)modem->HARDWARE_Config.Buffer.Buffer, Data_Size)!=HAL_OK)
					{
						modem->HARDWARE_Config.ERROR=DEVICE_ERROR_PROTOCOL_USART_INTERNAL_ERROR;
					}
					else
					{
						modem->OPRATION=HARDWARE_OPRATION_Transmit_Done;
					}
				}
				else	//if Data_Size isn't zero value
				{
					if(HAL_UART_Receive_DMA(modem->HARDWARE_Config.HAL_PREPHERAL.USART, (uint8_t*)modem->HARDWARE_Config.Buffer.Buffer, modem->HARDWARE_Config.Buffer.Buffer_Size)!=HAL_OK)
					{
						modem->HARDWARE_Config.ERROR=DEVICE_ERROR_PROTOCOL_USART_INTERNAL_ERROR;
					}
					else
					{
						modem->OPRATION=HARDWARE_OPRATION_Transmit_Done;
					}
				}
			}
		}
	}
	else
	{
		modem->OPRATION=HARDWARE_OPRATION_VALIDATION_Error;
		return false;
	}
	return true;
}

bool MODEM_HARDWARE_CHECK_STATUS(MODEM* modem)
{
	//Puts your Validation Code here
	if(modem->Validation_State != HARDWARE_VALIDATION_OK)
	{
		return false;
	}


	return true;
}
