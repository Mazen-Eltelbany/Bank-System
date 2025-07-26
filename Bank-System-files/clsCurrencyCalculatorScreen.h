#pragma once
#include"clsCurrency.h"
#include "clsScreen.h"
#include "clsinputvalidate.h"
using namespace std;
class clsCurrencyCalculatorScreen:protected clsScreen
{
private:
    static  void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card:")
    {

        cout << "\n" << Title << "\n";
        cout << "_____________________________\n";
        cout << "\nCountry       : " << Currency.Country();
        cout << "\nCode          : " << Currency.CurrencyCode();
        cout << "\nName          : " << Currency.CurrencyName();
        cout << "\nRate(1$) =    : " << Currency.Rate();
        cout << "\n_____________________________\n\n";

    }    static string _ReadCurrencyCode() {
        string currency = clsinputvalidate::ReadString();
        while (!clsCurrency::IsCurrencyExist(currency)) {
            cout << "Invalid Currency Code, Enter Another One:\n ";
            currency = clsinputvalidate::ReadString();
        }
        return currency;
    }
    static void _PrintCalculationsResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
    {

        _PrintCurrencyCard(Currency1, "Convert From:");

        float AmountInUSD = Currency1.convertcurrencytousd(Amount);

        cout << Amount << " " << Currency1.CurrencyCode()
            << " = " << AmountInUSD << " USD\n";

        if (Currency2.CurrencyCode() == "USD")
        {
            return;
        }

        cout << "\nConverting from USD to:\n";

        _PrintCurrencyCard(Currency2, "To:");

        float AmountInCurrrency2 = Currency1.convertcurrency(Currency2, Amount);

        cout << Amount << " " << Currency1.CurrencyCode()
            << " = " << AmountInCurrrency2 << " " << Currency2.CurrencyCode();

    }
    static float _ReadAmount()
    {
        cout << "\nEnter Amount to Exchange: ";
        float Amount = 0;

        Amount = clsinputvalidate::ReadNumber<float>();
        return Amount;
    }
    static clsCurrency _GetCurrency(string Message)
    {

        string CurrencyCode;
        cout << Message << endl;

        CurrencyCode = clsinputvalidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency is not found, choose another one: ";
            CurrencyCode = clsinputvalidate::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindbyCode(CurrencyCode);
        return Currency;

    }

public:
    static void ShowCurrencyCalculatorScreen() {
        char cont = 'y';
        while (cont=='y'||cont=='Y') {
            system("cls");
            _DrawScreenHeader("\t Calculator Currency");
            clsCurrency currency1 = _GetCurrency("\nPlease Enter Currency1 Code: ");
            clsCurrency currency2 = _GetCurrency("\nPlease Enter Currency2 Code: ");
            float amount = _ReadAmount();
            _PrintCalculationsResults(amount, currency1, currency2);

            cout << "\n\nDo you want to perform another calculation? y/n ? ";
            cin >> cont;

        }
       

    }
};

