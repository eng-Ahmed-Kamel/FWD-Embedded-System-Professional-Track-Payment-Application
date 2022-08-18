#define _CRT_SECURE_NO_WARNINGS
#include "app.h"		// header include
#include "server.h"		// header include


void appStart(void)  //decleration of function  and calling other func
{
		arrrayintializaion();
		ST_cardData_t cardData;
		ST_terminalData_t termData;
		ST_transaction_t transData;
		setMaxAmount(&termData);
		if (getCardHolderName(&cardData) == WRONG_NAME)
		{
			printf("incorrect name\n");
			return 0;
		}
		if (getCardExpiryDate(&cardData) == WRONG_EXP_DATE)
		{
			printf("incorrect date\n");
			return 0;
		}
		if (getCardPAN(&cardData) == WRONG_PAN)
		{
			printf("incorrect PAN\n");
			return 0;
		}

		getTransactionDate(&termData);

		if (isCardExpired(cardData, termData) == EXPIRED_CARD)
		{
			printf("Expired Card\n");
			return 0;
		}

		if (getTransactionAmount(&termData) == INVALID_AMOUNT)
		{
			printf("Insufficent Amount\n");
			return 0;
		}
		if (isBelowMaxAmount(&termData) == EXCEED_MAX_AMOUNT)
		{
			printf("Exceeded Maximum Amount\n ");
			return 0;
		}
		if (isValidAccount(&cardData) == DECLINED_STOLEN_CARD)
		{
			printf("Invalid Account\n");
			return 0;
		}
		else if (isValidAccount(&cardData) == APPROVED)
		{
			if (isAmountAvailable(&termData) == LOW_BALANCE)
			{
				printf("Not enough Money Available\n");
				return 0;
			}
		}

		acceptedAccounts[counter].balance = acceptedAccounts[counter].balance - termData.transAmount;	//update balance database 
		saveTransaction(&transData);
		printf("Successful Transaction\n");
		printf("Your new balance is: %f\n", acceptedAccounts[counter].balance);

}