#pragma once
#include <iostream>
#include<iomanip>
#include "clsinputvalidate.h"
#include "clsScreen.h"
#include "clsbankclient.h"
using namespace std;
class clsTransferScreen:protected clsScreen
{
private:
	static void _printclientcard(clsbankclient client) {
		cout << "\nClient Card:\n";
		cout << "\n__________________________________________________\n";
		cout << "\nFull Name  : " << client.FullName() << endl;
		cout << "Acc. Number  :" << client.Accountnumber() << endl;
		cout << "Balance      : " << client.AccountBalance << endl;
		cout << "\n__________________________________________________\n";
	}
	static float ReadAmount(clsbankclient SourceClient)
	{
		float Amount;

		cout << "\nEnter Transfer Amount? ";

		Amount = clsinputvalidate::ReadNumber<float>();

		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
			Amount = clsinputvalidate::ReadNumber<double>();
		}
		return Amount;
	}
	static string _ReadAccountNumber()
	{
		string AccountNumber;
		cout << "\nPlease Enter Account Number to Transfer From: ";
		AccountNumber = clsinputvalidate::ReadString();
		while (!clsbankclient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsinputvalidate::ReadString();
		}
		return AccountNumber;
	}



public:
	static void ShowTransferScreen() {
		_DrawScreenHeader("\tTransfer Screen");
		string accnum1 = _ReadAccountNumber();
		clsbankclient client1 = clsbankclient::Find(accnum1);
		_printclientcard(client1);
		string accnum2 = _ReadAccountNumber();
		clsbankclient client2 = clsbankclient::Find(accnum2);
		_printclientcard(client2);
		double transamount = ReadAmount(client1);
		cout << "Are You Sure You want To preform this operation?y/n? ";
		char ans = 'n';
		cin >> ans;
		ans = tolower(ans);
		if (ans == 'y') {
			if (client1.Transfer(transamount,client2,currentuser.UserName)) {
				cout << "\nTransfer Done Successfully\n";
			}
			else {
				cout << "\nCannot withdraw, Insuffecient Balance!\n";
				cout << "\nAmout to withdraw is: " <<transamount;
				cout << "\nYour Balance is: " << client1.AccountBalance;
			}
		}
		_printclientcard(client1);
		_printclientcard(client2);


	}
};

