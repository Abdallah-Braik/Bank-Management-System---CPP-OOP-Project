#pragma once
#include<iostream>
#include <iomanip>
#include<vector>
#include"clsUser.h"
#include"clsScreen.h"

using namespace std;

class clsUserListScreen: protected clsScreen
{
private:
	static void _PrintUserRecord(clsUser c)
	{
		cout << left
			<< "| " << setw(15) << c.UserName()
			<< "| " << setw(20) << c.FullName()
			<< "| " << setw(10) << c.Password()
			<< "| " << setw(15) << c.Phone()
			<< "| " << setw(25) << c.Email()
			<< "| " << setw(15) << fixed << setprecision(2) << c.Permission()
			<< "|\n\n";
	}


public:

	static void _ShowUsersList()
	{
		vector <clsUser> vUser = clsUser::GetUsersList();
		_PrintHeader("Users List", "( " + to_string(vUser.size()) + " ) User");
		cout << left
			<< "| " << setw(15) << "User Name"
			<< "| " << setw(20) << "FullName"
			<< "| " << setw(10) << "PassWord"
			<< "| " << setw(15) << "Phone"
			<< "| " << setw(25) << "Email"
			<< "| " << setw(15) << "Permission"
			<< "|\n";
		cout << "\n-----------------------------------------------------------------------------------------------------------------------\n\n";
		if(vUser.size ()==0)
			cout << "\t\t\t\t\tNO CLIENTS IN THE SYSTEM.\n\n";

		else
		{
			for (clsUser& C : vUser)
				_PrintUserRecord(C);
		}
	}




};

