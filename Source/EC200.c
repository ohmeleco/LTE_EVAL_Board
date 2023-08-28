/*
 * EC200.c
 *
 *  Created on: Nov 24, 2022
 *      Author: Acer
 */

#include "EC200_MID.h"
#include "TEXT_EDITOR_C.h"
#include "NETWORK_C.h"

const char EC200_Default_Local_Port_Char[]   =EC200_Default_Local_Port;
const char EC200_Default_Local_Access_Mode_Char[] =EC200_Default_Access_Mode;

static EC2OO_AT_CMD private_EC2OO_AT_CMD;

OBJ_Identifier obj_id;
OBJ_Config	   obj_config;

bool EC200_Validate_Database(EC2OO_AT_CMD* obj)
{
	if(obj->EC200_STD_VALUE.AT_type == EC200_AT_UNKNOW) return false;
	if(obj->ID.IS_VALID == false) return false;
	if(obj->Config.Config_type !=Configurable_type_YES) return false;
	return true;
}


OBJ_Identifier EC200_Command_init_ID(const char* name, uint16_t id)
{
	//validate data if you needed
	obj_id.IS_VALID=true;
	OBJ_Identifier_Initialize(&obj_id, id, name);
	private_EC2OO_AT_CMD.ID=obj_id;
	return obj_id;
}

void EC200_Command_init_ID_NAME(OBJ_Identifier* obj_type, const char* name)
{
	strcpy((char*)obj_type->OBJ_NAME,name);
}

void EC200_Command_init_ID_ID(OBJ_Identifier* obj_type, uint16_t id)
{
	obj_type->OBJ_ID=id;
}

OBJ_Config EC200_Command_init_Config(Configurable_type_t Configure_type ,uint8_t Number_of_Parameters,uint32_t Time_out,uint8_t Retry_Value)
{
	//validate data if you needed
	obj_config.Config_type=Configure_type;
	obj_config.Time_Out_ms=Time_out;
	OBJ_RETRY_Initialize(&obj_config.Loop_Config,Retry_Value);
	if(Configure_type==Configurable_type_YES)
		obj_config.Number_of_Configurtion_Parameter=Number_of_Parameters;
	else
		obj_config.Number_of_Configurtion_Parameter=0;

	private_EC2OO_AT_CMD.Config=obj_config;
	return obj_config;
}

void EC200_Command_init_Config_Retry(OBJ_Config* obj_type,uint8_t Retry_Value)
{

	obj_type->Loop_Config.Retry_Value=Retry_Value;
	obj_type->Loop_Config.Passed_Retry=false;
	obj_type->Loop_Config.Retry_Counter=0;
}

void EC200_Command_init_Config_TYPE(OBJ_Config* obj_type,Configurable_type_t Configure_type)
{
	obj_type->Config_type=Configure_type;
}

void EC200_Command_init_Config_TimeOut(OBJ_Config* obj_type,uint32_t timeout)
{
	obj_type->Time_Out_ms=timeout;
}


EC2OO_AT_CMD EC200T_Command_Init(OBJ_Identifier *obj_id,OBJ_Config *obj_config,uint16_t Buffer_Size,bool SAVE_BUFFER)
{
	/*
	private_EC2OO_AT_CMD.Config.Config_type = obj_config->Config_type;
	private_EC2OO_AT_CMD.Config.Number_of_Configurtion_Parameter= obj_config->Number_of_Configurtion_Parameter;
	private_EC2OO_AT_CMD.Config.Time_Out_ms = obj_config->Time_Out_ms;
	*/
	memcpy(&private_EC2OO_AT_CMD.ID,obj_id,sizeof(OBJ_Identifier));
	memcpy(&private_EC2OO_AT_CMD.Config,obj_config,sizeof(OBJ_Config));
	private_EC2OO_AT_CMD.Buffer.Buffer_Size=Buffer_Size;
	OBJ_Buffer_Initialize(&private_EC2OO_AT_CMD.Buffer, Buffer_Size);
	return private_EC2OO_AT_CMD;
}


