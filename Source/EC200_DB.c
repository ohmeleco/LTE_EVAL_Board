/*
 * EC200_DB.c
 *
 *  Created on: Nov 29, 2022
 *      Author: mosavi
 */


#include "EC200.h"
#include "EC200_DB.h"

// ============================= General ==============
const char EC200_CMD_AT_Char	 []=	 	EC200_CMD_AT_Value;
const char EC200_CMD_ATE0_Char	 []=		EC200_CMD_ATE0_Value;
const char EC200_CMD_AT_GSN_Char []=		EC200_CMD_AT_GSN_Value;
const char EC200_CMD_AT_CGMI_Char[]=		EC200_CMD_AT_CGMI_Value;
const char EC200_CMD_AT_CMEE_Char[]=		EC200_CMD_AT_CMEE_Value;
const char EC200_CMD_AT_CFUN_Char[]=		EC200_CMD_AT_CFUN_Value;
// ============================= General ==============


// ============================= USIM ==============
const char EC200_CMD_AT_CPIN_Char[]=		EC200_CMD_AT_CPIN_Value;
const char EC200_CMD_AT_QCCID_Char[]=		EC200_CMD_AT_QCCID_Value;
const char EC200_CMD_AT_QINISTAT_Char[]=	EC200_CMD_AT_QINISTAT_Value;
// ============================= USIM ==============


// ============================= NET Services ======
const char EC200_CMD_AT_COPS_Char[]=		EC200_CMD_AT_COPS_Value;
const char EC200_CMD_AT_CREG_Char[]=		EC200_CMD_AT_CREG_Value;
const char EC200_CMD_AT_CSQ_Char []=		EC200_CMD_AT_CSQ_Value;
// ============================= NET Services ======


// ============================= SMS ===============
const char EC200_CMD_AT_CNMI_Char[]=		EC200_CMD_AT_CNMI_Value;
const char EC200_CMD_AT_CMGF_Char[]=		EC200_CMD_AT_CMGF_Value;
const char EC200_CMD_AT_CMGD_Char[]=		EC200_CMD_AT_CMGD_Value;
const char EC200_CMD_AT_CMGL_Char[]=		EC200_CMD_AT_CMGL_Value;
const char EC200_CMD_AT_CMGR_Char[]=		EC200_CMD_AT_CMGR_Value;
const char EC200_CMD_AT_CMGS_Char[]=		EC200_CMD_AT_CMGS_Value;
// ============================= SMS ===============


// ============================= Packet ============
const char EC200_CMD_AT_CGATT_Char    []=	EC200_CMD_AT_CGATT_Value;
const char EC200_CMD_AT_CGDCONT_Char  []=	EC200_CMD_AT_CGDCONT_Value;
const char EC200_CMD_AT_CGACT_Char    []=	EC200_CMD_AT_CGACT_Value;
const char EC200_CMD_AT_CGDATA_Char   []=	EC200_CMD_AT_CGDATA_Value;
const char EC200_CMD_AT_CGPADDR_Char  []=	EC200_CMD_AT_CGPADDR_Value;
const char EC200_CMD_AT_QGDCNT_Char   []=	EC200_CMD_AT_QGDCNT_Value;
const char EC200_CMD_AT_CGREG_Char    []=	EC200_CMD_AT_CGREG_Value;
// ============================= Packet ============


// ============================= HTTP ============
const char EC200_CMD_AT_QHTTPCFG_Char []=	EC200_CMD_AT_QHTTPCFG_Value;
const char EC200_CMD_AT_QHTTPURL_Char []=	EC200_CMD_AT_QHTTPURL_Value;
const char EC200_CMD_AT_QHTTPGET_Char []=	EC200_CMD_AT_QHTTPGET_Value;
const char EC200_CMD_AT_QHTTPPOST_Char[]= 	EC200_CMD_AT_QHTTPPOST_Value;
const char EC200_CMD_AT_QHTTPREAD_Char[]= 	EC200_CMD_AT_QHTTPREAD_Value;
// ============================= HTTP ============


