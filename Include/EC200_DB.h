/*
 * EC200_DB.h
 *
 *  Created on: Nov 26, 2022
 *      Author: mosavi
 */

#ifndef INC_USER_LIB_EC200_DB_H_
#define INC_USER_LIB_EC200_DB_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "EC200.h"


#define EC200_Default_APN_NAME	"mtnirancell"

#define EC200_AT_CMD_General_TIMEOUT	500
#define EC200_AT_CMD_Hardware_TIMEOUT	500
#define EC200_AT_CMD_TCPIP_TIMEOUT		500
#define EC200_AT_CMD_HTTP_TIMEOUT		2000
#define EC200_AT_CMD_PACKET_TIMEOUT		500
#define EC200_AT_CMD_SMS_TIMEOUT		500
#define EC200_AT_CMD_NET_TIMEOUT		500
#define EC200_AT_CMD_USIM_TIMEOUT		500

// ============================= General ==============
#define EC200_CMD_AT_Value 			"AT\r\n"
#define EC200_CMD_ATE0_Value 		"ATE0\r\n"
#define EC200_CMD_AT_GSN_Value		"AT+GSN\r\n"
#define EC200_CMD_AT_CGMI_Value		"AT+CGMI\r\n"
#define EC200_CMD_AT_CMEE_Value		"AT+CMEE=xx1\r\n"
#define EC200_CMD_AT_CFUN_Value		"AT+CFUN=xx1\r\n"
// ============================= General ==============

// ============================= USIM ==============
#define EC200_CMD_AT_CPIN_Value		"AT+CPIN=xx1\r\n"
#define EC200_CMD_AT_QCCID_Value	"AT+QCCID=xx1\r\n"
#define EC200_CMD_AT_QINISTAT_Value	"AT+QINISTAT\r\n"
// ============================= USIM ==============

// ============================= NET Services ======
#define EC200_CMD_AT_COPS_Value		"AT+COPS?\r\n"
#define EC200_CMD_AT_CREG_Value		"AT+CREG=xx1\r\n"
#define EC200_CMD_AT_CSQ_Value		"AT+CSQ\r\n"
// ============================= NET Services ======

// ============================= SMS ===============
#define EC200_CMD_AT_CNMI_Value		"AT+CNMI=xx1\r\n"
#define EC200_CMD_AT_CMGF_Value		"AT+CMGF=xx1\r\n"
#define EC200_CMD_AT_CMGD_Value		"AT+CMGD=xx1\r\n"
#define EC200_CMD_AT_CMGL_Value		"AT+CMGL=xx1\r\n"
#define EC200_CMD_AT_CMGR_Value		"AT+CMGR=xx1\r\n"
#define EC200_CMD_AT_CMGS_Value		"AT+CMGS=xx1\r\n"
// ============================= SMS ===============


// ============================= Packet ============
#define EC200_CMD_AT_CGATT_Value	"AT+CGATT=xx1\r\n"
#define EC200_CMD_AT_CGDCONT_Value	"AT+CGDCONT=xx1,xx2,xx3\r\n"
#define EC200_CMD_AT_CGACT_Value	"AT+CGACT=xx1,xx2\r\n"
#define EC200_CMD_AT_CGDATA_Value	"AT+CGDATA=xx1\r\n"
#define EC200_CMD_AT_CGPADDR_Value	"AT+CGPADDR=xx1\r\n"
#define EC200_CMD_AT_QGDCNT_Value	"AT+QGDCNT=xx1\r\n"
#define EC200_CMD_AT_CGREG_Value	"AT+CGREG=xx1\r\n"
// ============================= Packet ============


// ============================= HTTP ============
#define EC200_CMD_AT_QHTTPCFG_Value	 "AT+QHTTPCFG=xx1,xx2\r\n"
#define EC200_CMD_AT_QHTTPURL_Value	 "AT+QHTTPURL=xx1,xx2\r\n"
#define EC200_CMD_AT_QHTTPGET_Value	 "AT+QHTTPGET=xx1\r\n"
#define EC200_CMD_AT_QHTTPPOST_Value "AT+QHTTPPOST=xx1,xx2,xx3\r\n"
#define EC200_CMD_AT_QHTTPREAD_Value "AT+QHTTPREAD=xx1\r\n"
// ============================= HTTP ============


