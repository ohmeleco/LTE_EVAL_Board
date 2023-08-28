/*
 * Default_C.c
 *
 *  Created on: Nov 24, 2022
 *      Author: Acer
 */

#include "Default_C.h"

void OBJ_Identifier_Initialize(OBJ_Identifier *obj,uint16_t id,const char* name)
{
	obj->IS_VALID=true;
	obj->OBJ_ID=id;
	memset((uint8_t*)obj->OBJ_NAME,0,OBJ_NAME_SIZE);
	memcpy((uint8_t*)obj->OBJ_NAME,name,strlen(name));
}

void OBJ_Buffer_Initialize(OBJ_Buffer *obj,uint16_t Size)
{
	obj->FLAG_Saved_Buffer=true;
	obj->Buffer=(char*) malloc(sizeof(char)*Size);
	obj->Buffer_Size=Size;
}

char* OBJ_Buffer_RESIZE(OBJ_Buffer *obj,uint16_t Size)
{
	char* temp=NULL;
	temp=obj->Buffer;
	obj->Buffer=(char*)realloc(obj->Buffer,Size);
	obj->Buffer_Size=Size;
	if(temp!=obj->Buffer)	// new address for reAssigne
		return temp;
	else
		return obj->Buffer;
}

void OBJ_Buffer_DeInitialize(OBJ_Buffer *obj)
{
	obj->FLAG_Saved_Buffer=false;
	obj->Buffer_Size=0;
	free(obj->Buffer);
}
void OBJ_Buffer_Initialize_Defualt(OBJ_Buffer *obj)
{
	obj->FLAG_Saved_Buffer=true;
	obj->Buffer=(char*) malloc(sizeof(char)*OBJ_DEFAULT_BUFFER_SIZE);
}
OBJ_RETRY_Config OBJ_RETRY_Initialize (OBJ_RETRY_Config* obj, uint8_t Retry_Vale)
{
	if(Retry_Vale >0)
	{
		obj->Active_Retry=true;
		obj->Passed_Retry=false;
		obj->Retry_Counter=0;
		obj->Retry_Value=Retry_Vale;
	}
	else
	{
		obj->Active_Retry=false;
		obj->Passed_Retry=false;
		obj->Retry_Counter=0;
		obj->Retry_Value=0;
	}
	return *obj;
}
void OBJ_Configurtion_Initialize(OBJ_Config *obj,Configurable_type_t Configure_type ,uint8_t Number_of_Parameters,uint32_t Time_out,uint8_t Retry_Value)
{
	obj->Config_type=Configure_type;
	obj->Number_of_Configurtion_Parameter=Number_of_Parameters;
	obj->Time_Out_ms=Time_out;
	OBJ_RETRY_Initialize(&obj->Loop_Config,Retry_Value);
}

void OBJ_Buffer_Clear_Data(OBJ_Buffer *obj)
{
	if(obj->FLAG_Saved_Buffer)
		memset(obj->Buffer,0,obj->Buffer_Size);
}

