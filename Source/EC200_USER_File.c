/*
 * EC200_USER_File.c
 *
 *  Created on: Dec 3, 2022
 *      Author: mosavi
 */

#include "TEXT_EDITOR_C.h"
#include "EC200_DB.h"

//================== private user function ================
EC2OO_AT_CMD EC200_Command_AT_init_UserConfig  (EC2OO_AT_CMD* obj);
EC2OO_AT_CMD EC200_Command_ATE0_init_UserConfig(EC2OO_AT_CMD* obj);
EC2OO_AT_CMD EC200_Command_CFUN_init_UserConfig(EC2OO_AT_CMD* obj);
EC2OO_AT_CMD EC200_Command_CPIN_init_UserConfig(EC2OO_AT_CMD* obj);
EC2OO_AT_CMD EC200_Command_CMEE_init_UserConfig(EC2OO_AT_CMD* obj);
EC2OO_AT_CMD EC200_Command_CREG_init_UserConfig(EC2OO_AT_CMD* obj);
EC2OO_AT_CMD EC200_Command_CSQ_init_UserConfig (EC2OO_AT_CMD* obj);
EC2OO_AT_CMD EC200_Command_CGATT_init_UserConfig(EC2OO_AT_CMD* obj);
EC2OO_AT_CMD EC200_Command_CGACT_init_UserConfig(EC2OO_AT_CMD* obj);
EC2OO_AT_CMD EC200_Command_Contex_init_UserConfig(EC2OO_AT_CMD* obj);
EC2OO_AT_CMD EC200_Command_Responseheader_init_UserConfig(EC2OO_AT_CMD* obj);
EC2OO_AT_CMD EC200_Command_QICSGP_init_UserConfig(EC2OO_AT_CMD* obj);

uint8_t EC200_Creat_User_Command_List(void);
//================== private user function ================


//================== private user variable ================
EC200_AT_Command_t USER_AT_Command[]=
{
		EC200_AT,
		EC200_ATE0,
		EC200_AT_CFUN,
		EC200_AT_CPIN,
		EC200_AT_CMEE,
};

EC2OO_AT_CMD EC200_USER_Command_AT;
EC2OO_AT_CMD EC200_USER_Command_ATE0;
EC2OO_AT_CMD EC200_USER_Command_CFUN;
EC2OO_AT_CMD EC200_USER_Command_CPIN;
EC2OO_AT_CMD EC200_USER_Command_CMEE;
EC2OO_AT_CMD EC200_USER_Command_CREG;
EC2OO_AT_CMD EC200_USER_Command_CSQ;
EC2OO_AT_CMD EC200_USER_Command_CGATT;
EC2OO_AT_CMD EC200_USER_Command_CGACT;
EC2OO_AT_CMD EC200_USER_Command_HTTPCFG_Contex;
EC2OO_AT_CMD EC200_USER_Command_HTTPCFG_responseheader;
EC2OO_AT_CMD EC200_USER_Command_QICSGP;
EC2OO_AT_CMD EC200_USER_Command_QHTTPURL;

EC2OO_AT_CMD* EC200_USER_Command_List[]=
{
	&EC200_USER_Command_AT,
	&EC200_USER_Command_ATE0,
	&EC200_USER_Command_CFUN,
	&EC200_USER_Command_CPIN,
	&EC200_USER_Command_CMEE,
	&EC200_USER_Command_CREG,
	&EC200_USER_Command_CSQ,
	&EC200_USER_Command_CGATT,
	&EC200_USER_Command_CGACT,
	&EC200_USER_Command_HTTPCFG_Contex,
	&EC200_USER_Command_HTTPCFG_responseheader,
	&EC200_USER_Command_QICSGP,
	&EC200_USER_Command_QHTTPURL,
};
//================== private user variable ================




