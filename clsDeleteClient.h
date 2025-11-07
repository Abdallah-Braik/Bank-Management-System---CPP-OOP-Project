#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include"clsUser.h"
using namespace std;


class clsDeleteClient : private clsScreen
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
		cout << "\nAcount Balance : " << Client.AcountBalance();
		cout << "\n-------------------------------\n";
	}

public:
	static void DeleteClient()
	{
		if (!CheckAccessScreen(clsUser::enPermission::DeleteClient))
			return;

		_PrintHeader("Delete Client");
		string s1;
		cout << "Enter the Acount number you want to delete : \n";
		getline(cin >> ws, s1);

		while (!clsBankClient::IsClientExist(s1))
		{
			cout << "Acount Number was not found, Enter a valid one : \n";
			getline(cin >> ws, s1);
		}
		clsBankClient Client1 = Client1.Find(s1);
		_Print(Client1);
		cout << "\nAre you sure you want to delete this client ? (Y/N)\n";
		char answer = 'n';
		cin >> answer;

		if (answer == 'y' || answer == 'Y')
		{
			if (Client1.Delete())
			{
				cout << "Client was deleted successfully.\n";
				_Print(Client1);
			}
			else
				cout << "Error, Client wasn't deleted.\n";

		}





	};

};