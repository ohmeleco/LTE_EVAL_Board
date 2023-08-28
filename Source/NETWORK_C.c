/*
 * NETWORK_C.c
 *
 *  Created on: Dec 9, 2022
 *      Author: Acer
 */

#include "NETWORK_C.h"
#include "Default_C.h"

OBJ_NETWORK_Service 	NETWORK_SERVICE_Config(OBJ_NETWORK_Service* obj,char* Domain, char* PORT)
{
	const uint16_t Domain_Size=strlen(Domain);
	const uint8_t  PORT_Size  =strlen(PORT);
	//========================================== Domain Section =============
	if(obj->DOMAIN_OBJ.FLAG_Saved_Buffer)
	{
		obj->DOMAIN_OBJ.Buffer=OBJ_Buffer_RESIZE(&obj->DOMAIN_OBJ, Domain_Size);
	}
	else
	{
		OBJ_Buffer_Initialize(&obj->DOMAIN_OBJ, Domain_Size);
	}
	strcpy(obj->DOMAIN_OBJ.Buffer,Domain);
	//========================================== Domain Section =============

	//========================================== PORT Section 	=============
	if(obj->PORT_OBJ.FLAG_Saved_Buffer)
	{
		obj->PORT_OBJ.Buffer=OBJ_Buffer_RESIZE(&obj->PORT_OBJ, PORT_Size);
	}
	else
	{
		OBJ_Buffer_Initialize(&obj->PORT_OBJ, PORT_Size);
	}
	strcpy(obj->PORT_OBJ.Buffer,PORT);
	//========================================== PORT Section   =============

	//========================================== Domain Size Section ========
	if(obj->DOMAIN_SIZE_N != Domain_Size)
	{
		char s[NETWORK_Max_DOMAIN_SIZE_DIGIT];
		sprintf(s,"%d",Domain_Size);
		obj->DOMAIN_SIZE_N = Domain_Size;
		if(obj->DOMAIN_SIZE_OBJ.FLAG_Saved_Buffer) // reinitialize
		{
			obj->DOMAIN_SIZE_OBJ.Buffer=OBJ_Buffer_RESIZE(&obj->DOMAIN_SIZE_OBJ, TEXT_EDITOR_Return_Digit_Number(Domain_Size));
		}
		else// initialize
		{
			OBJ_Buffer_Initialize(&obj->DOMAIN_SIZE_OBJ, TEXT_EDITOR_Return_Digit_Number(Domain_Size));
		}
		strcpy(obj->DOMAIN_SIZE_OBJ.Buffer,s);

	}
	//========================================== Domain Size Section ========

	//========================================== PORT Size Section 	 ========
	if(obj->PORT_N !=PORT_Size)
	{
		char p[NETWORK_Max_DOMAIN_SIZE_DIGIT];
		sprintf(p,"%d",PORT_Size);
		obj->PORT_N = PORT_Size;
		if(obj->PORT_SIZE_OBJ.FLAG_Saved_Buffer) // reinitialize
		{
			obj->PORT_SIZE_OBJ.Buffer=OBJ_Buffer_RESIZE(&obj->PORT_SIZE_OBJ,TEXT_EDITOR_Return_Digit_Number(PORT_Size));
		}
		else// initialize
		{
			OBJ_Buffer_Initialize(&obj->PORT_SIZE_OBJ, TEXT_EDITOR_Return_Digit_Number(PORT_Size));
		}
		strcpy(obj->PORT_SIZE_OBJ.Buffer,p);
	}
	//========================================== PORT Size Section 	 ========
	return *obj;
}

