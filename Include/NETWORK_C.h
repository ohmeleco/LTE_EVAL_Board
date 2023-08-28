/*
 * NETWORK_C.h
 *
 *  Created on: Dec 9, 2022
 *      Author: Acer
 */

#ifndef USER_FILE_NETWORK_C_H_
#define USER_FILE_NETWORK_C_H_

#ifdef __cplusplus
extern "C" {
#endif
/* Includes ------------------------------------------------------------------*/
#include "Default_C.h"
#include "TEXT_EDITOR_C.h"
/* Private defines -----------------------------------------------------------*/
#define NETWORK_Max_DOMAIN_SIZE_DIGIT	3


typedef enum NETWORK_TYPE_t
{
	NETWORK_TYPE_UNKNOWN,
	NETWORK_TYPE_TCP,
	NETWORK_TYPE_UDP,
	NETWORK_TYPE_HTTP,
	NETWORK_TYPE_FTP,
	NETWORK_TYPE_NOCHANGE,
}NETWORK_TYPE_t;

typedef struct OBJ_NETWORK_Service
{
	OBJ_Buffer	DOMAIN_SIZE_OBJ;
	OBJ_Buffer 	PORT_OBJ;
	OBJ_Buffer 	PORT_SIZE_OBJ;
	OBJ_Buffer 	TIMEOUT_SEC_OBJ;
	OBJ_Buffer 	DOMAIN_OBJ;
	uint16_t 	DOMAIN_SIZE_N;
	uint16_t 	TIMEOUT_SEC_N;
	uint16_t 	PORT_N;
}OBJ_NETWORK_Service;

typedef struct NETWORK_Service_Config
{
	OBJ_Identifier obj_Id;
	OBJ_NETWORK_Service OBJ_Net;
	NETWORK_TYPE_t Network_Type;
	bool Enable_NETWORK;
}NETWORK_Service_Config;

NETWORK_Service_Config* NETWORK_SERVICE_Config_Connection(NETWORK_Service_Config* obj,char* name,uint16_t id,NETWORK_TYPE_t Network_Type);
NETWORK_Service_Config* NETWORK_SERVICE_Config_Connection_type(NETWORK_Service_Config* obj, NETWORK_TYPE_t Network_Type);
OBJ_NETWORK_Service 	NETWORK_SERVICE_Config(OBJ_NETWORK_Service* obj,char* Domain, char* PORT);
OBJ_NETWORK_Service		NETWORK_SERVICE_Config_PORT(OBJ_NETWORK_Service* obj ,char* PORT);
OBJ_NETWORK_Service 	NETWORK_SERVICE_Config_DOMAIN(OBJ_NETWORK_Service* obj,char* Domain);
NETWORK_Service_Config 	NETWORK_SERVICE_Config_TIME(NETWORK_Service_Config* obj ,uint16_t TimeOut_Sec);

#ifdef __cplusplus
}
#endif

#endif /* USER_FILE_NETWORK_C_H_ */