//======================== USER Define AT ==========================//
//==================================================================//
EC2OO_AT_CMD EC200_Command_AT_init_UserConfig(EC2OO_AT_CMD* obj)
{
	obj->EC200_STD_VALUE.AT_type=EC200_AT;
	obj->EC200_STD_VALUE=EC200_Create_DataBase_str(obj->EC200_STD_VALUE.AT_type,&obj->EC200_STD_VALUE);
	obj->Config=EC200_Command_init_Config(Configurable_type_NO,0,2000,3);
	obj->ID= 	EC200_Command_init_ID("AT", 0);
	OBJ_Buffer_Initialize(&obj->Buffer,EC200_CMD_AT_Size);
	strcpy(obj->Buffer.Buffer,EC200_CMD_AT_Value);
	//OBJ_Buffer_Initialize(&obj->Buffer,obj->EC200_STD_VALUE.Command_Size);
	//EC200_Command_COPY_Buffer(obj);
	return *obj;
}

EC2OO_AT_CMD EC200_Command_ATE0_init_UserConfig(EC2OO_AT_CMD* obj)
{
	obj->EC200_STD_VALUE.AT_type=EC200_ATE0;
	obj->EC200_STD_VALUE=EC200_Create_DataBase_str(obj->EC200_STD_VALUE.AT_type,&obj->EC200_STD_VALUE);
	obj->Config=EC200_Command_init_Config(Configurable_type_NO,0,2000,2);
	obj->ID= 	EC200_Command_init_ID("ATE0", 1);
	OBJ_Buffer_Initialize(&obj->Buffer,obj->EC200_STD_VALUE.Command_Size);
	EC200_Command_COPY_Buffer(obj);
	//OBJ_Buffer_Initialize(&obj->Buffer,EC200_CMD_ATE0_Size);
	//strcpy(obj->Buffer.Buffer,EC200_CMD_ATE0_Value);
	return *obj;
}

EC2OO_AT_CMD EC200_Command_CFUN_init_UserConfig(EC2OO_AT_CMD* obj)
{
	obj->EC200_STD_VALUE.AT_type=EC200_AT_CFUN;
	obj->EC200_STD_VALUE=EC200_Create_DataBase_str(obj->EC200_STD_VALUE.AT_type,&obj->EC200_STD_VALUE);
	obj->Config=EC200_Command_init_Config(Configurable_type_YES,1,1000,2);
	obj->ID= 	EC200_Command_init_ID("CFUN", 2);
	OBJ_Buffer_Initialize(&obj->Buffer,obj->EC200_STD_VALUE.Command_Size);
	EC200_Command_COPY_Buffer(obj);
	//OBJ_Buffer_Initialize(&obj->Buffer,EC200_CMD_AT_CFUN_Size);
	//strcpy(obj->Buffer.Buffer,EC200_CMD_AT_CFUN_Value);
	obj->Buffer.Buffer=TEXT_EDITOR_Replace_Text_C(obj->Buffer.Buffer, TEXT_EDITORE_SUBSTR_xx1, "?");
	return *obj;
}

EC2OO_AT_CMD EC200_Command_CPIN_init_UserConfig(EC2OO_AT_CMD* obj)
{
	obj->EC200_STD_VALUE.AT_type=EC200_AT_CPIN;
	obj->EC200_STD_VALUE=EC200_Create_DataBase_str(obj->EC200_STD_VALUE.AT_type,&obj->EC200_STD_VALUE);
	obj->Config=EC200_Command_init_Config(Configurable_type_YES,1,1000,2);
	obj->ID= 	EC200_Command_init_ID("CPIN", 3);
	OBJ_Buffer_Initialize(&obj->Buffer,obj->EC200_STD_VALUE.Command_Size);
	EC200_Command_COPY_Buffer(obj);
	//OBJ_Buffer_Initialize(&obj->Buffer,EC200_CMD_AT_CPIN_Size);
	//strcpy(obj->Buffer.Buffer,EC200_CMD_AT_CPIN_Value);
	obj->Buffer.Buffer=TEXT_EDITOR_Replace_Text_C(obj->Buffer.Buffer, TEXT_EDITORE_SUBSTR_xx1, "?");
	return *obj;
}

