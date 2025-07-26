#pragma once
#include <iostream>
#include<iomanip>
#include "clsinputvalidate.h"
#include "clsScreen.h"
#include "clsDepositScreen.h"
#include "clsWithDrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
using namespace std;
class clsTransactionMenu:protected clsScreen
{
private:
	enum _entransactionmenuoption {
		edeposit = 1,
		ewithdraw = 2,
		eshowtotalbalance = 3,
        enTransfer=4,
        entransferlog=5,
		eshowmainmenu=6
	};

    static short ReadTransactionsMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsinputvalidate::ReadNumberBetween<short>(1, 5, "Enter Number between 1 to 4? ");
        return Choice;
    }
    static void _ShowDepositScreen()
    {
        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
        clsWithDrawScreen::ShowWithDrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        clsTotalBalancesScreen::showtotalbalances();
    }
    static void _ShowTransferScreen() {
        clsTransferScreen::ShowTransferScreen();
    }
    static void _ShowTransferLogScreen() {
        clsTransferLogScreen::ShowTransferLogScreen();
    }
    static void _GoBackToTransactionsMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        ShowTransactionMenu();

    }
    static void _PerformTransactionsMenueOption(_entransactionmenuoption TransactionsMenueOption)
    {
        switch (TransactionsMenueOption)
        {
        case _entransactionmenuoption::edeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case _entransactionmenuoption::ewithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case _entransactionmenuoption::eshowtotalbalance:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        case _entransactionmenuoption::enTransfer:
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionsMenue();
        case _entransactionmenuoption::entransferlog:
            system("cls");
            _ShowTransferLogScreen();
            _GoBackToTransactionsMenue();
        case _entransactionmenuoption::eshowmainmenu:
        {
            //do nothing here the main screen will handle it :-) ;
        }
        }


    }

public:
	static void ShowTransactionMenu() {

        system("cls");
        if (!CheckAccessRights(clsUser::enpermissions::etransaction)) {
            return;
        }
       
        _DrawScreenHeader("\t  Transactions Screen");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerformTransactionsMenueOption((_entransactionmenuoption)ReadTransactionsMenueOption());
	}
};

