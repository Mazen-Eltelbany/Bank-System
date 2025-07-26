#pragma once
#include <iostream>
#include<iomanip>
#include "clsbankclient.h"
#include "clsScreen.h"
using namespace std;
class clsFindClientScreen :protected clsScreen
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
public:
	static void ShowFindClientScreen() {
		if (!CheckAccessRights(clsUser::enpermissions::efindclient)) {
			return;
		}
		_DrawScreenHeader("\t Find Client Screen");
		string accnum;
		cout << "\nPlease enter Account Number: ";
		accnum = clsinputvalidate::ReadString();
		while (!clsbankclient::IsClientExist(accnum)) {
			cout << "Account Number is not found,choose another one: ";
			accnum = clsinputvalidate::ReadString();
		}
		clsbankclient client = clsbankclient::Find(accnum);
		if (!client.isEmpty()) {
			cout << "\nClient Found :-)\n";
		}
		else {
			cout << "Client Was Not Found :-(\n";
		}
		_printclient(client);
	}
};

