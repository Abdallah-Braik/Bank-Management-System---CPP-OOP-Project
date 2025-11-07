#pragma once
#include<iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsScreen.h"

using namespace std;
class clsAddUserScreen : protected clsScreen
{
private:

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

	static void _ReadUserData(clsUser & user)
	{
		cout << "\nEnter Your First Name : ";
		user.SetFirstName(clsInputValidate::ReadString());

		cout << "\nEnter Your Last Name : ";
		user.SetLastName(clsInputValidate::ReadString());

		cout << "\nEnter Your PassWord : ";
		user.SetPassword(clsInputValidate::ReadString());

		cout << "\nEnter Your Email : ";
		user.SetEmail(clsInputValidate::ReadString());

		cout << "\nEnter Your Phone Number : ";
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

		cout << "\nDo you want to give this user Access to the Log In List ? (Y/N) : ";
		cin >> Answer;
		if (tolower(Answer) == 'y')
			per += clsUser::enPermission::LogIn;

		return per;
	
	}


public:
	static void AddNewUser()
	{
		_PrintHeader("Add New Screen");
		string UserName;
		cout << "Enter User Name : ";
		getline(cin >> ws, UserName);

		while (clsUser::IsUserExist(UserName))
		{
			cout << "This User Name is taken, chose another one : ";
			getline(cin >> ws, UserName);
		}
		clsUser User1 = clsUser::AddNewUser(UserName);

		_ReadUserData(User1);
		  clsUser::ensucced Success = User1.Save();
		  if (Success == clsUser::ensucced::failed)
			  cout << "ERROR, Something Wrong Happend.\n\n";
		  
		  
		  else
		  {
			  cout << "Client was added Successfully :).\n\n";
			  _Print(User1);
		  }


	}









};

