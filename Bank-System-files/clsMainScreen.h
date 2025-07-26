#pragma once
#include <iostream>
#include<iomanip>
#include "clsinputvalidate.h"
#include "clsScreen.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionMenu.h"
#include "clsManageUserScreen.h"
#include "clsCurrencyExchangeScreen.h"
#include "clsLoginRegister.h"
#include "Global.h"
using namespace std;
class clsMainScreen:protected clsScreen
{
private:
	enum enmainmenu {
		elistclient = 1,
		eaddnewclient = 2,
		edeleteclient = 3,
		eupdateclient = 4,
		efindclient = 5,
		eshowtransactionmenu = 6,
		emanageuser = 7,
		eLoginRegister=8,
		eCurrencyExchange=9,
		eLogout = 10
	};
	static short _ReadMainMenuOption() {
		cout << setw(37) << left << "" << "Choose What do you want? [1 to 10]: ";
		short choice=clsinputvalidate::ReadNumberBetween<short>(1,10);
		return choice;
	}
	static void _gobacktomainmenu() {
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowMainMenu();
	}
	static void _ShowAllClientsScreen()
	{
		clsClientListScreen::showclientslist();
	}

	static void _ShowAddNewClientsScreen()
	{
		clsAddNewClientScreen::showaddnewclientscreen();

	}

	static void _ShowDeleteClientScreen()
	{
		clsDeleteClientScreen::showdeleteclientscreen();
	}

	static void _ShowUpdateClientScreen()
	{
		clsUpdateClientScreen::ShowUpdateClientScreen();

	}

	static void _ShowFindClientScreen()
	{
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionsMenue()
	{
		clsTransactionMenu::ShowTransactionMenu();

	}

	static void _ShowManageUsersMenue()
	{
		clsManageUserScreen::ShowManageUsersMenue();

	}
	static void _ShowLoginRegister() {
		clsLoginRegister::ShowLoginRegister();
	}
	static void _ShowCurrencyExchangeScreen() {
		clsCurrencyExchangemenuScreen::ShowCurrencyExchangeScreen();
	}
	static void _Logout()
	{
		currentuser = clsUser::Find("", "");

	}

	static void _preformmainmenuoption(enmainmenu mainmenuoption) {
		switch (mainmenuoption) {
		case enmainmenu::elistclient:
			system("cls");
			_ShowAllClientsScreen();
			_gobacktomainmenu();
			break;
		case enmainmenu::eaddnewclient:
			system("cls");
			_ShowAddNewClientsScreen();
			_gobacktomainmenu();
			break;
		case enmainmenu::edeleteclient:
			system("cls");
			_ShowDeleteClientScreen();
			_gobacktomainmenu();
			break;
		case enmainmenu::eupdateclient:
			system("cls");
			_ShowUpdateClientScreen();
			_gobacktomainmenu();
			break;
		case enmainmenu::efindclient:
			system("cls");
			_ShowFindClientScreen();
			_gobacktomainmenu();
			break;
		case enmainmenu::eshowtransactionmenu:
			system("cls");
			_ShowTransactionsMenue();
			_gobacktomainmenu();
			break;
		case enmainmenu::emanageuser:
			system("cls");
			_ShowManageUsersMenue();
			_gobacktomainmenu();
			break;
		case enmainmenu::eLoginRegister:
			system("cls");
			_ShowLoginRegister();
			_gobacktomainmenu();
		case enmainmenu::eCurrencyExchange:
			system("cls");
			_ShowCurrencyExchangeScreen();
			_gobacktomainmenu();
		case enmainmenu::eLogout:
			system("cls");
			_Logout();
			break;
		}
	}
public:
	static void ShowMainMenu() 
	{
		system("cls");
		_DrawScreenHeader("\t\tMain Screen");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Clients List.\n ";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage User.\n";
		cout << setw(37) << left << "" << "\t[8] Login Register.\n";
		cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
		cout << setw(37) << left << "" << "\t[10] Logout.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_preformmainmenuoption((enmainmenu)_ReadMainMenuOption());
	}
};

