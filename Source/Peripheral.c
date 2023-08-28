/*
 * Peripheral.c
 *
 *  Created on: Aug 24, 2023
 *      Author: Acer
 */

#include "PERIPHERAL.h"

static PERIPHERAL_Str* PERIPHERAL_List;
static uint8_t* PERIPHERAL_Cnt;


static PERIPHERAL_Str* Add_Peripheral_obj(PERIPHERAL_Str *obj);
static void Clear_Peripheral_Info(uint8_t index);

bool OBJ_Peripheral_init(PERIPHERAL_TYPE type,char* ID_Name,uint16_t ID ,char* Info_txt,char*HAL_Name)
{
	PERIPHERAL_Str obj;
	if(type!=PERIPHERAL_TYPE_NONE)
	{
		obj.PERIPHERAL=type;
		OBJ_Identifier_Initialize(&obj.ID, ID, ID_Name);
		memset(obj.HAL_Name,0,HAL_NAME_Size);
		memcpy(obj.HAL_Name,HAL_Name,strlen(HAL_Name));
		memset(obj.Peripheral_Info,0,Information_Size);
		memcpy(obj.Peripheral_Info,Info_txt,strlen(Info_txt));
		Add_Peripheral_obj(&obj);
		return true;
	}
	return false;
}
static PERIPHERAL_Str* Add_Peripheral_obj(PERIPHERAL_Str *obj)
{
	static uint8_t PERIPHERAL_Counter=0;
	static PERIPHERAL_Str* PERIPHERAL_LocaL_List;
	if(PERIPHERAL_LocaL_List == NULL)	// first time
	{
		PERIPHERAL_LocaL_List =(PERIPHERAL_Str*)malloc(sizeof(PERIPHERAL_Str)*PERIPHERAL_List_Default_Size);
		if(PERIPHERAL_LocaL_List==NULL)
		{
			__NOP();
			//Error happen
		}
		PERIPHERAL_List=PERIPHERAL_LocaL_List;
		PERIPHERAL_Cnt = &PERIPHERAL_Counter;
	}
	if(PERIPHERAL_Counter>PERIPHERAL_List_Default_Size && PERIPHERAL_LocaL_List==NULL)
	{
		__NOP();
		//Error Happen
	}
	else
	{
		memcpy(&PERIPHERAL_LocaL_List[PERIPHERAL_Counter],obj,sizeof(PERIPHERAL_Str));
		PERIPHERAL_LocaL_List[PERIPHERAL_Counter].index=PERIPHERAL_Counter;
		PERIPHERAL_Counter++;

	}

	return PERIPHERAL_LocaL_List;
}
uint8_t Get_Peripheral_Conter(void)
{
	return *PERIPHERAL_Cnt;
}

PERIPHERAL_Str* GET_Peripheral_List(void)
{
	return PERIPHERAL_List;
}

static void Clear_Peripheral_Info(uint8_t index)
{
	memset(PERIPHERAL_List[index].Peripheral_Info,0,Information_Size);
}

bool EDIT_Peripheral_List_Info_txt(char* HAL_Name,char* Info_text)
{
	if(strlen(Info_text)>Information_Size)
	{
		//error
		return false;
	}
	for(uint8_t i=0;i<Get_Peripheral_Conter();i++)
	{
		if(strcmp(HAL_Name,PERIPHERAL_List[i].HAL_Name)==0)
		{
			memset(PERIPHERAL_List[i].Peripheral_Info,0,Information_Size);
			strcpy(PERIPHERAL_List[i].Peripheral_Info,Info_text);
			return true;
		}
	}
	return false;
}

bool Get_Peripheral_index(char* HAL_Name, uint8_t *Index)
{
	//char *s=NULL;
	PERIPHERAL_Str ph;
	for(uint8_t i=0;i<Get_Peripheral_Conter();i++)
	{
		ph=GET_Peripheral_List()[i];
		if(strcmp(HAL_Name,ph.HAL_Name)==0)
		{
			*Index = PERIPHERAL_List[i].index;
			return true;

		}
	}
	return false;
}

bool EDIT_Peripheral_List_Info_ByIndex(uint8_t Index,char* Info_text)
{
	if(Index < Get_Peripheral_Conter())
	{
		Clear_Peripheral_Info(Index);
		strcpy(PERIPHERAL_List[Index].Peripheral_Info,Info_text);
		return true;
	}
	return false;
}