// ============================= TCP/IP ============
const char EC200_CMD_AT_QICSGP_Char []=		EC200_CMD_AT_QICSGP_Value;
const char EC200_CMD_AT_QIACT_Char  []=		EC200_CMD_AT_QIACT_Value;
const char EC200_CMD_AT_QIDEACT_Char[]=		EC200_CMD_AT_QIDEACT_Value;
const char EC200_CMD_AT_QIOPEN_Char []= 	EC200_CMD_AT_QIOPEN_Value;
const char EC200_CMD_AT_QICLOSE_Char[]= 	EC200_CMD_AT_QICLOSE_Value;
const char EC200_CMD_AT_QISTATE_Char[]=		EC200_CMD_AT_QISTATE_Value;
const char EC200_CMD_AT_QISEND_Char []=		EC200_CMD_AT_QISEND_Value;
const char EC200_CMD_AT_QIRD_Char	[]=		EC200_CMD_AT_QIRD_Value;
const char EC200_CMD_AT_QPING_Char	[]= 	EC200_CMD_AT_QPING_Value;
// ============================= TCP/IP ============

// ============================= Hardware ===========
const char EC200_CMD_AT_QPOWD_Char[]=	EC200_CMD_AT_QPOWD_Value;
const char EC200_CMD_AT_CCLK_Char []= 	EC200_CMD_AT_CCLK_Value;
// ============================= Hardware ===========



