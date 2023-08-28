/*
 * TEXT_EDITOR_C.h
 *
 *  Created on: Nov 26, 2022
 *      Author: mosavi
 */

#ifndef USER_FILE_TEXT_EDITOR_C_H_
#define USER_FILE_TEXT_EDITOR_C_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "Default_C.h"

#define TEXT_EDITORE_SUBSTR_xx1			"xx1"
#define TEXT_EDITORE_SUBSTR_xx2			"xx2"
#define TEXT_EDITORE_SUBSTR_xx3			"xx3"
#define TEXT_EDITORE_SUBSTR_xx4			"xx4"
#define TEXT_EDITORE_SUBSTR_xx5			"xx5"
#define TEXT_EDITORE_SUBSTR_xx6			"xx6"
#define TEXT_EDITORE_SUBSTR_xx7			"xx7"
#define TEXT_EDITORE_SUBSTR_xx8			"xx8"

#define TEXT_EDITORE_Double_Quate_char	0x22	// "
#define TEXT_EDITORE_SINGLE_Quate_char	0x27	// '

char* TEXT_EDITOR_Replace_Text_C(char* Source, char* txt1,char* txt2 );
bool TEXT_EDITOR_Remove_Text_C	(char* Source, char* txt1);
uint16_t TEXT_EDITOR_Find_Text_C(char* Source, char* txt);
char* TEXT_EDITOR_PLACE_Txt_between_Character_C(char* Source,char* txt1, char* txt2 ,char CHAR);


uint8_t TEXT_EDITOR_Return_Digit_Number(uint16_t Number);


#ifdef __cplusplus
}
#endif

#endif /* USER_FILE_TEXT_EDITOR_C_H_ */