// ============================= TCP/IP ============
#define EC200_CMD_AT_QICSGP_Value	"AT+QICSGP=xx1,xx2,xx3,xx4,xx5,xx6\r\n"
#define EC200_CMD_AT_QIACT_Value	"AT+QIACT=xx1\r\n"
#define EC200_CMD_AT_QIDEACT_Value	"AT+QIDEACT=xx1\r\n"
#define EC200_CMD_AT_QIOPEN_Value 	"AT+QIOPEN=xx1,xx2,xx3,xx4,xx5,xx6,xx7\r\n"
#define EC200_CMD_AT_QICLOSE_Value 	"AT+QICLOSE=xx1\r\n"
#define EC200_CMD_AT_QISTATE_Value	"AT+QISTATE=xx1,xx2\r\n"
#define EC200_CMD_AT_QISEND_Value	"AT+QISEND=xx1,xx2\r\n"
#define EC200_CMD_AT_QIRD_Value		"AT+QIRD=xx1,xx2\r\n"
#define EC200_CMD_AT_QPING_Value 	"AT+QPING=xx1,xx2\r\n"
// ============================= TCP/IP ============


// ============================= Hardware ===========
#define EC200_CMD_AT_QPOWD_Value	"ATQPOWD=xx1\r\n"
#define EC200_CMD_AT_CCLK_Value 	"AT+CCLK=?\r\n"
// ============================= Hardware ===========


// ============================= General ==============(string size)
#define EC200_CMD_AT_Size 			sizeof(EC200_CMD_AT_Value)-1
#define EC200_CMD_ATE0_Size			sizeof(EC200_CMD_ATE0_Value)-1
#define EC200_CMD_AT_GSN_Size		sizeof(EC200_CMD_AT_GSN_Value)-1
#define EC200_CMD_AT_CGMI_Size		sizeof(EC200_CMD_AT_CGMI_Value)-1
#define EC200_CMD_AT_CMEE_Size		sizeof(EC200_CMD_AT_CMEE_Value)-1
#define EC200_CMD_AT_CFUN_Size		sizeof(EC200_CMD_AT_CFUN_Value)-1
// ============================= General ==============

// ============================= USIM =================(string size)
#define EC200_CMD_AT_CPIN_Size		sizeof(EC200_CMD_AT_CPIN_Value)-1
#define EC200_CMD_AT_QCCID_Size		sizeof(EC200_CMD_AT_QCCID_Value)-1
#define EC200_CMD_AT_QINISTAT_Size	sizeof(EC200_CMD_AT_QINISTAT_Value)-1
// ============================= USIM =================(string size)

// ============================= NET Services =========(string size)
#define EC200_CMD_AT_COPS_Size		sizeof(EC200_CMD_AT_COPS_Value)-1
#define EC200_CMD_AT_CREG_Size		sizeof(EC200_CMD_AT_CREG_Value)-1
#define EC200_CMD_AT_CSQ_Size		sizeof(EC200_CMD_AT_CSQ_Value)-1
// ============================= NET Services =========(string size)

// ============================= SMS ==================(string size)
#define EC200_CMD_AT_CNMI_Size		sizeof(EC200_CMD_AT_CNMI_Value)-1
#define EC200_CMD_AT_CMGF_Size		sizeof(EC200_CMD_AT_CMGF_Value)-1
#define EC200_CMD_AT_CMGD_Size		sizeof(EC200_CMD_AT_CMGF_Value)-1
#define EC200_CMD_AT_CMGL_Size		sizeof(EC200_CMD_AT_CMGF_Value)-1
#define EC200_CMD_AT_CMGR_Size		sizeof(EC200_CMD_AT_CMGF_Value)-1
#define EC200_CMD_AT_CMGS_Size		sizeof(EC200_CMD_AT_CMGF_Value)-1
// ============================= SMS ==================(string size)

// ============================= Packet ===============(string size)
#define EC200_CMD_AT_CGATT_Size		sizeof(EC200_CMD_AT_CGATT_Value)-1
#define EC200_CMD_AT_CGDCONT_Size	sizeof(EC200_CMD_AT_CGDCONT_Value)-1
#define EC200_CMD_AT_CGACT_Size		sizeof(EC200_CMD_AT_CGACT_Value)-1
#define EC200_CMD_AT_CGDATA_Size	sizeof(EC200_CMD_AT_CGDATA_Value)-1
#define EC200_CMD_AT_CGPADDR_Size	sizeof(EC200_CMD_AT_CGPADDR_Value)-1
#define EC200_CMD_AT_QGDCNT_Size	sizeof(EC200_CMD_AT_QGDCNT_Value)-1
#define EC200_CMD_AT_CGREG_Size		sizeof(EC200_CMD_AT_CGREG_Value)-1
// ============================= Packet ===============(string size)

