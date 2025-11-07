#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"

using namespace std;
class clsFindUser : protected clsScreen
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


public:
	static void FindUser()
	{
		_PrintHeader("Find User");
		string UserName;
		cout << "Enter the User Name : ";
		getline(cin >> ws, UserName);

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "User with this User Name wasn't found, Enter a valid one : ";
			getline(cin >> ws, UserName);
		}
		clsUser User1 = clsUser::Find(UserName);
		_Print(User1); 
	}

};

