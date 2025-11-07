#pragma once
#include<iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
using namespace std;

class clsFindClient: protected clsScreen
{
private :
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
		cout << "\nAcount Balance : " << Client.AcountBalance();
		cout << "\n-------------------------------\n";
	}

public :
	 
	static void FindClient()
	{
		if (!CheckAccessScreen(clsUser::enPermission::FindClient))
			return;
		_PrintHeader("Find Client");
		string AcountNumber= "";
		cout << "Enter the Acount Number : ";
		getline(cin>>ws, AcountNumber);
		while (!clsBankClient::IsClientExist(AcountNumber))
		{
			cout << "Acount Number doesn't exist, enter a valid one : ";
			getline(cin, AcountNumber);
		}

		clsBankClient Client1 = clsBankClient::Find(AcountNumber);

		if (Client1.IsEmpty())
		{
			cout << "Client Acount is Empty.\n";
		}
		else
		{
			_Print(Client1);
		}
	}

};

