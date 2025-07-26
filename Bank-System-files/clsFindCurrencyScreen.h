#pragma once
#include"clsCurrency.h"
#include "clsScreen.h"
#include "clsinputvalidate.h"
using namespace std;
class clsFindCurrencyScreen:protected clsScreen
{
private:
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();
        cout << "\n_____________________________\n";
    }
    static void _ShowResults(clsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
            cout << "\nCurrency Found :-)\n";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\nCurrency Was not Found :-(\n";
        }
    }
public:
    static void ShowFindCurrencyScreen() {
        _DrawScreenHeader("\t  Find Currency Screen");
        cout << "\nFind By: [1] Code or [2] Country ? ";
        short ans = 1;
        ans = clsinputvalidate::ReadNumberBetween<short>(1, 2);
        if (ans == 1) {
            string currencycode;
            cout << "\nPlease Enter Currency Code: ";
            currencycode = clsinputvalidate::ReadString();
            clsCurrency currency = clsCurrency::FindbyCode(currencycode);
            _ShowResults(currency);

        }
        if (ans == 2) {
            string country;
            cout << "\nPlease Enter Currency Code: ";
            clsCurrency currency = clsCurrency::FindbyCountry(country);
            _ShowResults(currency);
        }
      
    }
};

