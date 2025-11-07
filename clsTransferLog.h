#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include "clsScreen.h"
using namespace std;
class clsTransferLog: protected clsScreen
{
	static vector <string> _ConvertOneRectord(string S, string del="#//#")
	{
		vector <string>vS;
		string part;
		short pos;
		while ((pos = S.find(del)) != std::string::npos)
		{
			part = S.substr(0, pos);
			vS.push_back(part);
			S.erase(0, pos + del.size());
		}

		if (S != "")
			vS.push_back(S);

		return vS;
	}

	static void _PrintOneRecord(vector<string> vS)
	{
		cout << left
			<< "| " << setw(10) << vS[0]
			<< "| " << setw(20) << vS[1]
			<< "| " << setw(6) << vS[2]
			<< "| " << setw(15) << vS[3]
			<< "| " << setw(6) << vS[4]
			<< "| " << setw(15) << vS[5]
			<< "| " << setw(15) << vS[6]
			<< "| " << setw(12) << vS[7]
			<< "|\n\n";

	}




public:
	static void ShowTransferLogScreen()
	{
		_PrintHeader("Tranfers Log Screen");
		cout << left
			<< "\n| " << setw(10) << "Time"
			<< "| " << setw(20) << "Date"
			<< "| " << setw(6) << "S.Acc"
			<< "| " << setw(15) << "S.Balance"
			<< "| " << setw(6) << "D.Acc"
			<< "| " << setw(15) << "D.Balance"
			<< "| " << setw(15) << "Amount"
			<< "| " << setw(12) << "Admin"
			<< "|\n";
		cout << "\n-----------------------------------------------------------------------------------------------------------------------\n\n";

		fstream file;
		file.open("TransferLog.txt", ios::in);
		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				_PrintOneRecord(_ConvertOneRectord(line));
			}

			file.close();
		}
		cout << "\n-----------------------------------------------------------------------------------------------------------------------\n\n";
	}




};

