#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsUser.h"

using namespace std;

class clsUpdateClient : protected clsScreen
{
private :

   static 	void _ReadClient(clsBankClient& Client)
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

	static void UpdateClient()
	{
		if (!CheckAccessScreen(clsUser::enPermission::UpdateClient))
			return;

		_PrintHeader("Update Client");
		
		string s1 = "";
		cout << "Please Enter the Acount Number \n";
		getline(cin >> ws, s1);
		while (!clsBankClient::IsClientExist(s1))
		{
			cout << "Acount Number doesn't exist, Enter again : \n";
			getline(cin >> ws, s1);
		}
		clsBankClient Client1 = clsBankClient::Find(s1);

		_Print(Client1);

		cout << "\nUpdate Client info\n";
		cout << "---------------------------\n";
		_ReadClient(Client1);
		cout << "---------------------------\n";
		clsBankClient::enSave save = Client1.SaveMode();

		if (save == clsBankClient::enSave::Failed)
			cout << "Error, Client update was failed.\n";

		else if (save == clsBankClient::enSave::Succeded)
		{
			cout << "Client was updated successfully :)\n";
			_Print(Client1);
		}
	}


};