// ============================= HTTP =================(string size)
#define EC200_CMD_AT_QHTTPCFG_Size	 sizeof(EC200_CMD_AT_QHTTPCFG_Value)-1
#define EC200_CMD_AT_QHTTPURL_Size	 sizeof(EC200_CMD_AT_QHTTPURL_Value)-1
#define EC200_CMD_AT_QHTTPGET_Size	 sizeof(EC200_CMD_AT_QHTTPGET_Value)-1
#define EC200_CMD_AT_QHTTPPOST_Size  sizeof(EC200_CMD_AT_QHTTPPOST_Value)-1
#define EC200_CMD_AT_QHTTPREAD_Size  sizeof(EC200_CMD_AT_QHTTPREAD_Value)-1
// ============================= HTTP =================(string size)

// ============================= TCP/IP ===============(string size)
#define EC200_CMD_AT_QICSGP_Size	sizeof(EC200_CMD_AT_QICSGP_Value)-1
#define EC200_CMD_AT_QIACT_Size		sizeof(EC200_CMD_AT_QIACT_Value)-1
#define EC200_CMD_AT_QIDEACT_Size	sizeof(EC200_CMD_AT_QIDEACT_Value)-1
#define EC200_CMD_AT_QIOPEN_Size 	sizeof(EC200_CMD_AT_QIOPEN_Value)-1
#define EC200_CMD_AT_QICLOSE_Size 	sizeof(EC200_CMD_AT_QICLOSE_Value)-1
#define EC200_CMD_AT_QISTATE_Size	sizeof(EC200_CMD_AT_QISTATE_Value)-1
#define EC200_CMD_AT_QISEND_Size	sizeof(EC200_CMD_AT_QISEND_Value)-1
#define EC200_CMD_AT_QIRD_Size		sizeof(EC200_CMD_AT_QIRD_Value)-1
#define EC200_CMD_AT_QPING_Size 	sizeof(EC200_CMD_AT_QPING_Value)-1
// ============================= TCP/IP ===============(string size)

// ============================= Hardware ===========
#define EC200_CMD_AT_QPOWD_Size		sizeof(EC200_CMD_AT_QPOWD_Value)-1
#define EC200_CMD_AT_CCLK_Size 		sizeof(EC200_CMD_AT_CCLK_Value)-1
// ============================= Hardware ===========




// ============================= General ==============(uint32_t)
#define EC200_CMD_AT_TIMEOUT 			EC200_AT_CMD_General_TIMEOUT
#define EC200_CMD_ATE0_TIMEOUT 			EC200_AT_CMD_General_TIMEOUT
#define EC200_CMD_AT_GSN_TIMEOUT		EC200_AT_CMD_General_TIMEOUT
#define EC200_CMD_AT_CGMI_TIMEOUT		EC200_AT_CMD_General_TIMEOUT
#define EC200_CMD_AT_CMEE_TIMEOUT		EC200_AT_CMD_General_TIMEOUT
#define EC200_CMD_AT_CFUN_TIMEOUT		15000
// ============================= General ==============(uint32_t)

// ============================= USIM =================(uint32_t)
#define EC200_CMD_AT_CPIN_TIMEOUT		5000
#define EC200_CMD_AT_QCCID_TIMEOUT		EC200_AT_CMD_USIM_TIMEOUT
#define EC200_CMD_AT_QINISTAT_TIMEOUT	EC200_AT_CMD_USIM_TIMEOUT
// ============================= USIM =================(uint32_t)

// ============================= NET Services =========(uint32_t)
#define EC200_CMD_AT_COPS_TIMEOUT		180000
#define EC200_CMD_AT_CREG_TIMEOUT		EC200_AT_CMD_NET_TIMEOUT
#define EC200_CMD_AT_CSQ_TIMEOUT		EC200_AT_CMD_NET_TIMEOUT
// ============================= NET Services =========(uint32_t)

// ============================= SMS ==================(uint32_t)
#define EC200_CMD_AT_CNMI_TIMEOUT		EC200_AT_CMD_SMS_TIMEOUT
#define EC200_CMD_AT_CMGF_TIMEOUT		EC200_AT_CMD_SMS_TIMEOUT
#define EC200_CMD_AT_CMGD_TIMEOUT		EC200_AT_CMD_SMS_TIMEOUT
#define EC200_CMD_AT_CMGL_TIMEOUT		EC200_AT_CMD_SMS_TIMEOUT
#define EC200_CMD_AT_CMGR_TIMEOUT		EC200_AT_CMD_SMS_TIMEOUT	//Depends on the length of message content
#define EC200_CMD_AT_CMGS_TIMEOUT		120000
// ============================= SMS ==================(uint32_t)


