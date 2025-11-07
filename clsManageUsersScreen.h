#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUserListScreen.h"
#include "clsAddUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUser.h"
#include "clsUser.h"
using namespace std;

class clsManageUsersScreen : protected clsScreen
{
private : 
	enum enChoise
	{enUsersList=1,enAddUser=2,enDeleteUser=3,enUpdateUser=4,enFindUser=5,enMainMenu=6};

	static enChoise _ReadChoice()
	{
		short Choise = 0;
		cout << "\nEnter your choise from 1 to 6 : ";
		Choise =clsInputValidate::ReadIntNumberBetween(1, 6);
		return enChoise(Choise);
	}

	static void _UsersList()
	{
		clsUserListScreen::_ShowUsersList();
	}

	static void _AddUser()
	{
		clsAddUserScreen::AddNewUser();
	}

	static void _DeleteUser()
	{
		clsDeleteUserScreen::DeleteUesr();
	}

	static void _UpdateUser()
	{
		clsUpdateUserScreen::UpdateUser();
	}

	static void _FindUser()
	{
		clsFindUser::FindUser();
	}

	static void _BackToUsersScreen()
	{
		system("pause>0");
		system("cls");
		ManageUsers();
	}

	static void _PerformUsersMenu(enChoise Choise)
	{
		switch (Choise)
		{
		case enChoise::enAddUser:
			system("cls");
			_AddUser();
			_BackToUsersScreen();
			break;

		case enChoise::enDeleteUser:
			system("cls");
			_DeleteUser();
			_BackToUsersScreen();
			break;

		case enChoise::enFindUser:
			system("cls");
			_FindUser();
			_BackToUsersScreen();
			break;

		case enChoise::enMainMenu:
		{ break; };

		case enChoise::enUpdateUser:
			system("cls");
			_UpdateUser();
			_BackToUsersScreen();
			break;

		case enChoise::enUsersList:
			system("cls");
			_UsersList();
			_BackToUsersScreen();
			break;

		}
	}


public :
	static void ManageUsers()
	{
		if (!CheckAccessScreen(clsUser::enPermission::ManageUsers))
			return;


		_PrintHeader("Manage users Screen");
		cout << left << setw(37) << "\t\t\t\t\t=======================================\n";
		cout << setw(37) << left << "\t\t\t\t\t\t\tManage Users Menu\n";
		cout << setw(37) << left << "\t\t\t\t=======================================\n";
		cout << setw(37) << left << " " << "\t\t1.Show Users List\n";
		cout << setw(37) << left << " " << "\t\t2.Add New User\n";
		cout << setw(37) << left << " " << "\t\t3.Delete User\n";
		cout << setw(37) << left << " " << "\t\t4.Update User\n";
		cout << setw(37) << left << " " << "\t\t5.Find User\n";
		cout << setw(37) << left << " " << "\t\t6.Back to Main Menu\n";
		_PerformUsersMenu(_ReadChoice());
	}

};

