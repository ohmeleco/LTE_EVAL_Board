/*
 * EEPROM.c
 *
 *  Created on: May 6, 2023
 *      Author: mosavi
 */

#include "EEPROM.h"
#include "main.h"


bool EEPROM_HARDWARE_Init(EEPROM *e2prom,uint16_t E2PROM_Device_Address,uint16_t PAGE_Size,HARDWARE_PROTOCOL HP,HARDWARE_PREPHERAL *Handler,HARDWARE_HANDLE_TYPE HHT)
{
	HARDWARE_CONFIG_SCAN_Prepheral();
	e2prom->HARDWARE_Config.Hardware_Config.Device=DEVICE_TYPE_MEMORY_EEPROM;
	if(PAGE_Size==0)
	{
		e2prom->HARDWARE_Config.ERROR = DEVICE_ERROR_EEPROM_INTERNAL_ERROR;
		return false;
	}
	else
		e2prom->PAGE_Size_InByte=PAGE_Size;
	if(E2PROM_Device_Address == 0)	//ERROR Report
	{
		e2prom->HARDWARE_Config.ERROR	=DECIVE_ERROR_MEMORY_ADDRESS_ERROR;
		return false;
	}
	else
		e2prom->EEPROM_ADDRESS=E2PROM_Device_Address;

	if(HP==HARDWARE_PROTOCOL_I2C || HP==HARDWARE_PROTOCOL_SPI)
	{
		e2prom->HARDWARE_Config.Hardware_Config.Hardware_Protocol=HP;
		if(HP==HARDWARE_PROTOCOL_I2C)
		{
			#ifdef HAL_I2C_MODULE_ENABLED
			e2prom->HARDWARE_Config.HAL_PREPHERAL.I2C=Handler->I2C;
			e2prom->HARDWARE_Config.Hardware_Config.Hardware_Handle=HHT;
			e2prom->HARDWARE_Config.HARDWARE_Validate = true;
			#else
			__NOP();
			#endif
		}
		else if(HP== HARDWARE_PROTOCOL_SPI)
		{
			#ifdef HAL_SPI_MODULE_ENABLED
			e2prom->HARDWARE_Config.HAL_PREPHERAL.SPI=Handler->SPI;
			e2prom->HARDWARE_Config.Hardware_Config.Hardware_Handle=HHT;
			e2prom->HARDWARE_Config.HARDWARE_Validate = true;
			#else
			__NOP();
			#endif
		}
	}
	else									// ERROR Report
	{
		e2prom->HARDWARE_Config.ERROR=DEVICE_ERROR_PROTOCOL_NOT_CORRECT;
		return false;
	}
	e2prom->HARDWARE_Config.HARDWARE_Validate=true;
	return true;
}

void EEPROM_Identifire_Init(EEPROM*e2prom, const char *Name, uint16_t ID, uint32_t Size_InByte,uint16_t Size_InKByte,uint8_t Address)
{
	OBJ_Identifier_Initialize(&e2prom->HARDWARE_Config.ID, ID, Name);
	if(Size_InByte && Size_InKByte)
	{
		e2prom->Size_InByte	= Size_InByte;
		e2prom->SIZE_InKbit = Size_InKByte;
	}
	else
		e2prom->HARDWARE_Config.ERROR=DECIVE_ERROR_MEMORY_SIZE_ERROR;
	__NOP();
}

bool EEPROM_BUFFER_Init(EEPROM*e2prom , uint16_t Buffer_Size,uint8_t Number_Of_ADDRESS_Bytes)
{
	if(Buffer_Size)
	{
		OBJ_Buffer_Initialize(&e2prom->HARDWARE_Config.Buffer, Buffer_Size+Number_Of_ADDRESS_Bytes);
		return true;
	}
	else
		return false;
}

