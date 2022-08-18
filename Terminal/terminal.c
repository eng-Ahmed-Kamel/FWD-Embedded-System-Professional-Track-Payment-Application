#define _CRT_SECURE_NO_WARNINGS
#include "terminal.h"			// header include
EN_terminalError_t setMaxAmount(ST_terminalData_t* termData)	//decleration of function that set max amount to 12k
{
	termData->maxTransAmount = 12000.00;
}


EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)	//decleration of function that get TransactionDate
{
	SYSTEMTIME T;
	GetLocalTime(&T);									//built in func to get time
	printf("your transaction date is ");				// print the transaction date  to user 
	printf("%d/%d/%d\n", (T.wDay), (T.wMonth), (T.wYear));		// print the transaction date

	if (T.wDay < 10) {										// check to make sure it got in form dd/mm/yyyy.
		termData->transactionDate[0] = '0';					//casting of data type 
		termData->transactionDate[1] = T.wDay + '0';		//casting of data type 
	}
	else {
		termData->transactionDate[0] = T.wDay / 10 + '0';		//casting of data type 
		termData->transactionDate[1] = T.wDay % 10 + '0';		//casting of data type 
	}
	termData->transactionDate[2] = '/';
	if (T.wMonth < 10) {
		termData->transactionDate[3] = '0';		//casting of data type 
		termData->transactionDate[4] = T.wMonth + '0';		//casting of data type 
	}
	else {
		termData->transactionDate[3] = T.wMonth / 10 + '0';		//casting of data type 
		termData->transactionDate[4] = T.wMonth % 10 + '0';		//casting of data type 
	}
	termData->transactionDate[5] = '/';
	termData->transactionDate[9] = T.wYear % 10 + '0';						//casting of data type 
	termData->transactionDate[8] = (T.wYear % 100) / 10 + '0';				//casting of data type 
	termData->transactionDate[7] = (T.wYear % 1000) / 100 + '0';			//casting of data type 
	termData->transactionDate[6] = T.wYear / 1000 + '0';					//casting of data type 
}





EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData)	//decleration  of function that check card expire Date
{
	if (cardData.cardExpirationDate[3]< termData.transactionDate[8])				//CHECK YEARS FIRST 
	{
		return EXPIRED_CARD;
	}
	else if (cardData.cardExpirationDate[3] > termData.transactionDate[8])			
	{
		return Ok;
	}
	else {
		if (cardData.cardExpirationDate[4] < termData.transactionDate[9])		// check second digit of year
		{
			return EXPIRED_CARD;
		}
		else if (cardData.cardExpirationDate[4] > termData.transactionDate[9])
		{
			return Ok;
		}
		else {
			if (cardData.cardExpirationDate[0] < termData.transactionDate[3])			// check month		
			{
				return EXPIRED_CARD;
			}
			else if (cardData.cardExpirationDate[0] > termData.transactionDate[3])
			{
				return Ok;
			}
			else {
				if (cardData.cardExpirationDate[1] < termData.transactionDate[4])		// check 2nd digit of monthes
				{
					return EXPIRED_CARD;
				}
				else if (cardData.cardExpirationDate[1] >= termData.transactionDate[4])
				{
					return Ok;
				}
			}
		}
	}
}

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData)	//decleration of function that get TransactionAmount
{
	printf("Enter the transaction amount: ");		// telling user what to do	
	scanf("%f", &termData->transAmount);			// getting TransactionAmount from user 

	if (termData->transAmount > 0)		//check if amount more than zero 
	{
		return Ok;
	}
	else
	{
		return INVALID_AMOUNT;
	}
}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)	//decleration of function that check TransactionAmount if below max
{
	if (termData->transAmount <= termData->maxTransAmount)  // checking if below max or not 
	{
		return Ok;
	}
	else
	{
		return EXCEED_MAX_AMOUNT;
	}
}

EN_terminalError_t isValidCardPAN(ST_cardData_t* cardData) //decleration of function that check card PAN
{
	if (cardData->primaryAccountNumber == NULL || strlen(cardData->primaryAccountNumber) < 16 || strlen(cardData->primaryAccountNumber) > 19)
	{
		return WRONG_PAN;
	}
	else
	{
		return Ok;
	}
}