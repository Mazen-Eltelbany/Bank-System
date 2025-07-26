#pragma once
#include <iostream>
#include<iomanip>
#include "clsbankclient.h"
#include "clsScreen.h"
using namespace std;
class clsDeleteClientScreen:protected clsScreen
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
	static void showdeleteclientscreen() {
		if (!CheckAccessRights(clsUser::enpermissions::edeleteclient)) {
			return;
		}
		_DrawScreenHeader("\t Delete Client Screen");
		string accnum = "";
		cout << "Please Enter Account Number: ";
		accnum = clsinputvalidate::ReadString();
		while (!clsbankclient::IsClientExist(accnum)) {
			cout << "\nAccount Number is not found,choose another one: ";
			accnum = clsinputvalidate::ReadString();
		}
		clsbankclient client1 = clsbankclient::Find(accnum);
		_printclient(client1);
		cout << "Are You Sure You want to Delete this Client y/n? ";
		char ans = 'n';
		cin >> ans;
		ans = tolower(ans);
		if (ans == 'y') {
			if (client1.Delete()) {
				cout << "\nClient Deleted Successfully :-)\n";
				_printclient(client1);
			}
			else {
				cout << "\nError Client Wasn't Deleted\n";
			}
		}
	}
};

