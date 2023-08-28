/*
 * TEXT_EDITORE_C.c
 *
 *  Created on: Nov 26, 2022
 *      Author: mosavi
 */

#include "TEXT_EDITOR_C.h"

uint16_t TEXT_EDITOR_Find_Text_C(char* Source, char* txt)
{
	uint16_t i=0;
	for(i=0;i<strlen(Source)-strlen(txt);i++)
	{
		if(memcmp(&Source[i],txt,strlen(txt))==0) // it's equal
		{
			return i;
		}
	}
	return 0;
}

char* TEXT_EDITOR_Replace_Text_C(char* Source, char* txt1,char* txt2 )
{
	const uint8_t  len_txt1=(uint8_t)strlen(txt1);
	const uint8_t  len_txt2=(uint8_t)strlen(txt2);
	const uint16_t len_Source=strlen(Source);
	const uint16_t new_len_source=len_Source-len_txt1+len_txt2;
	uint16_t index=TEXT_EDITOR_Find_Text_C(Source, txt1);
	if(index)
	{
		char *p = (char*)malloc(sizeof(char)*strlen(Source));
		memset(p,0,new_len_source);
		strcpy(p,Source);
		//free(Source);
		//Source=(char*)malloc(sizeof(char)*new_len_source);
		Source=(char*)realloc(Source,new_len_source);
		memset(Source,0,new_len_source);
		memcpy(Source,p,index);
		memcpy(&Source[index],txt2,len_txt2);
		memcpy(&Source[index+len_txt2],&p[index+len_txt1],len_Source-index+len_txt1);
		free(p);

	}
	return Source;
}

bool TEXT_EDITOR_Remove_Text_C(char* Source, char* txt1)
{
	const uint8_t  len_txt1=(uint8_t)strlen(txt1);
	const uint16_t len_Source=strlen(Source);
	const uint16_t new_len_source=len_Source-len_txt1+1;
	uint16_t index=TEXT_EDITOR_Find_Text_C(Source, txt1);
	if(index)
	{
		char *p = (char*)malloc(sizeof(char)*strlen(Source));
		memset(p,0,new_len_source);
		strcpy(p,Source);
		Source=(char*)realloc(Source,new_len_source);
		memset(Source,0,new_len_source);
		memcpy(Source,p,index);
		memcpy(&Source[index],&p[index+len_txt1],len_Source-index+len_txt1);
		free(p);
		return true;
	}
	else
		return false;
}

char* TEXT_EDITOR_PLACE_Txt_between_Character_C(char* Source,char* txt1, char* txt2 ,char CHAR)
{
	const uint8_t  len_txt1=(uint8_t)strlen(txt1);
	const uint8_t  len_txt2=(uint8_t)strlen(txt2);
	const uint16_t len_Source=strlen(Source);
	const uint16_t new_len_source=len_Source-len_txt1+len_txt2+4;
	uint16_t index=TEXT_EDITOR_Find_Text_C(Source, txt1);
	uint16_t Pointer=0;
	uint8_t Spacial_char;
	bool IS_Special_Char=false;
	switch(CHAR)
	{
		case(TEXT_EDITORE_Double_Quate_char):
			{
				IS_Special_Char=true;
				Spacial_char= TEXT_EDITORE_Double_Quate_char;
				break;
			}
		case(TEXT_EDITORE_SINGLE_Quate_char):
			{
				IS_Special_Char=true;
				Spacial_char= TEXT_EDITORE_SINGLE_Quate_char;
				break;
			}
		default:
			{
				Spacial_char=CHAR;
				break;
			}
	}

	if(index)
	{
		char *p = (char*)malloc(sizeof(char)*len_Source);
		memset(p,0,new_len_source);
		strcpy(p,Source);
		Source=(char*)realloc(Source,new_len_source);
		memset(Source,0,new_len_source);
		memcpy(Source,p,index);
		Pointer=index;

		if(IS_Special_Char)
		{
		Source[Pointer]='\\';
		Pointer++;
		}
		Source[Pointer]=Spacial_char;
		Pointer++;

		memcpy(&Source[Pointer],txt2,len_txt2);
		Pointer+=len_txt2;

		if(IS_Special_Char)
		{
		Source[Pointer]='\\';
		Pointer++;
		}
		Source[Pointer]=Spacial_char;
		Pointer++;

		memcpy(&Source[Pointer],&p[index+len_txt1],len_Source-index+len_txt1);
		free(p);
	}
	return Source;
}

uint8_t TEXT_EDITOR_Return_Digit_Number(uint16_t Number)
{
	uint8_t counter=1;
	if(Number>=65535 || Number==0) return 0;
	for(uint16_t i=10;i<Number;i*=10)
		counter++;
	return counter;
}