EC2OO_AT_CMD EC200_Command_CMEE_init_UserConfig(EC2OO_AT_CMD* obj)
{
	obj->EC200_STD_VALUE.AT_type=EC200_AT_CMEE;
	obj->EC200_STD_VALUE=EC200_Create_DataBase_str(obj->EC200_STD_VALUE.AT_type,&obj->EC200_STD_VALUE);
	obj->Config=EC200_Command_init_Config(Configurable_type_YES,1,1000,2);
	obj->ID= 	EC200_Command_init_ID("CMEE", 4);
	OBJ_Buffer_Initialize(&obj->Buffer,obj->EC200_STD_VALUE.Command_Size);
	EC200_Command_COPY_Buffer(obj);
	obj->Buffer.Buffer=TEXT_EDITOR_Replace_Text_C(obj->Buffer.Buffer, TEXT_EDITORE_SUBSTR_xx1, "2");
	return *obj;
}

EC2OO_AT_CMD EC200_Command_CREG_init_UserConfig(EC2OO_AT_CMD* obj)
{
	obj->EC200_STD_VALUE.AT_type=EC200_AT_CREG;
	obj->EC200_STD_VALUE=EC200_Create_DataBase_str(obj->EC200_STD_VALUE.AT_type,&obj->EC200_STD_VALUE);
	obj->Config=EC200_Command_init_Config(Configurable_type_YES,1,1000,2);
	obj->ID= 	EC200_Command_init_ID("CREG", 5);
	OBJ_Buffer_Initialize(&obj->Buffer,obj->EC200_STD_VALUE.Command_Size);
	EC200_Command_COPY_Buffer(obj);
	obj->Buffer.Buffer=TEXT_EDITOR_Replace_Text_C(obj->Buffer.Buffer, TEXT_EDITORE_SUBSTR_xx1, "1");
	return *obj;
}

EC2OO_AT_CMD EC200_Command_CSQ_init_UserConfig(EC2OO_AT_CMD* obj)
{
	obj->EC200_STD_VALUE.AT_type=EC200_AT_CSQ;
	obj->EC200_STD_VALUE=EC200_Create_DataBase_str(obj->EC200_STD_VALUE.AT_type,&obj->EC200_STD_VALUE);
	obj->Config=EC200_Command_init_Config(Configurable_type_NO,0,1000,2);
	obj->ID= 	EC200_Command_init_ID("CSQ", 6);
	OBJ_Buffer_Initialize(&obj->Buffer,obj->EC200_STD_VALUE.Command_Size);
	EC200_Command_COPY_Buffer(obj);
	return *obj;
}

EC2OO_AT_CMD EC200_Command_CGATT_init_UserConfig(EC2OO_AT_CMD* obj)
{
	obj->EC200_STD_VALUE.AT_type=EC200_AT_CGATT;
	obj->EC200_STD_VALUE=EC200_Create_DataBase_str(obj->EC200_STD_VALUE.AT_type,&obj->EC200_STD_VALUE);
	obj->Config=EC200_Command_init_Config(Configurable_type_YES,1,1000,2);
	obj->ID= 	EC200_Command_init_ID("CGATT", 7);
	OBJ_Buffer_Initialize(&obj->Buffer,obj->EC200_STD_VALUE.Command_Size);
	EC200_Command_COPY_Buffer(obj);
	obj->Buffer.Buffer=TEXT_EDITOR_Replace_Text_C(obj->Buffer.Buffer, TEXT_EDITORE_SUBSTR_xx1, "1");
	return *obj;
}

EC2OO_AT_CMD EC200_Command_CGACT_init_UserConfig(EC2OO_AT_CMD* obj)
{
	obj->EC200_STD_VALUE.AT_type=EC200_AT_CGACT;
	obj->EC200_STD_VALUE=EC200_Create_DataBase_str(obj->EC200_STD_VALUE.AT_type,&obj->EC200_STD_VALUE);
	obj->Config=EC200_Command_init_Config(Configurable_type_YES,1,1000,2);
	obj->ID= 	EC200_Command_init_ID("CGACT", 7);
	OBJ_Buffer_Initialize(&obj->Buffer,obj->EC200_STD_VALUE.Command_Size);
	EC200_Command_COPY_Buffer(obj);
	obj->Buffer.Buffer=TEXT_EDITOR_Replace_Text_C(obj->Buffer.Buffer, TEXT_EDITORE_SUBSTR_xx1, "1");
	TEXT_EDITOR_Remove_Text_C(obj->Buffer.Buffer,",xx2");
	return *obj;
}

