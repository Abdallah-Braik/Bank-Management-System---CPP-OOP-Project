#pragma once
#include<iostream>
#include "clsScreen.h"
#include"clsUser.h"
#include "Global.h"
#include "clsMainScreen.h"

using namespace std;
class clsLoginScreen : protected clsScreen
{
private :
	static bool _ShowLoginScreen()
	{
		string UserName, Password;
		bool LoginFailed = false;
		short Trials = 3;

		do 
		{		
	if (LoginFailed)
	{
		system("cls");
		_PrintHeader("Login Screen");
		Trials--;
		if (Trials == 0)
		{
			cout << "You don't have any more trials, the system is locked in.\n\n";
			return false;
		}
		cout << "\n\nInvalid Username/Password, you have " << Trials << " more trials, try again.\n\n";
				
	}

			cout << "\nEnter Username : ";
			cin >> UserName;
			cout << "\nEnter Password : ";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);
			
			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed == true);
	
		CurrentUser.SaveLogInInfo();
		clsMainScreen::ShowMainMenu();

	}

public:
	static bool LoginScreen()
	{
		system("cls");
		_PrintHeader("Login Screen");
		return _ShowLoginScreen();
	}








};

