#pragma once
#include<iostream>
#include "clsBankClient.h"
#include"clsScreen.h"
#include"clsUser.h"
#include<iomanip>
#include <string>

class clsShowClientsList:protected clsScreen
{

private :
	static void PrintClientRecord(clsBankClient c)
	{
		cout << left
			<< "| " << setw(15) << c.AcountNumber()
			<< "| " << setw(20) << c.FullName()
			<< "| " << setw(25) << c.Email()
			<< "| " << setw(15) << c.Phone()
			<< "| " << setw(10) << c.PinCode()
			<< "| " << setw(15) << fixed << setprecision(2) << c.AcountBalance()
			<< "|\n\n";
	}

public :
      static void PrintClientsList()
	{
		  if (! CheckAccessScreen(clsUser::enPermission::ShowClientssList))
			  return;


		vector<clsBankClient> vClients = clsBankClient::GetClientsList();
		clsScreen::_PrintHeader("Clients List", "( " + to_string(vClients.size()) + " ) Client");
		cout << left
			<< "| " << setw(15) << "Account Number"
			<< "| " << setw(20) << "Name"
			<< "| " << setw(25) << "Email"
			<< "| " << setw(15) << "Phone"
			<< "| " << setw(10) << "Pin Code"
			<< "| " << setw(15) << "Balance"
			<< "|\n";
		cout << "\n-----------------------------------------------------------------------------------------------------------------------\n\n";
		if (vClients.size() == 0)
			cout << "\t\t\t\t\tNO CLIENTS IN THE SYSTEM.\n\n";
		else
		{
			for (clsBankClient& c : vClients)
				PrintClientRecord(c);
		}


	}






};

