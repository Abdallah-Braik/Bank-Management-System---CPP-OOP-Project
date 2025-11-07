#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"


using namespace std;

class clsWithdraw : protected clsScreen
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
		cout << "\nAcount Balance : " << fixed << setprecision(2) << Client.AcountBalance() << endl;
		cout << "\n-------------------------------\n";
	}

public :
	static void WithdrawScreen()
	{
		_PrintHeader("Withdraw");
		cout << "\nEnter your Acount Number : ";
		string AcountNumber = "";
		getline(cin >> ws, AcountNumber);

		while (!clsBankClient::IsClientExist(AcountNumber))
		{
			cout << "\nAcount Number doesn't exist, Enter another one : ";
			getline(cin >> ws, AcountNumber);
		}

		clsBankClient Client1 = clsBankClient::Find(AcountNumber);
		_Print(Client1);
		double Amount = 0;
		string Answer = "";
		cout << "\nEnter the Amount you want to withdraw : ";
		cin >> Amount;
		cout << "\nAre you sure You want to Withdraw this Amount ? (Y/N) : ";
		cin >> Answer;
		if(Answer=="Y"||Answer=="y")
		{ 
		
			bool statement = Client1.Withdraw(Amount);
		
		if (statement == true)
		{
			cout << "\nYour Transaction was done successfully, You new balance is : ";
			cout << fixed << setprecision(2) << Client1.AcountBalance() << endl;
		}
 
		else
		{
			cout << "\nThe amount you entered is out of range, your Acount Balance is : "
				<< Client1.AcountBalance();
		}

	    }

		else
		{
			cout << "\nTransaction was Canceled.\n";
		}



	}

};

