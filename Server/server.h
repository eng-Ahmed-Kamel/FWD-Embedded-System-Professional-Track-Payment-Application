#define _CRT_SECURE_NO_WARNINGS
#ifndef __SERVER_H			//header file gaurd
#define __SERVER_H
#include <stdio.h>			// library include
#include "terminal.h"		// header include
typedef unsigned int uint32_t;
typedef enum EN_transState_t
{
	APPROVED, DECLINED_INSUFFECIENT_FUND, DECLINED_STOLEN_CARD, INTERNAL_SERVER_ERROR
}EN_transState_t;
typedef enum EN_serverError_t
{
	ok, SAVING_FAILED, TRANSACTION_NOT_FOUND, ACCOUNT_NOT_FOUND, LOW_BALANCE
}EN_serverError_t;
typedef struct ST_accountsDB_t		// structure contain balance and PAN array
{
	float balance;
	uint8_t primaryAccountNumber[20];
}ST_accountsDB_t;
typedef struct ST_transaction_t		// structure contain card data and terminal data and transstate 
{
	ST_cardData_t cardHolderData;
	ST_terminalData_t terminalData;
	EN_transState_t transState;
	uint32_t transactionSequenceNumber;
}ST_transaction_t;
void arrrayintializaion();		// function to call other functions	
EN_transState_t recieveTransactionData(ST_transaction_t* transData);	//prototype of function to recieve TranscationData
EN_serverError_t isValidAccount(ST_cardData_t* cardData);				//prototype of function to check if valid account 
EN_serverError_t isAmountAvailable(ST_terminalData_t* termData);		//prototype of function to check if amount available
EN_serverError_t saveTransaction(ST_transaction_t* transData);			//prototype of function to save transaction		
EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t* transData);	//prototype of function to get transaction	
extern int counter;			//decleration of counter
extern ST_accountsDB_t acceptedAccounts[255];	//decleration of array OF acceptedAccounts
extern ST_transaction_t validTransactionData[255];	//decleration of array of validTransactionData
#endif

