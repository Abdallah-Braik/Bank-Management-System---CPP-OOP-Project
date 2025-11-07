#pragma once
#include <iostream>
#include "clsBankClient.h"
#include <iomanip>
#include "clsUtility.h"
using namespace std;
class clsShowTotalBalances 
{

 static void PrintClientBalance(clsBankClient Client)
	{
		cout << left
			<< "|" << setw(19) << Client.AcountNumber()
			<< "|" << setw(22) << Client.FullName();
		cout << "|" << setw(22)  << fixed << setprecision(2) << Client.AcountBalance() << "\n\n";

	}


public:


	static void PrintClientsBalances()
	{
		vector<clsBankClient> vClients = clsBankClient::GetClientsList();

		cout << "\n-----------------------------------------------------------------------------------------------------------------------\n";
		cout << "\n\t\t\t\t\tClients   Balances   ( " << vClients.size() << " ) Client\n";
		cout << "\n-----------------------------------------------------------------------------------------------------------------------\n\n";

		cout << left
			<< "| " << setw(18) << "Account Number"
			<< "| " << setw(21) << "Name"
			<< "| " << setw(24) << "Balance" << "\n\n";
		
		for (clsBankClient& c : vClients)
		{
			PrintClientBalance(c);
		}


		double TotalBalances = clsBankClient::TotalBalances();
		cout << "\n\n" << right << "Total Balances : " << TotalBalances;
		cout << "\n\n( " << clsUtility::NumberToText(TotalBalances) << " )\n";


	}

};

