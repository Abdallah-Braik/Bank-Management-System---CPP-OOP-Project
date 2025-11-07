#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include"clsCurrencyList.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateRateScreen.h"
#include "clsCurrencyCalaulatorScreen.h"

using namespace std;

class clsCurrancyMainScreen : protected clsScreen
{
private:

	enum enOption{ListCurrancy=1, FindCurrancy=2,UpdateCurrancy=3, Calaulator=4, Back=5};

	static enOption _ReadOption()
	{
		short N = clsInputValidate::ReadIntNumberBetween(1, 5);
		return enOption(N);
	}

	static void _ListCurrancies()
	{
		clsCurrencyList::ShowCurrenciesList();
	}

	static void _FindCurrancy()
	{
		clsFindCurrencyScreen::_FindCurrencyScreen();
	}

	static void _UpdateRate()
	{
		clsUpdateRateScreen::_ShowUpdateRateScreen();
	}

	static void _Calculator()
	{
		clsCurrencyCalaulatorScreen::ShowCalculatorScreen();
	}

	static void _BackToMenu()
	{
		system("pause>0");
		ShowMainMenu();
	}

	static void _PerformMenu(enOption E)
	{
		switch (E)
		{
			case enOption::ListCurrancy:
				system("cls");
				_ListCurrancies();
				_BackToMenu();
				break;

			case enOption::FindCurrancy:
				system("cls");
				_FindCurrancy();
				_BackToMenu();
				break;

			case enOption::UpdateCurrancy:
				system("cls");
				_UpdateRate();
				_BackToMenu();
				break;

			case enOption::Calaulator:
				system("cls");
				_Calculator();
				_BackToMenu();
				break;

			case enOption::Back:
			{}




		}

	}


public:
	static void ShowMainMenu()
	{
		system("cls");

		_PrintHeader("Currancy Main Screen");

		cout << left << setw(37) << "\t\t\t\t\t=======================================\n";
		cout << setw(37) << left << "\t\t\t\t\t\tCurrencies Screen\n";
		cout << setw(37) << left << "\t\t\t\t=======================================\n";
		cout << setw(37) << left << " " << "\t\t1.Currancies List\n";
		cout << setw(37) << left << " " << "\t\t2.Find Currancy\n";
		cout << setw(37) << left << " " << "\t\t3.Update Currancy\n";
		cout << setw(37) << left << " " << "\t\t4.Currancy Claculator\n";
		cout << setw(37) << left << " " << "\t\t5.Back to Main Menu\n";
		
		cout << "Enter Your Choise [1:5] : ";
		_PerformMenu(_ReadOption());

	}

};

