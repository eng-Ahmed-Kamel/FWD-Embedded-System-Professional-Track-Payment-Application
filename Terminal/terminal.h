#define _CRT_SECURE_NO_WARNINGS
#ifndef __TERMINAL_H		//header file gaurd
#define __TERMINAL_H
#include "card.h"			//including header file		
#include <stdio.h>			//library include
#include <string.h>			// string library include
#include <time.h>           // time library include
#include <windows.h>		// windows library include
typedef struct ST_terminalData_t
{
	float transAmount;			// decleration of transfer amount
	float maxTransAmount;		// decleration of transfer Max amount
	uint8_t transactionDate[11];	// decleration of transfer date array
}ST_terminalData_t;

typedef enum EN_terminalError_t
{
	Ok, WRONG_DATE, EXPIRED_CARD, INVALID_CARD, INVALID_AMOUNT, EXCEED_MAX_AMOUNT, INVALID_MAX_AMOUNT
}EN_terminalError_t;



EN_terminalError_t getTransactionDate(ST_terminalData_t* termData);		//prototype of function that get TransactionDate
EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData);	//prototype of function that check card expire Date
EN_terminalError_t isValidCardPAN(ST_cardData_t* cardData);		//prototype of function that check card PAN
EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData);		//prototype of function that get TransactionAmount if available
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData);			//prototype of function that check TransactionAmount if below max 
EN_terminalError_t setMaxAmount(ST_terminalData_t* termData);			//prototype of function that set max amount 


#endif
