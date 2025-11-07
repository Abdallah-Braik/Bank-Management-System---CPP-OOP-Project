#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"


using namespace std;

class clsDeleteUserScreen : protected clsScreen
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

public :
	static void DeleteUesr()
	{
		_PrintHeader("Delete User");
		string UserName = " ";
		cout << "Enter the User Name : ";
		getline(cin >> ws, UserName);

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "User Name doesn't exist, enter a valid one : ";
			getline(cin >> ws, UserName);
		}

		clsUser User1 = clsUser::Find(UserName);
		_Print(User1);
		cout << "Are you sure you want to delete this user ?  (Y/N) : ";
		char Answer;
		cin >> Answer;
		if (tolower(Answer) == 'y')
		{
			if (User1.Delete())
			{
				User1.Save();
				cout << "\nUser was deleted successfully.\n";
				_Print(User1);
			}
			else
				cout << "\nSomething wrong happened.\n";
		}

		else
			cout << "Deleting process was canceled.\n";
	}







};

