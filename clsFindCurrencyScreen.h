#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

using namespace std;
class clsFindCurrencyScreen : protected clsScreen
{
private :
	static clsCurrency _FindByCountry()
	{
		cout << "Enter The Country Name : ";
			string Country ;
			cin.ignore();
			getline(cin, Country);
			while (!clsCurrency::IsCurrencyExistCountry (Country) )
			{
				cout << "\n\nCountry was not found, try again : ";
			
				getline(cin, Country);

			}
			clsCurrency Currency= clsCurrency::FindByCountry(Country);

			return Currency;
	}

	static clsCurrency _FindByCode()
	{
		cout << "Enter the Currency Code : ";
		string code;
		cin.ignore();
		getline(cin, code);
		while (!clsCurrency::IsCurrencyExistCode(code))
		{
			cout << "\nCurrency was not found, Try again : ";
			getline(cin, code);
		}
		clsCurrency Currency = clsCurrency::FindByCode(code);

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
	static void _FindCurrencyScreen()
	{
		_PrintHeader("Find Currency Screen");
		cout << "Find By Country (1) | Find By Code (2)   : ";
		short choise = clsInputValidate::ReadIntNumberBetween(1, 2);

		if (choise == 1)
		{
			system("cls");
			clsCurrency Currency = _FindByCountry();
				_Print(Currency);
		}

		else
		{
			system("cls");
			clsCurrency Currency = _FindByCode();
			_Print(Currency);
		}




	}


};