EC2OO_AT_CMD EC200_Command_Contex_init_UserConfig(EC2OO_AT_CMD* obj)
{
	obj->EC200_STD_VALUE.AT_type=EC200_AT_QHTTPCFG;
	obj->EC200_STD_VALUE=EC200_Create_DataBase_str(obj->EC200_STD_VALUE.AT_type,&obj->EC200_STD_VALUE);
	obj->Config=EC200_Command_init_Config(Configurable_type_YES,2,1000,2);
	obj->ID= 	EC200_Command_init_ID("CONTEX", 8);
	OBJ_Buffer_Initialize(&obj->Buffer,obj->EC200_STD_VALUE.Command_Size);
	EC200_Command_COPY_Buffer(obj);
	//TEXT_EDITOR_Replace_Text_C(obj->Buffer.Buffer, TEXT_EDITORE_SUBSTR_xx1,"contextid");
	obj->Buffer.Buffer=TEXT_EDITOR_PLACE_Txt_between_Character_C(obj->Buffer.Buffer, TEXT_EDITORE_SUBSTR_xx1,"contextid",TEXT_EDITORE_Double_Quate_char);
	obj->Buffer.Buffer=TEXT_EDITOR_Replace_Text_C(obj->Buffer.Buffer, ",xx2", ",1");
	return *obj;
}

EC2OO_AT_CMD EC200_Command_Responseheader_init_UserConfig(EC2OO_AT_CMD* obj)
{
	obj->EC200_STD_VALUE.AT_type=EC200_AT_QHTTPCFG;
	obj->EC200_STD_VALUE=EC200_Create_DataBase_str(obj->EC200_STD_VALUE.AT_type,&obj->EC200_STD_VALUE);
	obj->Config=EC200_Command_init_Config(Configurable_type_YES,2,1000,2);
	obj->ID= 	EC200_Command_init_ID("RES_HE", 9);
	OBJ_Buffer_Initialize(&obj->Buffer,obj->EC200_STD_VALUE.Command_Size);
	EC200_Command_COPY_Buffer(obj);
	//TEXT_EDITOR_Replace_Text_C(obj->Buffer.Buffer, TEXT_EDITORE_SUBSTR_xx1,"contextid");
	obj->Buffer.Buffer=TEXT_EDITOR_PLACE_Txt_between_Character_C(obj->Buffer.Buffer, TEXT_EDITORE_SUBSTR_xx1,"responseheader",TEXT_EDITORE_Double_Quate_char);
	obj->Buffer.Buffer=TEXT_EDITOR_Replace_Text_C(obj->Buffer.Buffer, ",xx2", ",1");
	return *obj;
}