EC2OO_AT_CMD* EC200_Command_COPY_Buffer(EC2OO_AT_CMD* obj)
{
	if(obj->Buffer.Buffer_Size !=0 && obj->EC200_STD_VALUE.AT_type !=EC200_AT_UNKNOW)
		strcpy(obj->Buffer.Buffer,obj->EC200_STD_VALUE.Command_Value);
	return obj;
}

bool EC200_Command_init_Network_CID(EC200_NETWORK_Config *NETWORK,uint8_t Context_ID,uint8_t Connect_ID)
{
	if(Connect_ID <= EC200_MAX_Number_ConnectID && Context_ID <=EC200_MAX_Number_ContexID )
	{
		NETWORK->Connect_ID='0'+Connect_ID;
		NETWORK->Context_ID='0'+Context_ID;
		NETWORK->Connect_ID_DIGIT = Connect_ID;
		NETWORK->Context_ID_DIGIT = Context_ID;
		return true;
	}
	else
		return false;
}


EC2OO_AT_CMD EC200_Command_Init_Network(EC2OO_AT_CMD* obj,EC200_NETWORK_Config *net)
{
	// Validating all value
	// Validate object and net
	if(!EC200_Validate_Database(obj))
	{
		return *obj;
	}
	if(!(net->Context_ID >='0' && net->Context_ID <='9' )) // Check CID
	{
		return *obj;
	}

	switch(net->NET.Network_Type)
	{
		case(NETWORK_TYPE_HTTP):
		{
			break;
		}
		case(NETWORK_TYPE_TCP):
		{

			if(!obj->Buffer.FLAG_Saved_Buffer)	// new object
			{
				OBJ_Buffer_Initialize(&obj->Buffer,obj->EC200_STD_VALUE.Command_Size);

			}
			else
			{
				obj->Buffer.Buffer=OBJ_Buffer_RESIZE(&obj->Buffer,obj->EC200_STD_VALUE.Command_Size);
			}
			EC200_Command_COPY_Buffer(obj);
			// Replace Contex_ID
			obj->Buffer.Buffer=TEXT_EDITOR_Replace_Text_C(obj->Buffer.Buffer, TEXT_EDITORE_SUBSTR_xx1, &net->Context_ID);
			// Replace Connect_ID
			obj->Buffer.Buffer=TEXT_EDITOR_Replace_Text_C(obj->Buffer.Buffer, TEXT_EDITORE_SUBSTR_xx2, &net->Connect_ID);
			// Replace Connection Type--> TCP
			obj->Buffer.Buffer=TEXT_EDITOR_PLACE_Txt_between_Character_C(obj->Buffer.Buffer,TEXT_EDITORE_SUBSTR_xx3,"TCP", TEXT_EDITORE_Double_Quate_char);
			// Replace IP/Domain
			obj->Buffer.Buffer=TEXT_EDITOR_PLACE_Txt_between_Character_C(obj->Buffer.Buffer,TEXT_EDITORE_SUBSTR_xx4, net->NET.OBJ_Net.DOMAIN_OBJ.Buffer, TEXT_EDITORE_Double_Quate_char);
			// Replace PORT
			obj->Buffer.Buffer=TEXT_EDITOR_Replace_Text_C(obj->Buffer.Buffer, TEXT_EDITORE_SUBSTR_xx5, net->NET.OBJ_Net.PORT_OBJ.Buffer);
			// Replace Local Port
			obj->Buffer.Buffer=TEXT_EDITOR_Replace_Text_C(obj->Buffer.Buffer, TEXT_EDITORE_SUBSTR_xx6, (char*)EC200_Default_Local_Port_Char);
			// Replace access Mode
			obj->Buffer.Buffer=TEXT_EDITOR_Replace_Text_C(obj->Buffer.Buffer, TEXT_EDITORE_SUBSTR_xx7, (char*)EC200_Default_Local_Access_Mode_Char);
			break;
		}
		case(NETWORK_TYPE_FTP):
		{
			break;
		}
		case(NETWORK_TYPE_UDP):
		{
			break;
		}
		case(NETWORK_TYPE_NOCHANGE):
		{
			break;
		}
		case(NETWORK_TYPE_UNKNOWN):
		{
			break;
		}
		default:
		{
			break;
		}
	}
	return *obj;
}
