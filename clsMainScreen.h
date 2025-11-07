#pragma once
#include<iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsShowClientsList.h"
#include "clsAddNewClient.h"
#include "clsDeleteClient.h"
#include "clsUpdateClient.h"
#include "clsFindClient.h"
#include "clsTransaction.h"
#include "clsManageUsersScreen.h"
#include"Global.h"
#include "clsRegisterScreen.h"
#include "clsCurrencyMainScreen.h"

using namespace std;



class clsMainScreen : protected clsScreen
{


private :
	enum enMainMenuOption {ShowClientsList=1,AddNewClient=2,DeleteClient=3,UpdateClient=4,FindClient=5,
		Transactions=6,ManageUsers=7,LoginList=8,Currency=9, LogOut=10};

	static short _ReadMainMenuOption()
	{
		cout << "\nEnter your choice [1-10]: \n";

		short Option = clsInputValidate::ReadIntNumberBetween(1, 10);
		return Option;
	}

	static void _ShowClientsList()
	{
		clsShowClientsList::PrintClientsList();
	}

	static void _AddNewClient()
	{
		clsAddNewClient::AddNewClient();
	}

	static void _DeleteClient()
	{
		clsDeleteClient::DeleteClient();
	}

	static void _UpdateClient()
	{
		clsUpdateClient::UpdateClient();
	}

	static void _FindClient()
	{
		clsFindClient::FindClient();
	}

	static void _Transaction()
	{
		clsTransaction::ShowTransactionMenu();
	}

	static void _ManageUsers()
	{
		clsManageUsersScreen::ManageUsers();
	}

	static void _Currancy()
	{
		clsCurrancyMainScreen::ShowMainMenu();
	}

	static void _LogOut()
	{
		CurrentUser = clsUser::Find("", "");
	}

	static void _LogInList()
	{
		clsRegisterScreen::ShowLogInScreen();
	}

	static void _BackToMainMenuScreen()
	{
		system("pause>0");
		ShowMainMenu();

	}

	static void _PerformMainMenu(enMainMenuOption enOption)
	{
		switch (enOption)
		{
		case enMainMenuOption::ShowClientsList:
			system("cls");
			_ShowClientsList();
			_BackToMainMenuScreen();
			break;

		case enMainMenuOption::AddNewClient:
			system("cls");
			_AddNewClient();
			_BackToMainMenuScreen();
			break;

		case enMainMenuOption::DeleteClient:
			system("cls");
			_DeleteClient();
			_BackToMainMenuScreen();
			break;

		case enMainMenuOption::UpdateClient:
			system("cls");
			_UpdateClient();
			_BackToMainMenuScreen();
			break;

		case enMainMenuOption::FindClient:
			system("cls");
			_FindClient();
			_BackToMainMenuScreen();
			break;

		case enMainMenuOption::Transactions:
			system("cls");
			_Transaction();
			_BackToMainMenuScreen();
			break;

		case enMainMenuOption::ManageUsers:
			system("cls");
			_ManageUsers();
			_BackToMainMenuScreen();
			break;

		case enMainMenuOption::Currency:
			system("cls");
			_Currancy();
			_BackToMainMenuScreen();
			break;

		case enMainMenuOption::LogOut:
			_LogOut();
			break;

		case enMainMenuOption::LoginList:
			system("cls");
			_LogInList();
			_BackToMainMenuScreen();
			break;

		}

	 }



public:

	static void ShowMainMenu()
	{
		system("cls");

		_PrintHeader("Main Screen");

		cout << left << setw(37) << "\t\t\t\t\t=======================================\n";
		cout << setw(37) << left << "\t\t\t\t\t\t\tMain Menu\n";
		cout << setw(37) << left << "\t\t\t=======================================\n";
		cout << setw(37) << left << " " << "\t\t1.Show Clients List\n";
		cout << setw(37) << left << " " << "\t\t2.Add New Client\n";
		cout << setw(37) << left << " " << "\t\t3.Delete Client\n";
		cout << setw(37) << left << " " << "\t\t4.Update Client Info\n";
		cout << setw(37) << left << " " << "\t\t5.Find Client\n";
		cout << setw(37) << left << " " << "\t\t6.Transactions\n";
		cout << setw(37) << left << " " << "\t\t7.Manage Users\n";
		cout << setw(37) << left << " " << "\t\t8.LogIn List\n";
		cout << setw(37) << left << " " << "\t\t9.Currancy Exchange\n";
		cout << setw(37) << left << " " << "\t\t10.Log Out\n";



		_PerformMainMenu(enMainMenuOption(_ReadMainMenuOption()));

	}




};