bool EEPROM_OPRATION_CHECK(EEPROM*e2prom,bool OP_Type,uint16_t Address)
{

	if(e2prom->Validation_State!=HARDWARE_VALIDATION_OK)	//Place Validation Code here
	{
		e2prom->OPRATION=HARDWARE_OPRATION_VALIDATION_Error;
		return false;
	}
	if(e2prom-> Data_Size >= e2prom->HARDWARE_Config.Buffer.Buffer_Size )
	{
		e2prom->OPRATION=HARDWARE_OPRATION_BUFFER_NOTenough_Space;
		return false;
	}

	if(OP_Type)	//Write Operate
	{
		if(e2prom->Data_Size==0)
		{
			e2prom->OPRATION=HARDWARE_OPRATION_WRITE_SIZE_ERROR;
			return false;
		}
		if(Address >= e2prom->Size_InByte)
		{
			e2prom->OPRATION=HARDWARE_OPRATION_WRITE_NOTenough_Space;
			return false;
		}
		if(e2prom->Data_Size+Address >= e2prom->Size_InByte)
		{
			e2prom->OPRATION=HARDWARE_OPRATION_WRITE_NOTenough_Space;
			return false;
		}

		HAL_GPIO_WritePin(EEPROM_WP_PORT, EEPROM_WP_PIN,EEPROM_WP_DISABLE);
		e2prom->OPRATION=HARDWARE_OPRATION_WRITE_DONE;
	}
	else		//Read Operate
	{
		if(e2prom-> Data_Size==0)
		{
			e2prom->OPRATION=HARDWARE_OPRATION_READ_SIZE_ERROR;
			return false;
		}
		if(Address >= e2prom->Size_InByte)
		{
			e2prom->OPRATION=HARDWARE_OPRATION_READ_NOTenough_Space;
			return false;
		}
		if(e2prom-> Data_Size+Address >= e2prom->Size_InByte)
		{
			e2prom->OPRATION=HARDWARE_OPRATION_READ_NOTenough_Space;
			return false;
		}
		HAL_GPIO_WritePin(EEPROM_WP_PORT, EEPROM_WP_PIN,EEPROM_WP_Enable);
		e2prom->OPRATION=HARDWARE_OPRATION_READ_DONE;
	}
	return true;
}

static void EEPROM_GPIO_ctrl(bool OP_Type, bool Start_End)
{
	if(EEPROM_PWR_Ctrl)	// if Power Control is Set to 1
	{
		if(Start_End)	// turn on a EEPROM
			HAL_GPIO_WritePin(EEPROM_PWR_PORT, EEPROM_PWR_PIN, EEPROM_PWR_Enable);
		else
			HAL_GPIO_WritePin(EEPROM_PWR_PORT, EEPROM_PWR_PIN, EEPROM_PWR_Disable);
	}
	if(EEPROM_WP_Ctrl)	// if Write Protected Pin is Set to 1
	{
		if(OP_Type)	//write Opration

			HAL_GPIO_WritePin(EEPROM_WP_PORT, EEPROM_WP_PIN, EEPROM_WP_DISABLE);
		else
			HAL_GPIO_WritePin(EEPROM_WP_PORT, EEPROM_WP_PIN, EEPROM_WP_Enable);
	}
}

DEVICE_ERROR EEPROM_Validatin_Sequence(EEPROM *e2prom)
{
	if(e2prom->HARDWARE_Config.HARDWARE_Validate == false)
	{
		return e2prom->HARDWARE_Config.ERROR;
	}
	if(e2prom->HARDWARE_Config.Buffer.FLAG_Saved_Buffer==false)
	{
		return DECIVE_ERROR_BUFFE_INIT_FAIL;
	}
	if(e2prom->HARDWARE_Config.ID.IS_VALID==false)
	{
		return DECIVE_ERROR_IDENTIFIER_INIT_FAIL;
	}
	if(e2prom->HARDWARE_Config.ERROR==DECIVE_ERROR_MEMORY_SIZE_ERROR)
	{
		return DECIVE_ERROR_MEMORY_SIZE_ERROR;
	}
	e2prom->Validation_State=HARDWARE_VALIDATION_OK;
	return DEVICE_ERROR_NO_EEROR_REPORTED;
}

bool EEPROM_Write_Data(EEPROM *e2prom,uint8_t *DATA,uint16_t Size)
{
	//Place Validation Code here
	if(e2prom->Validation_State!=HARDWARE_VALIDATION_OK)
		return false;
	if(Size+EEPROM_ADRESS_Byte>=e2prom->HARDWARE_Config.Buffer.Buffer_Size)
		return false;
	else
	{
		//Clear Buffer
		memset(e2prom->HARDWARE_Config.Buffer.Buffer,0,e2prom->HARDWARE_Config.Buffer.Buffer_Size);
		memcpy(&e2prom->HARDWARE_Config.Buffer.Buffer[EEPROM_ADRESS_Byte],(char*)DATA,Size);
		e2prom->Data_Size=Size;
		return true;
	}
}

