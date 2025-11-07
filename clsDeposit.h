#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"


using namespace std;

class clsDeopsit:protected clsScreen
{
private:
	static void _Print(clsBankClient Client)
	{
		cout << "\nClient card\n";
		cout << "\n-------------------------------\n";
		cout << "First Name      : " << Client.FirstName();
		cout << "\nLast Name      : " << Client.LastName();
		cout << "\nFull Name      :" << Client.FullName();
		cout << "\nEmail          : " << Client.Email();
		cout << "\nPhone Number   : " << Client.Phone();
		cout << "\nAcount Number  : " << Client.AcountNumber();
		cout << "\nPIN CODE       : " << Client.PinCode();
		cout << "\nAcount Balance : " << fixed << setprecision(2) << Client.AcountBalance() << endl;
		cout << "\n-------------------------------\n";
	}



public :

	static void DepositScreen()
	{
		_PrintHeader("Deposit");
		string AcountNumber;
		cout << "\nEnter your Acount Number : ";
		getline(cin >> ws, AcountNumber);
		
		while (!clsBankClient::IsClientExist(AcountNumber))
		{
			cout << "\nAcount Number doesn't exist,Enter another one : ";
			getline(cin >> ws, AcountNumber);
		}


		clsBankClient Client1 = clsBankClient::Find(AcountNumber);

		_Print(Client1);

		double Amount = 0;
		string Answer = "N";

		cout << "Enter the deposit amount : ";
		cin >> Amount;
		cout << "\nAre you sure you want to perform this transaction ? (Y/N)  ";
		getline(cin >> ws, Answer);

		if (Answer == "Y" || Answer == "y")
		{
			Client1.Deposit(Amount);
			cout << "Transaction was done successfully .\n";
			cout << "Your Balance is : ";
			cout << fixed << setprecision(2) << Client1.AcountBalance() << endl;
		}

		else
			cout << "Transaction was canceled.";

	}

};