// ============================= Packet ===============(uint32_t)
#define EC200_CMD_AT_CGATT_TIMEOUT		140000
#define EC200_CMD_AT_CGDCONT_TIMEOUT	EC200_AT_CMD_PACKET_TIMEOUT
#define EC200_CMD_AT_CGACT_TIMEOUT		150000
#define EC200_CMD_AT_CGDATA_TIMEOUT		EC200_AT_CMD_PACKET_TIMEOUT
#define EC200_CMD_AT_CGPADDR_TIMEOUT	EC200_AT_CMD_PACKET_TIMEOUT
#define EC200_CMD_AT_QGDCNT_TIMEOUT		EC200_AT_CMD_PACKET_TIMEOUT
#define EC200_CMD_AT_CGREG_TIMEOUT		EC200_AT_CMD_PACKET_TIMEOUT
// ============================= Packet ===============(uint32_t)


// ============================= HTTP =================(uint32_t)
#define EC200_CMD_AT_QHTTPCFG_TIMEOUT	EC200_AT_CMD_HTTP_TIMEOUT
#define EC200_CMD_AT_QHTTPURL_TIMEOUT	60000
#define EC200_CMD_AT_QHTTPGET_TIMEOUT	60000
#define EC200_CMD_AT_QHTTPPOST_TIMEOUT  125000
#define EC200_CMD_AT_QHTTPREAD_TIMEOUT  600000
// ============================= HTTP =================(uint32_t)


// ============================= TCP/IP ===============(uint32_t)
#define EC200_CMD_AT_QICSGP_TIMEOUT	 	EC200_AT_CMD_TCPIP_TIMEOUT
#define EC200_CMD_AT_QIACT_TIMEOUT	 	150000
#define EC200_CMD_AT_QIDEACT_TIMEOUT 	40000
#define EC200_CMD_AT_QIOPEN_TIMEOUT  	150000
#define EC200_CMD_AT_QICLOSE_TIMEOUT 	10000
#define EC200_CMD_AT_QISTATE_TIMEOUT 	EC200_AT_CMD_TCPIP_TIMEOUT
#define EC200_CMD_AT_QISEND_TIMEOUT	 	EC200_AT_CMD_TCPIP_TIMEOUT
#define EC200_CMD_AT_QIRD_TIMEOUT	 	EC200_AT_CMD_TCPIP_TIMEOUT
#define EC200_CMD_AT_QPING_TIMEOUT 	 	4000
// ============================= TCP/IP ===============(string size)



// ============================= Hardware ===========
#define EC200_CMD_AT_QPOWD_TIMEOUT		EC200_AT_CMD_Hardware_TIMEOUT
#define EC200_CMD_AT_CCLK_TIMEOUT 		EC200_AT_CMD_Hardware_TIMEOUT
// ============================= Hardware ===========


//============================== USER Define Variable

extern EC2OO_AT_CMD EC200_USER_Command_AT;
extern EC2OO_AT_CMD EC200_USER_Command_ATE0;
extern EC2OO_AT_CMD EC200_USER_Command_CFUN;
extern EC2OO_AT_CMD EC200_USER_Command_CPIN;
extern EC2OO_AT_CMD EC200_USER_Command_CMEE;
extern EC2OO_AT_CMD EC200_USER_Command_CREG;
extern EC2OO_AT_CMD EC200_USER_Command_CSQ;
extern EC2OO_AT_CMD EC200_USER_Command_CGATT;
extern EC2OO_AT_CMD EC200_USER_Command_CGACT;
extern EC2OO_AT_CMD EC200_USER_Command_HTTPCFG_Contex;
extern EC2OO_AT_CMD EC200_USER_Command_HTTPCFG_responseheader;
extern EC2OO_AT_CMD EC200_USER_Command_QICSGP;
extern EC2OO_AT_CMD EC200_USER_Command_QHTTPURL;
//============================== USER Define Variable

EC200_Database_Struct EC200_Create_DataBase_str(EC200_AT_Command_t User_List,
									EC200_Database_Struct* USER_EC200_Struct_List);

EC2OO_AT_CMD* EC200_Create_DataBase_List(EC200_AT_Command_t* User_List,uint16_t size,
									EC2OO_AT_CMD* USER_EC200_AT_List);
#ifdef __cplusplus
}
#endif
#endif /* INC_USER_LIB_EC200_DB_H_ */