bool EEPROM_Send_Data(EEPROM *e2prom,uint16_t Address)
{
	if(EEPROM_OPRATION_CHECK(e2prom,1, Address)==false)
		return false;
	e2prom->HARDWARE_Config.Buffer.Buffer[0]=Address >> 8;		// LSB byte second
	e2prom->HARDWARE_Config.Buffer.Buffer[1]=Address & 0xFF;	// MSB byte first

	if(e2prom->Validation_State!=HARDWARE_VALIDATION_OK)			//Validation Code here
		return false;
	//======================  End I2C Section
	HAL_Delay(5);
	if(e2prom->HARDWARE_Config.Hardware_Config.Hardware_Protocol==HARDWARE_PROTOCOL_I2C)
	{
		EEPROM_GPIO_ctrl(1, 1); // turn on PWR and write mode
		switch(e2prom->HARDWARE_Config.Hardware_Config.Hardware_Handle)
		{
			case(Hardware_Handle_NORMAL):
			{
				HAL_I2C_Master_Transmit(e2prom->HARDWARE_Config.HAL_PREPHERAL.I2C, e2prom->EEPROM_ADDRESS, (uint8_t*)e2prom->HARDWARE_Config.Buffer.Buffer, e2prom->Data_Size+EEPROM_ADRESS_Byte, 100);
				HAL_Delay(EEPROM_Default_Timeout);
				break;
			}
			case(Hardware_Handle_IT):
			{
				break;
			}
			case(Hardware_Handle_DMA_Timer):
			{
				break;
			}
			default:
			{
				e2prom->HARDWARE_Config.ERROR=Hardware_Handle_UNKNOWN;
				e2prom->OPRATION=HARDWARE_OPRATION_WRITE_HW_ERROR;
				return false;
				break;
			}
		}
		EEPROM_GPIO_ctrl(0, 1); // turn on PWR and Read mode
	}
	//======================  End I2C Section
	//SPI Section
	else if (e2prom->HARDWARE_Config.Hardware_Config.Hardware_Protocol==HARDWARE_PROTOCOL_SPI)
		__NOP();
	return true;
}
bool EEPROM_Read_Data(EEPROM *e2prom,uint16_t Address,uint32_t Size)
{

	uint8_t dummy[2];
	e2prom->Data_Size=Size;
	if(EEPROM_OPRATION_CHECK(e2prom,0, Address)==false)
		return false;
	dummy[1]=Address & 0xFF;
	dummy[0]=Address >> 8;
	if(e2prom->HARDWARE_Config.Hardware_Config.Hardware_Protocol==HARDWARE_PROTOCOL_I2C)
	{
		EEPROM_GPIO_ctrl(0, 1); // turn on PWR and Read mode
		switch(e2prom->HARDWARE_Config.Hardware_Config.Hardware_Handle)
		{
			case(Hardware_Handle_NORMAL):
			{
				HAL_Delay(5);
				HAL_I2C_Master_Transmit(e2prom->HARDWARE_Config.HAL_PREPHERAL.I2C, e2prom->EEPROM_ADDRESS, dummy, 2, EEPROM_Default_Timeout);
				OBJ_Buffer_Clear_Data(&e2prom->HARDWARE_Config.Buffer);
				HAL_Delay(1);
				HAL_I2C_Master_Receive(e2prom->HARDWARE_Config.HAL_PREPHERAL.I2C, e2prom->EEPROM_ADDRESS, (uint8_t*)e2prom->HARDWARE_Config.Buffer.Buffer, Size, EEPROM_Default_Timeout);
				break;
			}
			case(Hardware_Handle_IT):
			{
				break;
			}
			case(Hardware_Handle_DMA_Timer):
			{
				break;
			}
			default:
			{
				e2prom->HARDWARE_Config.ERROR=Hardware_Handle_UNKNOWN;
				e2prom->OPRATION=HARDWARE_OPRATION_WRITE_HW_ERROR;
				return false;
				break;
			}
		}
		EEPROM_GPIO_ctrl(0, 1); // turn on PWR and Read mode
	}
	//======================  End I2C Section
	/*if(e2prom->HARDWARE_Config.Hardware_Config.Hardware_Protocol==HARDWARE_PROTOCOL_I2C)
	{
		HAL_Delay(5);
		HAL_I2C_Master_Transmit(e2prom->HARDWARE_Config.HAL_PREPHERAL.I2C, e2prom->EEPROM_ADDRESS, dummy, 2, EEPROM_Default_Timeout);
		OBJ_Buffer_Clear_Data(&e2prom->HARDWARE_Config.Buffer);
		HAL_I2C_Master_Receive(e2prom->HARDWARE_Config.HAL_PREPHERAL.I2C, e2prom->EEPROM_ADDRESS, (uint8_t*)e2prom->HARDWARE_Config.Buffer.Buffer, Size, EEPROM_Default_Timeout);
	}*/
	return true;
}

