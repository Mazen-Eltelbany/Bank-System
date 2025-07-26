#pragma once
#include"clsCurrency.h"
#include "clsScreen.h"
#include "clsinputvalidate.h"
#include "clsShowCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include"clsCurrencyCalculatorScreen.h"
using namespace std;
class clsCurrencyExchangemenuScreen:protected clsScreen
{
private:
	enum encurrencymenu {
		enlistccurrencies=1,
		enfindcurrency=2,
		enupdaterate=3,
		encurrencycalculator=4,
		enmainmenu=5
	};
	static short _ReadCurrencyMenuOption() {
		short choice;
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";

		choice = clsinputvalidate::ReadNumberBetween<short>(1, 5);
		return choice;
	}
	static void _ShowCurrenciesListScreen() {
		clsShowCurrenciesListScreen::ShowCurrenciesListScreen();
	}
	static void _ShowFindCurrenciesScreen() {
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}
	static void _ShowUpdateCurrencyScreen() {
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}
	static void _ShowCurrencyCalculatorScreen() {
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}
	static void _GoBackToCurrencyMenu() {
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
		system("pause>0");
		ShowCurrencyExchangeScreen();
	}
	static void Preformcurrencymenuoperation(encurrencymenu choice) {
		switch (choice) {
		case encurrencymenu::enlistccurrencies:
			system("cls");
			_ShowCurrenciesListScreen();
			_GoBackToCurrencyMenu();
			break;
		case encurrencymenu::enfindcurrency:
			system("cls");
			_ShowFindCurrenciesScreen();
			_GoBackToCurrencyMenu();
			break;
		case encurrencymenu::enupdaterate:
			system("cls");
			_ShowUpdateCurrencyScreen();
			_GoBackToCurrencyMenu();
			break;
		case encurrencymenu::encurrencycalculator:
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyMenu();
			break;
		case encurrencymenu::enmainmenu: {

		}

		}
	}
public:
	static void ShowCurrencyExchangeScreen() {
		system("cls");
		if (!CheckAccessRights(clsUser::enpermissions::ecurrency)) {
			return;
		}
		_DrawScreenHeader("    Currancy Exhange Main Screen");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Currency Exhange Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";


		Preformcurrencymenuoperation((encurrencymenu)_ReadCurrencyMenuOption());
	}
};

