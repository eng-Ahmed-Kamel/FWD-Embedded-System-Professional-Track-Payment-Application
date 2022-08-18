#define _CRT_SECURE_NO_WARNINGS
#include "server.h"			// header include
ST_accountsDB_t acceptedAccounts[255] = {     // valid accounts data base 
	{2500.0,"4716705718621221"},
	{12000.0, "4539195459515490"}, 
	{12100.0, "4556551087632206"}, 
	{27000.0, "4539039447062076"}, 
	{100000.0, "4485672138028420"}, 
	{55.67, "4539262665180905"},
	{100.00, "4215643562317248"},
	{5000.78, "4104806768580521"}, 
	{7000.44, "4381738481955967"}, 
	{10.12, "4929647978576211"},
	{2.01, "4539880988079262"},
	{740.45, "4485214059145824"},
	{5246.00, "4929406559471734"}
};
ST_transaction_t validTransactionData[255];
int counter;		// decleration of counter 

EN_transState_t recieveTransactionData(ST_transaction_t* transData)		//decleration of function to recieve TranscationData
{
	getCardHolderName(&transData->cardHolderData);				// getting card data 
	getCardExpiryDate(&transData->cardHolderData);
	getCardPAN(&transData->cardHolderData);
	getTransactionAmount(&transData->terminalData);				//getting terminal data 
	getTransactionDate(&transData->terminalData);
	if ((getCardHolderName(&transData->cardHolderData)
		&& getCardExpiryDate(&transData->cardHolderData) 
		&& getCardPAN(&transData->cardHolderData)
		&& getTransactionAmount(&transData->terminalData)
		&& getTransactionDate(&transData->terminalData)) == OK)
	{
		for (int x = 0; x < 255; x++)			// checking PAN by PAN in data base and if their are SUFFECIENT_FUND or not
		{
			if (strcmp(transData->cardHolderData.primaryAccountNumber, acceptedAccounts[x].primaryAccountNumber) != 0 )
			{
				if (x == (254))
					return DECLINED_STOLEN_CARD;
			}
			else if (transData->terminalData.transAmount > acceptedAccounts[x].balance)
			{
				if (x == (254))
					return DECLINED_INSUFFECIENT_FUND;
			}
			else
				return APPROVED;

		}
	}
}

EN_serverError_t isAmountAvailable(ST_terminalData_t* termData)			//func to check if AmountAvailable
{
	if ((termData->transAmount) <= acceptedAccounts[counter].balance)
		return ok;
	else
		return LOW_BALANCE;
}
EN_serverError_t saveTransaction(ST_transaction_t* transData) // fun to make transaction data base 
{
	static int count_m;		// counter declare initail value =0
	strcpy(validTransactionData[count_m].cardHolderData.cardHolderName, transData->cardHolderData.cardHolderName);
	strcpy(validTransactionData[count_m].cardHolderData.cardExpirationDate, transData->cardHolderData.cardExpirationDate);
	strcpy(validTransactionData[count_m].cardHolderData.primaryAccountNumber, transData->cardHolderData.primaryAccountNumber);
	validTransactionData[count_m].terminalData.transAmount = transData->terminalData.transAmount;
	strcpy(validTransactionData[count_m].terminalData.transactionDate, transData->terminalData.transactionDate);
	validTransactionData[count_m].transState = transData->transState;
	validTransactionData[count_m].transactionSequenceNumber = count_m + 1;
	count_m++;
	return ok;
}

EN_serverError_t isValidAccount(ST_cardData_t* cardData)		// checking PAN by PAN in data base 
{
	for (counter = 0; counter < 255; ++counter)
	{
		if (strcmp(acceptedAccounts[counter].primaryAccountNumber, cardData->primaryAccountNumber) == 0)
		{
			return APPROVED;
		}



	}
	return DECLINED_STOLEN_CARD;
}
EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t* transData)  // feeding data base 
{
	int i;
	for (i = 0; i < 255; i++)
	{
		if (transactionSequenceNumber == validTransactionData[i].transactionSequenceNumber)
		{

			return ok;
		}
		return TRANSACTION_NOT_FOUND;
	}
}
void arrrayintializaion()
{
	for (int i = 0; i < 255; i++)
	{
		validTransactionData[i].terminalData.transAmount = 0;
		validTransactionData[i].transState = 0;
		validTransactionData[i].transactionSequenceNumber = 0;
	}
}

