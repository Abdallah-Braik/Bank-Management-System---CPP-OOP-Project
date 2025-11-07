#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"


using namespace std;
class clsCurrencyCalaulatorScreen : protected clsScreen
{
private :

	static clsCurrency _FindCurrency(string msg="Enter Currency 1 Code : ")
	{
		cout << msg;
		string Code;
		cin >> Code;

		while (!clsCurrency::IsCurrencyExistCode(Code))
		{
			cout << "\n\nCurrency was not found, Try again : ";
			cin >> Code;
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

	static double _Exchange(clsCurrency c1, clsCurrency c2, double Amount)
	{
		double AmountInUSD =   Amount/ c1.Rate();
		double	Exchange2 = AmountInUSD * c2.Rate();
		return Exchange2;

	}






public :
	static void ShowCalculatorScreen()
	{	
		
		char answer;
		do {
			system("cls");
			_PrintHeader("Currency Exchange Calculator");
			clsCurrency Currency1 = _FindCurrency();
			clsCurrency Currency2 = _FindCurrency("Enter Currency 2 Code : ");

			cout << "Enter the Amount to exchange : ";
			double Amount = clsInputValidate::ReadDblNumber();

			double Exchange = _Exchange(Currency1, Currency2, Amount);
			cout << "\n\nExchanging " << Amount << " of " << Currency1.CurrencyCode() <<
				" to " << Currency2.CurrencyCode() << " = " << Exchange;
		
			cout << "\n\nDo you want to do any more Calculations ? (Y/N) : ";
			cin >> answer;
		} while (tolower(answer) == 'y');


	}




};

