#pragma once
#include<iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

using namespace std;
class clsUpdateUserScreen : protected clsScreen
{
	static void _Print(clsUser User)
	{
		cout << "\nClient card\n";
		cout << "\n-------------------------------\n";
		cout << "\nUser Name        : " << User.UserName();
		cout << "\nPassWord         : " << User.Password();
		cout << "\nFirst Name       : " << User.FirstName();
		cout << "\nLast Name      : " << User.LastName();
		cout << "\nFull Name      :" << User.FullName();
		cout << "\nEmail          : " << User.Email();
		cout << "\nPhone Number   : " << User.Phone();
		cout << "\nPermissions     : " << User.Permission();
		cout << "\n-------------------------------\n";
	}

	static void _ReadUserData(clsUser& user)
	{
		cout << "\nEnter First Name : ";
		user.SetFirstName(clsInputValidate::ReadString());

		cout << "\nEnter Last Name : ";
		user.SetLastName(clsInputValidate::ReadString());

		cout << "\nEnter PassWord : ";
		user.SetPassword(clsInputValidate::ReadString());

		cout << "\nEnter Email : ";
		user.SetEmail(clsInputValidate::ReadString());

		cout << "\nEnter Phone Number : ";
		user.SetPhone(clsInputValidate::ReadString());

		user.SetPermission(_ReadPermission());
	}

	static int _ReadPermission()
	{
		int per = 0;
		char Answer;
		cout << "\nDo you want to give this user full access ? (Y/N) : ";
		cin >> Answer;
		if (tolower(Answer) == 'y')
		{
			per = clsUser::enPermission::All;
			return per;
		}

		cout << "\nDo you want to give this user Access to Show Users List ? (Y/N) : ";
		cin >> Answer;
		if (tolower(Answer) == 'y')
			per += clsUser::enPermission::ShowClientssList;

		cout << "\nDo you want to give this user Access to Add a New User ? (Y/N) : ";
		cin >> Answer;
		if (tolower(Answer) == 'y')
			per += clsUser::enPermission::AddClient;

		cout << "\nDo you want to give this user Access to Delete a User ? (Y/N) : ";
		cin >> Answer;
		if (tolower(Answer) == 'y')
			per += clsUser::enPermission::DeleteClient;

		cout << "\nDo you want to give this user Access to Update a User ? (Y/N) : ";
		cin >> Answer;
		if (tolower(Answer) == 'y')
			per += clsUser::enPermission::UpdateClient;

		cout << "\nDo you want to give this user Access to Find a User ? (Y/N) : ";
		cin >> Answer;
		if (tolower(Answer) == 'y')
			per += clsUser::enPermission::FindClient;

		cout << "\nDo you want to give this user Access Transactions ? (Y/N) : ";
		cin >> Answer;
		if (tolower(Answer) == 'y')
			per += clsUser::enPermission::Transaction;

		cout << "\nDo you want to give this user Access to Manage Users ? (Y/N) : ";
		cin >> Answer;
		if (tolower(Answer) == 'y')
			per += clsUser::enPermission::ManageUsers;

		cout << "\nDo you want to give this user Access to the Log In Screen? (Y/N) : ";
		cin >> Answer;
		if (tolower(Answer) == 'y')
			per += clsUser::enPermission::LogIn;

		return per;

	}

public:

	static void UpdateUser()
	{
		_PrintHeader("Update User");
		string UserName;
		cout << "Enter User Name : ";
		getline(cin >> ws, UserName);
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "User Wasn't found, Enter a valid one : ";
			getline(cin >> ws, UserName);
		}

		clsUser User1 = clsUser::Find(UserName);
		_Print(User1);
		char Answer;
		cout << "\nAre you sure you want to update this user ? (Y/N)";
		cin >> Answer;
		if (tolower(Answer) == 'y')
		{
			_ReadUserData(User1);
			User1.Save();
			cout << "\nUser was updated successfullly.\n";
			_Print(User1);
		}
		else
			cout << "Process was canceled.";
	}










};

