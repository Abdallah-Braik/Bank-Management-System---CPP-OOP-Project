#pragma once
#include<iostream>
#include "clsCurrency.h"
#include "clsScreen.h"
#include <string>
#include<cctype>
using namespace std;

class clsUpdateRateScreen :protected clsScreen
{
private:

	static clsCurrency _FindCurrency()
	{
		cout << "Enter Currency Code : ";
		string Code;
		cin.ignore();
		getline(cin, Code);
		
		while (! clsCurrency::IsCurrencyExistCode(Code))
		{
			cout << "\n\nCurrency was not found, Try again : ";
			getline(cin, Code);		
		}

		clsCurrency Currency = clsCurrency::FindByCode(Code);
		return Currency;

	}

	static void _Print(clsCurrency Currency)
	{
		cout << "\n\nCurrency Card\n\n";
		cout << "\n--------------------------------------\n";
		cout << "Country : " << Currency.CountryName()
			<< "\nName : " << Currency.CurrencyName()
			<< "\nCode : " << Currency.CurrencyCode()
			<< "\nRate : " << Currency.Rate();
		cout << "\n--------------------------------------\n";
	}


public :
	static void _ShowUpdateRateScreen()
	{
		_PrintHeader("Update Rate Screen");
		clsCurrency Currency = _FindCurrency();
		_Print(Currency);
		cout << "\n\nAre you sure you want to update this currency rate? (Y/N) : ";
		char answer;
		cin >> answer;
		if (tolower(answer) == 'y')
		{
			float Rate = 0;
			cout << "\nEnter the new rate : ";
				cin >> Rate;
				Currency.SetRate(Rate);
				Currency.Save();
				_Print(Currency);

		}

	}



};

