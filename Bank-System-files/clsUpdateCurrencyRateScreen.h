#pragma once
#include"clsCurrency.h"
#include "clsScreen.h"
#include "clsinputvalidate.h"
using namespace std;
class clsUpdateCurrencyRateScreen:protected clsScreen
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
    static float _ReadRate()
    {
        cout << "\nEnter New Rate: ";
        float NewRate = 0;

        NewRate = clsinputvalidate::ReadNumber<float>();
        return NewRate;
    }
public:
	static void ShowUpdateCurrencyRateScreen() {
		_DrawScreenHeader(" Update Currency Screen");
		cout << "Please Enter Currency Code: ";
        string currencycode = clsinputvalidate::ReadString();
        while (!clsCurrency::IsCurrencyExist(currencycode)) {
            cout << "This code doesn't exist, enter another one? ";
            currencycode = clsinputvalidate::ReadString();
        }
        clsCurrency currency = clsCurrency::FindbyCode(currencycode);
        _PrintCurrency(currency);
        cout << "Are you sure you want to Update the rate of this currency y/n? ";
        char ans = 'n';
        cin >> ans;
        ans = tolower(ans);
        if (ans == 'y') {
            cout << "\n\nUpdate Currency Rate:";
            cout << "\n____________________\n";
            float newrate = _ReadRate();
            currency.UpdateRate(newrate);
            cout << "\nCurrency Rate Updated Successfully :-)\n";
            _PrintCurrency(currency);
        }
	}
};