EC200_Database_Struct EC200_Create_DataBase_str(EC200_AT_Command_t User_List,EC200_Database_Struct* USER_EC200_Struct_List)
{
	USER_EC200_Struct_List->AT_type=User_List;
	switch(User_List)
	{
		case(EC200_AT):
		{
			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_AT_Char;
			USER_EC200_Struct_List->Command_Size	= EC200_CMD_AT_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_AT_TIMEOUT;
			break;
		}
		case(EC200_ATE0):
		{
			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_ATE0_Char;
			USER_EC200_Struct_List->Command_Size	=EC200_CMD_ATE0_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_ATE0_TIMEOUT;
			break;
		}
		case(EC200_AT_GSN):
		{
			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_AT_GSN_Char;
			USER_EC200_Struct_List->Command_Size	=EC200_CMD_AT_GSN_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_AT_GSN_TIMEOUT;
			break;
		}
		case(EC200_AT_CGMI):
		{
			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_AT_CGMI_Char;
			USER_EC200_Struct_List->Command_Size	=EC200_CMD_AT_CGMI_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_AT_CGMI_TIMEOUT;
			break;
		}
		case(EC200_AT_CMEE):
		{
			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_AT_CMEE_Char;
			USER_EC200_Struct_List->Command_Size	=EC200_CMD_AT_CMEE_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_AT_CMEE_TIMEOUT;
			break;
		}
		case(EC200_AT_CFUN):
		{
			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_AT_CFUN_Char;
			USER_EC200_Struct_List->Command_Size	=EC200_CMD_AT_CFUN_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_AT_CFUN_TIMEOUT;
			break;
		}
		case(EC200_AT_CPIN):
		{
			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_AT_CPIN_Char;
			USER_EC200_Struct_List->Command_Size	=EC200_CMD_AT_CPIN_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_AT_CGMI_TIMEOUT;
			break;
		}
		case(EC200_AT_QCCID):
		{
			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_AT_QCCID_Char;
			USER_EC200_Struct_List->Command_Size	=EC200_CMD_AT_QCCID_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_AT_QCCID_TIMEOUT;
			break;
		}
		case(AT_QINISTAT):
		{
			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_AT_QINISTAT_Char;
			USER_EC200_Struct_List->Command_Size	=EC200_CMD_AT_QINISTAT_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_AT_QINISTAT_TIMEOUT;
			break;
		}
		case(EC200_AT_COPS):
		{
			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_AT_COPS_Char;
			USER_EC200_Struct_List->Command_Size	=EC200_CMD_AT_COPS_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_AT_COPS_TIMEOUT;
			break;
		}
		case(EC200_AT_CREG):
		{
			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_AT_CREG_Char;
			USER_EC200_Struct_List->Command_Size	=EC200_CMD_AT_CREG_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_AT_CREG_TIMEOUT;
			break;
		}
		case(EC200_AT_CSQ):
		{
			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_AT_CSQ_Char;
			USER_EC200_Struct_List->Command_Size	=EC200_CMD_AT_CSQ_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_AT_CSQ_TIMEOUT;
			break;
		}
		case(EC200_AT_CMGF):
		{

			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_AT_CMGF_Char;
			USER_EC200_Struct_List->Command_Size	=EC200_CMD_AT_CMGF_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_AT_CMGF_TIMEOUT;
			break;
		}
		case(EC200_AT_CNMI):
		{
			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_AT_CNMI_Char;
			USER_EC200_Struct_List->Command_Size	=EC200_CMD_AT_CNMI_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_AT_CNMI_TIMEOUT;
			break;
		}
		case(EC200_AT_CMGD):
		{
			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_AT_CMGD_Char;
			USER_EC200_Struct_List->Command_Size	=EC200_CMD_AT_CMGD_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_AT_CMGD_TIMEOUT;
			break;
		}
		case(EC200_AT_CMGL):
		{
			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_AT_CMGL_Char;
			USER_EC200_Struct_List->Command_Size	=EC200_CMD_AT_CMGL_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_AT_CMGL_TIMEOUT;
			break;
		}
		case(EC200_AT_CMGR):
		{
			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_AT_CMGR_Char;
			USER_EC200_Struct_List->Command_Size	=EC200_CMD_AT_CMGR_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_AT_CMGR_TIMEOUT;
			break;
		}
		case(EC200_AT_CMGS):
		{
			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_AT_CMGS_Char;
			USER_EC200_Struct_List->Command_Size	=EC200_CMD_AT_CMGS_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_AT_CMGS_TIMEOUT;
			break;
		}

		case(EC200_AT_CGATT):
		{
			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_AT_CGATT_Char;
			USER_EC200_Struct_List->Command_Size	=EC200_CMD_AT_CGATT_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_AT_CGATT_TIMEOUT;
			break;
		}
		case(EC200_AT_CGDCONT):
		{
			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_AT_CGDCONT_Char;
			USER_EC200_Struct_List->Command_Size	=EC200_CMD_AT_CGDCONT_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_AT_CGDCONT_TIMEOUT;
			break;
		}
		case(EC200_AT_CGACT):
		{
			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_AT_CGACT_Char;
			USER_EC200_Struct_List->Command_Size	=EC200_CMD_AT_CGACT_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_AT_CGACT_TIMEOUT;
			break;
		}
		case(EC200_AT_CGDATA):
		{
			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_AT_CGDATA_Char;
			USER_EC200_Struct_List->Command_Size	=EC200_CMD_AT_CGDATA_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_AT_CGDATA_TIMEOUT;
			break;
		}
		case(EC200_AT_CGPADDR):
		{
			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_AT_CGPADDR_Char;
			USER_EC200_Struct_List->Command_Size	=EC200_CMD_AT_CGPADDR_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_AT_CGPADDR_TIMEOUT;
			break;
		}
		case(EC200_AT_QGDCNT):
		{
			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_AT_QGDCNT_Char;
			USER_EC200_Struct_List->Command_Size	=EC200_CMD_AT_QGDCNT_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_AT_QGDCNT_TIMEOUT;
			break;
		}
		case(EC200_AT_CGREG):
		{
			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_AT_CGREG_Char;
			USER_EC200_Struct_List->Command_Size	=EC200_CMD_AT_CGREG_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_AT_CGREG_TIMEOUT;
			break;
		}

		case(EC200_AT_QHTTPCFG):
		{
			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_AT_QHTTPCFG_Char;
			USER_EC200_Struct_List->Command_Size	=EC200_CMD_AT_QHTTPCFG_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_AT_QHTTPCFG_TIMEOUT;
			break;
		}
		case(EC200_AT_QHTTPURL):
		{
			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_AT_QHTTPURL_Char;
			USER_EC200_Struct_List->Command_Size	=EC200_CMD_AT_QHTTPURL_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_AT_QHTTPURL_TIMEOUT;
			break;
		}
		case(EC200_AT_QHTTPGET):
		{
			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_AT_QHTTPGET_Char;
			USER_EC200_Struct_List->Command_Size	=EC200_CMD_AT_QHTTPGET_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_AT_QHTTPGET_TIMEOUT;
			break;
		}
		case(EC200_AT_QHTTPPOST):
		{
			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_AT_QHTTPPOST_Char;
			USER_EC200_Struct_List->Command_Size	=EC200_CMD_AT_QHTTPPOST_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_AT_QHTTPPOST_TIMEOUT;
			break;
		}
		case(EC200_AT_QHTTPREAD):
		{
			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_AT_QHTTPREAD_Char;
			USER_EC200_Struct_List->Command_Size	=EC200_CMD_AT_QHTTPREAD_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_AT_QHTTPREAD_TIMEOUT;
			break;
		}

		case(EC200_AT_QICSGP):
		{
			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_AT_QICSGP_Char;
			USER_EC200_Struct_List->Command_Size	=EC200_CMD_AT_QICSGP_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_AT_QICSGP_TIMEOUT;
			break;
		}
		case(EC200_AT_QIACT):
		{
			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_AT_QIACT_Char;
			USER_EC200_Struct_List->Command_Size	=EC200_CMD_AT_QIACT_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_AT_QIACT_TIMEOUT;
			break;
		}
		case(EC200_AT_QIDEACT):
		{
			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_AT_QIDEACT_Char;
			USER_EC200_Struct_List->Command_Size	=EC200_CMD_AT_QIDEACT_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_AT_QIDEACT_TIMEOUT;
			break;
		}
		case(EC200_AT_QIOPEN):
		{
			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_AT_QIOPEN_Char;
			USER_EC200_Struct_List->Command_Size	=EC200_CMD_AT_QIOPEN_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_AT_QIOPEN_TIMEOUT;
			break;
		}
		case(EC200_AT_QICLOSE):
		{
			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_AT_QICLOSE_Char;
			USER_EC200_Struct_List->Command_Size	=EC200_CMD_AT_QICLOSE_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_AT_QICLOSE_TIMEOUT;
			break;
		}
		case(EC200_AT_QISTATE):
		{
			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_AT_QISTATE_Char;
			USER_EC200_Struct_List->Command_Size	=EC200_CMD_AT_QISTATE_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_AT_QISTATE_TIMEOUT;
			break;
		}
		case(EC200_AT_QISEND):
		{
			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_AT_QISEND_Char;
			USER_EC200_Struct_List->Command_Size	=EC200_CMD_AT_QISEND_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_AT_QISEND_TIMEOUT;
			break;
		}
		case(EC200_AT_QIRD):
		{
			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_AT_QIRD_Char;
			USER_EC200_Struct_List->Command_Size	=EC200_CMD_AT_QIRD_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_AT_QIRD_TIMEOUT;
			break;
		}
		case(EC200_AT_QPING):
		{
			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_AT_QPING_Char;
			USER_EC200_Struct_List->Command_Size	=EC200_CMD_AT_QPING_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_AT_QPING_TIMEOUT;
			break;
		}

		case(EC200_AT_QPOWD):
		{
			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_AT_QPOWD_Char;
			USER_EC200_Struct_List->Command_Size	=EC200_CMD_AT_QPOWD_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_AT_QPOWD_TIMEOUT;
			break;
		}
		case(EC200_AT_CCLK):
		{
			USER_EC200_Struct_List->Command_Value	=(char*)EC200_CMD_AT_CCLK_Char;
			USER_EC200_Struct_List->Command_Size	=EC200_CMD_AT_CCLK_Size;
			USER_EC200_Struct_List->Command_TimeOut =EC200_CMD_AT_CCLK_TIMEOUT;
			break;
		}
		default:
		{
			USER_EC200_Struct_List->AT_type=EC200_AT_UNKNOW;
			break;
		}

	}
	return *USER_EC200_Struct_List;
}

EC2OO_AT_CMD* EC200_Create_DataBase_List(EC200_AT_Command_t* User_List,uint16_t size,EC2OO_AT_CMD* USER_EC200_AT_List)
{
	uint16_t i=0;
	if(USER_EC200_AT_List!=NULL)	// if address is empty
		USER_EC200_AT_List = (EC2OO_AT_CMD*)malloc(sizeof(EC2OO_AT_CMD)*size);
	USER_EC200_AT_List = (EC2OO_AT_CMD*)realloc(USER_EC200_AT_List, size);
	// clear all
	memset(USER_EC200_AT_List,EC200_EMPTY_Byte_Value,sizeof(EC2OO_AT_CMD)*size);

	for(i=0;i<size;i++)
	{
		EC200_Create_DataBase_str(User_List[i],&USER_EC200_AT_List[i].EC200_STD_VALUE);
		if(USER_EC200_AT_List->EC200_STD_VALUE.AT_type!=EC200_AT_UNKNOW)
		{
			USER_EC200_AT_List->ID.IS_VALID=true;
			USER_EC200_AT_List->ID.OBJ_ID=i;
		}
	}
	return USER_EC200_AT_List;
}
