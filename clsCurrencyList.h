#pragma once
#include <iostream>
#include <iomanip>
#include "clsCurrency.h"
#include "clsScreen.h"



class clsCurrencyList: protected clsScreen
{
private :

	static void _PrintCurrency(clsCurrency C)
	{
		cout << left
			<< "| " << setw(20) << C.CountryName()
			<< "| " << setw(6) << C.CurrencyCode()
			<< "| " << setw(25) << C.CurrencyName()
			<< "| " << setw(6) << C.Rate()
			<< "|\n\n";
	}








public:

	static void ShowCurrenciesList()
	{
		vector <clsCurrency> vC = clsCurrency::GetCurrencyList();
		_PrintHeader("Currencies List", "( " + to_string(vC.size()) + " ) Currency");
		cout << left
			<< "| " << setw(20) << "Country"
			<< "| " << setw(6) << "Code"
			<< "| " << setw(25) << "Currency Name"
			<< "| " << setw(6) << "Rate"
			<< "|\n";
		cout << "\n-----------------------------------------------------------------------------------------------------------------------\n\n";

		for (clsCurrency& C : vC)
			_PrintCurrency(C);

	}






};

