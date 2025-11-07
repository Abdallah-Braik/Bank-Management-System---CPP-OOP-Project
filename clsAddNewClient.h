#pragma once
#include <iostream>
#include"clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUser.h"
using namespace std;

class clsAddNewClient : private clsScreen
{
private : 
	static void _ReadClient(clsBankClient& Client)
	{
		cout << "Enter First Name : \n";
		Client.SetFirstName(clsInputValidate::ReadString());
		cout << "\nEnter Last Name : \n";
		Client.SetLastName(clsInputValidate::ReadString());
		cout << "\nEnter Email : \n";
		Client.SetEmail(clsInputValidate::ReadString());
		cout << "\nEnter Phone Number : \n";
		Client.SetPhone(clsInputValidate::ReadString());
		cout << "\nEnter PinCode : \n";
		Client.SetPinCode(clsInputValidate::ReadString());
		cout << "\nEnter Balance : \n";
		Client.SetAcountBalance(clsInputValidate::ReadDblNumber());

	}
	
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

	static void AddNewClient()
	{
		if (! CheckAccessScreen(clsUser::enPermission::AddClient))
			return;

		clsScreen::_PrintHeader("Add New Client List");
		string s1;
		cout << "Enter the Acount Number : \n";
		getline(cin >> ws, s1);
		while (clsBankClient::IsClientExist(s1))
		{
			cout << "Acount Number already exists, chose another one : \n";
			getline(cin >> ws, s1);
		}

		clsBankClient Client1 = clsBankClient::CreateNewClient(s1);

		_ReadClient(Client1);

		clsBankClient::enSave save = Client1.SaveMode();

		switch (save)
		{
		case clsBankClient::enSave::Succeded:
			cout << "\nClient was added successfully.\n";
			_Print(Client1);
			break;

		case clsBankClient::enSave::Failed:
			cout << "Error, Adding Client was failed.\n";
			break;
		case clsBankClient::enSave::AcountNumberExist:
			cout << "Error, This Acount number already exists.\n";
			break;
		}
	}

};