bool EEPROM_WRITE_PAGE(EEPROM *eeprom,uint16_t Address)
{
	uint16_t i=0,j=0;
	uint16_t PAGE_Write=0;
	uint16_t dummy=0;
	uint8_t Data[eeprom->PAGE_Size_InByte+EEPROM_ADRESS_Byte];
	if(EEPROM_OPRATION_CHECK(eeprom,1,Address)==false)
		return false;
	if(eeprom->OPRATION==HARDWARE_OPRATION_WRITE_DONE)
	{
		//================== I2C Section ======================
		//=====================================================
		PAGE_Write=eeprom->Data_Size / eeprom->PAGE_Size_InByte;
		dummy=eeprom->Data_Size % eeprom->PAGE_Size_InByte;
		//==================== Start of Write Sequence
		if(eeprom->HARDWARE_Config.Hardware_Config.Hardware_Protocol==HARDWARE_PROTOCOL_I2C)
		{
			HAL_Delay(EEPROM_PAGEWRITE_DELAY_ms);
			//Disable Write Protection
			if(EEPROM_WP_Ctrl)
				HAL_GPIO_WritePin(EEPROM_WP_PORT,EEPROM_WP_PIN,EEPROM_WP_DISABLE);
			for(i=0; i<PAGE_Write;i++)
			{
				Data[0]=Address >> 8;
				Data[1]=Address & 0xFF;
				memcpy(&Data[2],&eeprom->HARDWARE_Config.Buffer.Buffer[j],eeprom->PAGE_Size_InByte);
				if(HAL_I2C_Master_Transmit(eeprom->HARDWARE_Config.HAL_PREPHERAL.I2C, eeprom->EEPROM_ADDRESS, Data, eeprom->PAGE_Size_InByte, EEPROM_Default_Timeout)!=HAL_OK)
					eeprom->HARDWARE_Config.ERROR=DEVICE_ERROR_EEPROM_INTERNAL_ERROR;
				HAL_Delay(EEPROM_PAGEWRITE_DELAY_ms);
				Address+=eeprom->PAGE_Size_InByte;
				j+=eeprom->PAGE_Size_InByte;
			}

			if(dummy)
			{
				memcpy(&Data[2],&eeprom->HARDWARE_Config.Buffer.Buffer[PAGE_Write*eeprom->PAGE_Size_InByte],dummy);
				if(HAL_I2C_Master_Transmit(eeprom->HARDWARE_Config.HAL_PREPHERAL.I2C, eeprom->EEPROM_ADDRESS, Data, dummy, EEPROM_Default_Timeout)!=HAL_OK)
					eeprom->HARDWARE_Config.ERROR=DEVICE_ERROR_EEPROM_INTERNAL_ERROR;
			}
			if(EEPROM_WP_Ctrl)
				HAL_GPIO_WritePin(EEPROM_WP_PORT,EEPROM_WP_PIN,EEPROM_WP_Enable);

			//==================== End of Write Sequence

			//================== I2C Section ======================
			//=====================================================
		}

		else if(eeprom->HARDWARE_Config.Hardware_Config.Hardware_Protocol==HARDWARE_PROTOCOL_SPI)
		{
			//================== SPI Section ======================
			//=====================================================
			__NOP();
			HAL_Delay(EEPROM_PAGEWRITE_DELAY_ms);

			//================== SPI Section ======================
			//=====================================================
		}

	}
	return true;
}
