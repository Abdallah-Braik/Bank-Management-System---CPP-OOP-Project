#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsTransfer:protected clsScreen
{
private:
	static void _Print(clsBankClient Client)
	{
		cout << "\nClient card\n";
		cout << "\n-------------------------------\n";
		cout << "\nFull Name      :" << Client.FullName();
		cout << "\nAcount Number  : " << Client.AcountNumber();
		cout << "\nAcount Balance : " << Client.AcountBalance();
		cout << "\n-------------------------------\n";
	}

	static clsBankClient _ReadAccount( string Msg = "\nAcount Number doesn't Exist, Enter another one : ")
	{
		
		string AccountNumber = "";
		cin >> AccountNumber;
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << Msg;
			cin >> AccountNumber;
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_Print(Client);
		return Client;
	}


public :
	static void ShowTransferScreen()
	{
		_PrintHeader("Transfer");

		cout << "\n\nEnter the account number you want to transfer from : ";
		clsBankClient Source = _ReadAccount();

		cout << "\n\nEner the account number you want to transfer to : ";
		clsBankClient Destination = _ReadAccount();

		if (Source.AcountNumber() == Destination.AcountNumber())
		{
			cout << "\n\nYou can't transfer money to the same account.\n";
			return;
		}


    double Amount;
		do{
			cout << "\n\nEnter the amount you want to transfer : ";
			cin >> Amount;
		} while (Amount <= 0);


		char Answer='N';
		cout << "\nAre you sure you want to perform this transaction ? (Y/N) : ";
		cin >> Answer;

		if(Answer=='y'||Answer=='Y')
		{ 

			if (Source.Transfer(Amount, Destination))
			{
				system("cls");
				cout << "\n\nTransfer was done successfully.\n\n";
				Source.SaveTransferInfo(Destination, Amount);
			}

			else
				cout << "Error.\n\n";
        }
		_Print(Source);
		_Print(Destination);
		
	}







};

