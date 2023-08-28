/*
 * Default_C.h
 *
 *  Created on: Nov 24, 2022
 *      Author: Acer
 */

#ifndef INC_USER_LIB_DEFAULT_C_H_
#define INC_USER_LIB_DEFAULT_C_H_

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define OBJ_NAME_SIZE 8
#define OBJ_DEFAULT_BUFFER_SIZE 8

typedef enum Configurable_type_t
{
	Configurable_type_default,
	Configurable_type_YES,
	Configurable_type_NO,
}Configurable_type_t;


typedef struct OBJ_Identifier
{
	char OBJ_NAME[OBJ_NAME_SIZE];
	uint16_t OBJ_ID;
	bool IS_VALID;
}OBJ_Identifier;

typedef struct OBJ_Buffer
{
	uint16_t Buffer_Size;
	char* Buffer;
	bool FLAG_Saved_Buffer;
}OBJ_Buffer;

typedef struct OBJ_RETRY_Config{
	uint8_t Retry_Counter;
	uint8_t Retry_Value;
	bool Active_Retry;
	bool Passed_Retry;
}OBJ_RETRY_Config;

typedef struct OBJ_Config
{
	uint32_t Time_Out_ms;
	uint8_t Number_of_Configurtion_Parameter;
	Configurable_type_t Config_type;
	OBJ_RETRY_Config Loop_Config;
}OBJ_Config;


void OBJ_Identifier_Initialize(OBJ_Identifier *obj,uint16_t id,const char* name);
void OBJ_Buffer_Initialize(OBJ_Buffer *obj,uint16_t Size);
void OBJ_Buffer_Initialize_Defualt(OBJ_Buffer *obj);
char* OBJ_Buffer_RESIZE(OBJ_Buffer *obj,uint16_t Size);
void OBJ_Buffer_DeInitialize(OBJ_Buffer *obj);
void OBJ_Configurtion_Initialize(OBJ_Config *obj,Configurable_type_t Configure_type ,uint8_t Number_of_Parameters,uint32_t Time_out,uint8_t Retry_Value);
OBJ_RETRY_Config OBJ_RETRY_Initialize (OBJ_RETRY_Config* obj, uint8_t Retry_Vale);
void OBJ_Buffer_Clear_Data(OBJ_Buffer *obj);

#endif /* INC_USER_LIB_DEFAULT_C_H_ */
