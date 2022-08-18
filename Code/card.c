#include "card.h"         // header include
EN_cardError_t getCardHolderName(ST_cardData_t* cardData)	// function decleration to get name and check name's length 
{
	printf("Enter the card holder name: ");			//to tell user to enter his name 
	gets(cardData->cardHolderName);							// getting string from user 
	if (strlen(cardData->cardHolderName) < 20 || strlen(cardData->cardHolderName) > 24)		// if to check length of name  
	{
		return WRONG_NAME;
	}
	else
	{
		return OK;
	}
}

EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)	 // function decleration to get date and check it
{
	printf("Enter the card expiry date in the format MM / YY: ");		//to tell user to enter his card expiry date
	gets(cardData->cardExpirationDate);											//getting card expiry date from user by string func gets 
	if (strlen(cardData->cardExpirationDate) == 5 && cardData->cardExpirationDate[0] < '2' && cardData->cardExpirationDate[0] >= '0' && cardData->cardExpirationDate[2] == '/')	// valid checking 
	{
		if (cardData->cardExpirationDate[0] == '1')			// check case of october ,november and december
		{
			if (cardData->cardExpirationDate[1]<'0'|| cardData->cardExpirationDate[1] > '2')
			{
				return WRONG_EXP_DATE;
			}
			else {
				return OK;


			}
		}
		else if (cardData->cardExpirationDate[0] == '0')	// check case of entering month by 0 value 
		{
			if (cardData->cardExpirationDate[1] > '0'&& cardData->cardExpirationDate[1] <= '9')
				return OK;

			else
				return WRONG_EXP_DATE;
		}
	}
	else	// checking 
	{
		return WRONG_EXP_DATE;
	}
}

EN_cardError_t getCardPAN(ST_cardData_t* cardData)		// function decleration to get PAN and check it
{
	printf("Enter the card PAN:");				//to tell user to enter his card PAN
	gets(cardData->primaryAccountNumber);				//getting card PAN
	if (strlen(cardData->primaryAccountNumber) >= 16 && strlen(cardData->primaryAccountNumber) <= 19) // check conditions of PAN
	{
		return OK;
	}
	else
	{
		return WRONG_PAN;
	}
}