EC2OO_AT_CMD EC200_Command_QICSGP_init_UserConfig(EC2OO_AT_CMD* obj)
{
	obj->EC200_STD_VALUE.AT_type=EC200_AT_QICSGP;
	obj->EC200_STD_VALUE=EC200_Create_DataBase_str(obj->EC200_STD_VALUE.AT_type,&obj->EC200_STD_VALUE);
	obj->Config=EC200_Command_init_Config(Configurable_type_YES,2,1000,2);
	obj->ID= 	EC200_Command_init_ID("QICSGP", 10);
	OBJ_Buffer_Initialize(&obj->Buffer,obj->EC200_STD_VALUE.Command_Size);
	EC200_Command_COPY_Buffer(obj);
	obj->Buffer.Buffer=TEXT_EDITOR_Replace_Text_C(obj->Buffer.Buffer, TEXT_EDITORE_SUBSTR_xx1,"1");
	obj->Buffer.Buffer=TEXT_EDITOR_Replace_Text_C(obj->Buffer.Buffer, TEXT_EDITORE_SUBSTR_xx2,"1");
	obj->Buffer.Buffer=TEXT_EDITOR_PLACE_Txt_between_Character_C(obj->Buffer.Buffer, TEXT_EDITORE_SUBSTR_xx3,EC200_Default_APN_NAME,TEXT_EDITORE_Double_Quate_char);
	obj->Buffer.Buffer=TEXT_EDITOR_PLACE_Txt_between_Character_C(obj->Buffer.Buffer, TEXT_EDITORE_SUBSTR_xx4,"",TEXT_EDITORE_Double_Quate_char);
	obj->Buffer.Buffer=TEXT_EDITOR_PLACE_Txt_between_Character_C(obj->Buffer.Buffer, TEXT_EDITORE_SUBSTR_xx5,"",TEXT_EDITORE_Double_Quate_char);
	obj->Buffer.Buffer=TEXT_EDITOR_Replace_Text_C(obj->Buffer.Buffer, TEXT_EDITORE_SUBSTR_xx6,"1");
	//obj->Buffer.Buffer=TEXT_EDITOR_Replace_Text_C(obj->Buffer.Buffer, ",xx2", ",1");
	return *obj;
}

EC2OO_AT_CMD EC200_Command_QHTTPURL_init_UserConfig(EC2OO_AT_CMD* obj)
{
	obj->EC200_STD_VALUE.AT_type=EC200_AT_QHTTPURL;
	obj->EC200_STD_VALUE=EC200_Create_DataBase_str(obj->EC200_STD_VALUE.AT_type,&obj->EC200_STD_VALUE);
	obj->Config=EC200_Command_init_Config(Configurable_type_YES,2,1000,2);
	obj->ID= 	EC200_Command_init_ID("HTTP_URL", 11);
	OBJ_Buffer_Initialize(&obj->Buffer,obj->EC200_STD_VALUE.Command_Size);
	EC200_Command_COPY_Buffer(obj);
	TEXT_EDITOR_Replace_Text_C(obj->Buffer.Buffer, TEXT_EDITORE_SUBSTR_xx1,"contextid");
	//obj->Buffer.Buffer=TEXT_EDITOR_PLACE_Txt_between_Character_C(obj->Buffer.Buffer, TEXT_EDITORE_SUBSTR_xx1,"responseheader",TEXT_EDITORE_Double_Quate_char);
	obj->Buffer.Buffer=TEXT_EDITOR_Replace_Text_C(obj->Buffer.Buffer, ",xx2", ",80");
	return *obj;
}


uint8_t EC200_Creat_User_Command_List(void)
{
	uint8_t i=0;
	EC200_Command_AT_init_UserConfig(&EC200_USER_Command_AT);
	i++;
	EC200_Command_ATE0_init_UserConfig(&EC200_USER_Command_ATE0);
	i++;
	EC200_Command_CFUN_init_UserConfig(&EC200_USER_Command_CFUN);
	i++;
	EC200_Command_CPIN_init_UserConfig(&EC200_USER_Command_CPIN);
	i++;
	EC200_Command_CMEE_init_UserConfig(&EC200_USER_Command_CMEE);
	i++;
	EC200_Command_CREG_init_UserConfig(&EC200_USER_Command_CREG);
	i++;
	EC200_Command_CSQ_init_UserConfig (&EC200_USER_Command_CSQ);
	i++;
	EC200_Command_CGATT_init_UserConfig(&EC200_USER_Command_CGATT);
	i++;
	EC200_Command_CGACT_init_UserConfig(&EC200_USER_Command_CGACT);
	i++;
	EC200_Command_Contex_init_UserConfig(&EC200_USER_Command_HTTPCFG_Contex);
	i++;
	EC200_Command_Responseheader_init_UserConfig(&EC200_USER_Command_HTTPCFG_responseheader);
	i++;
	EC200_Command_QICSGP_init_UserConfig(&EC200_USER_Command_QICSGP);
	i++;
	return i;
}
//======================== USER Define AT ==========================//
//==================================================================//






