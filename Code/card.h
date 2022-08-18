#define _CRT_SECURE_NO_WARNINGS
#ifndef __CARD_H		//header file gaurd
#define __CARD_H
#include <stdio.h>		//library include
#include <string.h>		// string library include

typedef enum EN_cardError_t
{
	OK, WRONG_NAME, WRONG_EXP_DATE, WRONG_PAN
}EN_cardError_t;
typedef unsigned char uint8_t;
typedef struct ST_cardData_t		//strucutre of data of card 
{
	uint8_t cardHolderName[25];		// array of 25 character of name 
	uint8_t primaryAccountNumber[20];		// array of 20 character of PAN 
	uint8_t cardExpirationDate[6];			// array of 6 character of expiration date 
}ST_cardData_t;
EN_cardError_t getCardHolderName(ST_cardData_t* cardData);		//prototype of function that get name 
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData);      //prototype of function that get expiry date 
EN_cardError_t getCardPAN(ST_cardData_t* cardData);				//prototype of function that get card PAN 
#endif
