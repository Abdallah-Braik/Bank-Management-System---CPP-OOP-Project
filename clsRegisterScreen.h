#pragma once
#include <iostream>
#include "clsScreen.h"
#include <fstream>
#include <vector>
#include <string>
class clsRegisterScreen : protected clsScreen
{
private :

	static vector <string> _ConvertLine(string Line,string del = "#//#")
	{
		vector <string> vLogin;
		short pos;
		while ((pos = Line.find(del)) != std::string::npos)
		{
			string part = Line.substr(0, pos);
			vLogin.push_back(part);
			Line.erase(0, pos + del.size());
		}
		if (Line != "")
			vLogin.push_back(Line);
		return vLogin;


	}

	static void _PrintOneLogIn(vector<string>c)
	{
		cout << left
			<< "| " << setw(15) << c[0]
			<< "| " << setw(20) << c[1]
			<< "| " << setw(25) << c[2]
			<< "| " << setw(15) << clsUser::_DecryptPassword(c[3])
			<< "| " << setw(10) << c[4]
			<< "|\n\n";
	}

public:

	static void ShowLogInScreen()
	{
		_PrintHeader("LogIn Screen");

		if(clsScreen::CheckAccessScreen(clsUser::enPermission::LogIn))
		{
			cout << left
				<< "| " << setw(15) << "Time"
				<< "| " << setw(20) << "Date"
				<< "| " << setw(25) << "Name"
				<< "| " << setw(15) << "PassWord"
				<< "| " << setw(10) << "Permession"
				<< "|\n";
			cout << "\n-----------------------------------------------------------------------------------------------------------------------\n\n";

			fstream file;
			file.open("Login.txt", ios::in);
			if (file.is_open())
			{
				string line;
				while (getline(file, line))
				{
					vector <string> vLogIn = _ConvertLine(line);
					_PrintOneLogIn(vLogIn);
				}
				file.close();
			}
		}


	}

};

