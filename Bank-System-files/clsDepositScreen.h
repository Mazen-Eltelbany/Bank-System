#pragma once
#include <iostream>
#include<iomanip>
#include "clsinputvalidate.h"
#include "clsScreen.h"
#include "clsbankclient.h"
using namespace std;
class clsDepositScreen:protected clsScreen
{
private:
	static void _printclient(clsbankclient client) {
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName  : " << client.FirstName;
		cout << "\nLastName   : " << client.LastName;
		cout << "\nFull Name  : " << client.FullName();
		cout << "\nEmail      : " << client.Email;
		cout << "\nPhone      : " << client.Phone;
		cout << "\nAcc. Number: " << client.Accountnumber();
		cout << "\nPassword   : " << client.pincode;
		cout << "\nBalance    : " << client.AccountBalance;
		cout << "\n___________________\n";
	}
	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "\nPlease enter AccountNumber? ";
		cin >> AccountNumber;
		return AccountNumber;
	}

public:
	static void ShowDepositScreen() {
		_DrawScreenHeader("\t  Deposit Screen");
		string accnum = _ReadAccountNumber();
		while (!clsbankclient::IsClientExist(accnum)) {
			cout << "\nClient with [" <<accnum << "] does not exist.\n";
			string accnum = _ReadAccountNumber();
		}
		clsbankclient client1 = clsbankclient::Find(accnum);
		_printclient(client1);
		double amount = 0;
		cout << "\nPlease enter deposit amount? ";
		amount = clsinputvalidate::ReadNumber<double>();

		cout << "\nAre you sure you want to perform this transaction? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			client1.Deposit(amount);
			cout << "\nAmount Deposited Successfully.\n";
			cout << "\nNew Balance Is: " << client1.AccountBalance;

		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}

	}
};

