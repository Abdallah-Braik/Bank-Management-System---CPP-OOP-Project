#pragma once
#pragma warning (disable:4996)
#include<iostream>
#include"clsUser.h"
#include"Global.h"
#include <ctime>
using namespace std;

class clsScreen
{
protected:

static	void _PrintHeader(string title,string subtilte=" ")
	{

	time_t t = time(0);
	tm* now = localtime(&t);

		cout << "\n-----------------------------------------------------------------------------------------------------------------------\n\n";
		cout << "\t\t\t\t\t\t\t" << title << "\n";
		cout << "\t\t\t\t\t\t\t" << subtilte << "\n";
		cout << "\n\n\t\t\t\t\t\t\t" << now->tm_mday << "/" << now->tm_mon + 1 << "/" << now->tm_year + 1900 << "\n";
		cout << "\t\t\t\t\t\t\t" << CurrentUser.FullName();
		cout << "\n-----------------------------------------------------------------------------------------------------------------------\n\n";

	}

static bool CheckAccessScreen(clsUser::enPermission Access)
{
	if (CurrentUser.CheckAccess(Access))
		return true;

	else
	{
		cout << "\n-----------------------------------------------------------------------------------------------------------------------\n\n";
		cout << "\t\t\t\t\t\tAccess Denied, Contact Your Admin.\n" ;
		cout << "\n-----------------------------------------------------------------------------------------------------------------------\n\n";
		return false;
	}

}


};

