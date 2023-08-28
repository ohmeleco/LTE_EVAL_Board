/*
 * EC200.h
 *
 *  Created on: Nov 24, 2022
 *      Author: Acer
 */

#ifndef INC_USER_LIB_EC200_H_
#define INC_USER_LIB_EC200_H_

#ifdef __cplusplus
extern "C" {
#endif
/* Includes ------------------------------------------------------------------*/
#include "Default_C.h"
#include "NETWORK_C.h"
/* Private defines -----------------------------------------------------------*/
#define EC200_AT_CMD_USING_DB_TIMEOUT	1	// 1:using database as default value for TimeOut
#define EC200_EMPTY_Byte_Value 0x00
#define EC200_MAX_Number_ContexID	9
#define EC200_MAX_Number_ConnectID	9
#define EC200_Default_Local_Port	"0"
#define EC200_Default_Access_Mode	"0"



typedef enum EC200_AT_Command_t
{
	EC200_AT_UNKNOW,
	// General
	EC200_AT,
	EC200_ATE0,
	EC200_AT_GSN,
	EC200_AT_CGMI,
	EC200_AT_CMEE,
	EC200_AT_CFUN,
	// USIM
	EC200_AT_CPIN,
	EC200_AT_QCCID,
	AT_QINISTAT,
	// NET Services
	EC200_AT_COPS,
	EC200_AT_CREG,
	EC200_AT_CSQ,
	//Phonebook
	//Short Message service (SMS)
	EC200_AT_CNMI,
	EC200_AT_CMGF,
	EC200_AT_CMGD,
	EC200_AT_CMGL,
	EC200_AT_CMGR,
	EC200_AT_CMGS,
	//Packet domain
	EC200_AT_CGATT,
	EC200_AT_CGDCONT,
	EC200_AT_CGACT,
	EC200_AT_CGDATA,
	EC200_AT_CGPADDR,
	EC200_AT_QGDCNT,
	EC200_AT_CGREG,
	// HTTP
	EC200_AT_QHTTPCFG,
	EC200_AT_QHTTPURL,
	EC200_AT_QHTTPGET,
	EC200_AT_QHTTPPOST,
	EC200_AT_QHTTPREAD,
	// TCP/IP
	EC200_AT_QICSGP,
	EC200_AT_QIACT,
	EC200_AT_QIDEACT,
	EC200_AT_QIOPEN,
	EC200_AT_QICLOSE,
	EC200_AT_QISTATE,
	EC200_AT_QISEND,
	EC200_AT_QIRD,
	EC200_AT_QPING,
	//Hardware
	EC200_AT_QPOWD,
	EC200_AT_CCLK
}EC200_AT_Command_t;

typedef enum EC200_AT_RESPONSE_TYPE_t
{
	EC200_AT_RESPONSE_MSG_NON,
	EC200_AT_RESPONSE_MSG_OK,
	EC200_AT_RESPONSE_MULTI_STep,
	EC200_AT_RESPONSE_MSG_ERROR,
	EC200_AT_RESPONSE_MSG_Execut,
}EC200_AT_RESPONSE_MSG_TYPE_t;




typedef struct EC200_Database_Struct{
	char* 	 Command_Value;
	uint16_t Command_Size;
	uint32_t Command_TimeOut;
	EC200_AT_Command_t AT_type;
}EC200_Database_Struct;

typedef struct EC2OO_AT_CMD
{
	EC200_Database_Struct EC200_STD_VALUE;
	OBJ_Identifier ID;
	OBJ_Buffer Buffer;
	OBJ_Config Config;
}EC2OO_AT_CMD;

typedef struct EC200_NETWORK_Config
{
	char  Context_ID;
	char  Connect_ID;
	uint8_t  Context_ID_DIGIT;
	uint8_t  Connect_ID_DIGIT;
	NETWORK_Service_Config NET;
}EC200_NETWORK_Config;




OBJ_Identifier EC200_Command_init_ID(const char* name, uint16_t id);
void EC200_Command_init_ID_ID(OBJ_Identifier* obj_type, uint16_t id);
void EC200_Command_init_ID_NAME(OBJ_Identifier* obj_type, const char* name);


OBJ_Config EC200_Command_init_Config(Configurable_type_t Configure_type ,uint8_t Number_of_Parameters,uint32_t Time_out,uint8_t Retry_Value);
void EC200_Command_init_Config_TimeOut(OBJ_Config* obj_type,uint32_t timeout);
void EC200_Command_init_Config_TYPE(OBJ_Config* obj_type,Configurable_type_t Configure_type);
void EC200_Command_init_Config_Retry(OBJ_Config* obj_type,uint8_t Retry_Value);
EC2OO_AT_CMD EC200_Command_Init_Network(EC2OO_AT_CMD* obj,EC200_NETWORK_Config *net);

EC2OO_AT_CMD* EC200_Command_COPY_Buffer(EC2OO_AT_CMD* obj);
bool EC200_Command_init_Network_CID(EC200_NETWORK_Config *NETWORK,uint8_t Context_ID,uint8_t Connect_ID);
#ifdef __cplusplus
}
#endif

#endif /* INC_USER_LIB_EC200_H_ */
