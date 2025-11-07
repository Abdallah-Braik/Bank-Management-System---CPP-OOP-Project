#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsMainScreen.h"
#include "clsDeposit.h"
#include "clsWithdraw.h"
#include "clsShowTotalBalances.h"
#include"clsUser.h"
#include "clsTransfer.h"
#include "clsTransferLog.h"
using namespace std;

class clsTransaction : protected clsScreen
{
private:


	enum enTransaction {Deposit=1,Withdraw=2,TotalBalances=3,Transfer=4,TransferLog=5, MainMenu=6 };
  
	static enTransaction _ReadOption()
	{
		cout << "Enter your choice : ";
		short choice = clsInputValidate::ReadIntNumberBetween(1,6);
		return enTransaction(choice);
	}

	static void _Deposit()
	{
		clsDeopsit::DepositScreen();
	}

	static void _WithDraw()
	{
		clsWithdraw::WithdrawScreen();
	}

	static void _TotalBalances()
	{
		clsShowTotalBalances::PrintClientsBalances();
	}

	static void _Transactionmenu()
	{
		system("pause>0");
		ShowTransactionMenu();
	}

	static void _Transfer()
	{
		clsTransfer::ShowTransferScreen();
	}

	static void _TransferLog()
	{
		clsTransferLog::ShowTransferLogScreen();
	}

	static void _PerformTransactionMenu(enTransaction choice)
	{
		switch (choice)
		{
		case enTransaction::Deposit:
			system("cls");
			_Deposit();
			_Transactionmenu();
			break;

		case enTransaction::Withdraw:
			system("cls");
			_WithDraw();
			_Transactionmenu();
			break;

		case enTransaction::TotalBalances:
			system("cls");
			_TotalBalances();
			_Transactionmenu();
			break;
		
		case enTransaction::Transfer:
			system("cls");
			_Transfer();
			_Transactionmenu();
			break;

		case enTransaction::TransferLog:
			system("cls");
			_TransferLog();
			_Transactionmenu();
			break;

		case enTransaction::MainMenu:
		{}
		
		}

	}

public : 

	static void ShowTransactionMenu()
	{
		if (!CheckAccessScreen(clsUser::enPermission::Transaction))
			return;

		system("cls");
		_PrintHeader("Transaction Screen");

		cout << left << setw(37) << "\t\t\t\t\t=======================================\n";
		cout << setw(37) << left << "\t\t\t\t\t\t\tTransaction Menu\n";
		cout << setw(37) << left << "\t\t\t\t=======================================\n";
		cout << setw(37) << left << " " << "\t\t1.Deposit\n";
		cout << setw(37) << left << " " << "\t\t2.Withdraw\n";
		cout << setw(37) << left << " " << "\t\t3.Show All Balances\n";
		cout << setw(37) << left << " " << "\t\t4.Transfer\n";
		cout << setw(37) << left << " " << "\t\t5.Transfer Log Screen\n";
		cout << setw(37) << left << " " << "\t\t6.Back to Main Menu\n";

		_PerformTransactionMenu(_ReadOption());
		



	}



};

