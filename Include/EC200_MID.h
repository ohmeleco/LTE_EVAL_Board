/*
 * EC200_MID.h
 *
 *  Created on: Dec 3, 2022
 *      Author: mosavi
 */

#ifndef USER_FILE_EC200_MID_H_
#define USER_FILE_EC200_MID_H_


#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include	"Default_C.h"
#include	"EC200.h"
#include	"EC200_DB.h"
#include 	"NETWORK_C.h"
/* Private defines -----------------------------------------------------------*/

/* Private Variable -----------------------------------------------------------*/
extern EC200_AT_Command_t USER_AT_Command[];


/* Private Function -----------------------------------------------------------*/
uint8_t EC200_Creat_User_Command_List(void);

#ifdef __cplusplus
}
#endif





#endif /* USER_FILE_EC200_MID_H_ */