OBJ_NETWORK_Service 	NETWORK_SERVICE_Config_DOMAIN(OBJ_NETWORK_Service* obj,char* Domain)
{
	const uint16_t Domain_Size=strlen(Domain);

	//========================================== Domain Section =============
	if(obj->DOMAIN_OBJ.FLAG_Saved_Buffer)
	{
		obj->DOMAIN_OBJ.Buffer=OBJ_Buffer_RESIZE(&obj->DOMAIN_OBJ, Domain_Size);
	}
	else
	{
		OBJ_Buffer_Initialize(&obj->DOMAIN_OBJ, Domain_Size);
	}
	strcpy(obj->DOMAIN_SIZE_OBJ.Buffer,Domain);
	//========================================== Domain Section =============

	//========================================== Domain Size Section ========
	if(obj->DOMAIN_SIZE_N != Domain_Size)
	{
		char s[Domain_Size];
		sprintf(s,"%d",Domain_Size);
		obj->DOMAIN_SIZE_N = Domain_Size;
		if(obj->DOMAIN_SIZE_OBJ.FLAG_Saved_Buffer) // reinitialize
		{
			obj->DOMAIN_SIZE_OBJ.Buffer=OBJ_Buffer_RESIZE(&obj->DOMAIN_SIZE_OBJ, Domain_Size);
		}
		else// initialize
		{
			OBJ_Buffer_Initialize(&obj->DOMAIN_SIZE_OBJ, Domain_Size);
		}
		strcpy(obj->DOMAIN_SIZE_OBJ.Buffer,s);

	}
	//========================================== Domain Size Section ========

	return *obj;
}

OBJ_NETWORK_Service 	NETWORK_SERVICE_Config_PORT(OBJ_NETWORK_Service* obj ,char* PORT)
{
	const uint8_t  PORT_Size  =strlen(PORT);

	//========================================== PORT Section 	=============
	if(obj->PORT_OBJ.FLAG_Saved_Buffer)
	{
		obj->PORT_OBJ.Buffer=OBJ_Buffer_RESIZE(&obj->PORT_OBJ, PORT_Size);
	}
	else
	{
		OBJ_Buffer_Initialize(&obj->PORT_OBJ, PORT_Size);
	}
	strcpy(obj->DOMAIN_SIZE_OBJ.Buffer,PORT);
	//========================================== PORT Section   =============

	//========================================== PORT Size Section 	 ========
	if(obj->PORT_N !=PORT_Size)
	{
		char p[PORT_Size];
		sprintf(p,"%d",PORT_Size);
		obj->PORT_N = PORT_Size;
		if(obj->PORT_OBJ.FLAG_Saved_Buffer) // reinitialize
		{
			obj->PORT_OBJ.Buffer=OBJ_Buffer_RESIZE(&obj->PORT_OBJ, PORT_Size);
		}
		else// initialize
		{
			OBJ_Buffer_Initialize(&obj->PORT_OBJ, PORT_Size);
		}
		strcpy(obj->DOMAIN_SIZE_OBJ.Buffer,p);
	}
	//========================================== PORT Size Section 	 ========
	return *obj;
}

NETWORK_Service_Config* NETWORK_SERVICE_Config_Connection_type(NETWORK_Service_Config* obj, NETWORK_TYPE_t Network_Type)
{
	obj->Network_Type=Network_Type;
	return obj;
}

NETWORK_Service_Config* NETWORK_SERVICE_Config_Connection(NETWORK_Service_Config* obj,char* name,uint16_t id,NETWORK_TYPE_t Network_Type)
{
	if(Network_Type != NETWORK_TYPE_NOCHANGE)
		obj->Network_Type=Network_Type;
	if(strlen(name)<OBJ_NAME_SIZE )
	{
		strcpy(obj->obj_Id.OBJ_NAME,name);
		obj->obj_Id.OBJ_ID=id;
		obj->obj_Id.IS_VALID=true;
	}
	return obj;
}

NETWORK_Service_Config 	NETWORK_SERVICE_Config_TIME(NETWORK_Service_Config* obj ,uint16_t TimeOut_Sec)
{
	if(TimeOut_Sec!=obj->OBJ_Net.TIMEOUT_SEC_N)
	{
		obj->OBJ_Net.TIMEOUT_SEC_N=TimeOut_Sec;
		char s[TEXT_EDITOR_Return_Digit_Number(TimeOut_Sec)];
		sprintf(s,"%d",TimeOut_Sec);
		if(obj->OBJ_Net.TIMEOUT_SEC_OBJ.FLAG_Saved_Buffer)
		{
			obj->OBJ_Net.TIMEOUT_SEC_OBJ.Buffer=OBJ_Buffer_RESIZE(&obj->OBJ_Net.TIMEOUT_SEC_OBJ, strlen(s));
		}
		else
		{
			OBJ_Buffer_Initialize(&obj->OBJ_Net.TIMEOUT_SEC_OBJ, strlen(s));
		}
		strcpy(obj->OBJ_Net.TIMEOUT_SEC_OBJ.Buffer,s);
	}
	return *obj;
}
