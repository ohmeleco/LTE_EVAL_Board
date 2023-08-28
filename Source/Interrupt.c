/*
 * Interrupt.c
 *
 *  Created on: Aug 25, 2023
 *      Author: Acer
 */


#include "INTERRUPT.h"

static  INTERRUPT_Struct *Interrupt_List;
static uint8_t *Interrupt_Counter;

static INTERRUPT_Struct* Add_Interrupt_obj(INTERRUPT_Struct* str);

bool OBJ_Interrupt_init(INTERRUPT_Type type,char* ID_Name,uint16_t ID_Number,uint8_t Priority_Main,uint8_t Priority_Sub,uint8_t HAL_Number)
{
	INTERRUPT_Struct Interrupt;
	if(type!= Interrupt_Type_None)
	{

		OBJ_Identifier_Initialize(&Interrupt.ID, ID_Number, ID_Name);
		Interrupt.Priority_Main = Priority_Main;
		Interrupt.Priority_Sub  = Priority_Sub;
		if(HAL_Number)
		{
			Interrupt.HAL_Number=HAL_Number;
			if(Add_Interrupt_obj(&Interrupt))
				return true;
		}
	}

	return false;
}

static INTERRUPT_Struct* Add_Interrupt_obj(INTERRUPT_Struct* str)
{
	static INTERRUPT_Struct* Local_Interrupt_List;
	static uint8_t Interrupt_Cnt=0;
	if(Local_Interrupt_List==NULL)// first time this function call
	{
		Local_Interrupt_List=(INTERRUPT_Struct*)malloc(sizeof(INTERRUPT_Struct)*Default_Interrupt_Size);
		if(Local_Interrupt_List==NULL)
		{
			__NOP();
			//Error happen
		}
		Interrupt_List		=Local_Interrupt_List;
		Interrupt_Counter 	=&Interrupt_Cnt;
	}
	if(Interrupt_Cnt < Default_Interrupt_Size && Local_Interrupt_List!=NULL)
	{
		memcpy(&Local_Interrupt_List[Interrupt_Cnt],str,sizeof(INTERRUPT_Struct));
		Interrupt_Cnt++;
	}
	else
	{
		__NOP();
		//Error Happen
	}
	return Local_Interrupt_List;
}

uint8_t Get_Interrupt_Conter(void)
{
	return *Interrupt_Counter;
}

INTERRUPT_Struct* Get_Interrupt_List(void)
{
	return Interrupt_List;
}


void SET_INTERRUPT_Handler(INTERRUPT_Type type,uint8_t HAL_Number,INTERRUPT_MODE mode)
{
	//Interrupt_Handler.Interrupt=true;
	switch(type)
	{
		case(Interrupt_Type_UART):
		{

			break;
		}
		case(Interrupt_Type_UART_DMA):
		{

			break;
		}
		case(Interrupt_Type_Timer):
		{

			break;
		}
		default:
		{
			break;
		}
	}
}
