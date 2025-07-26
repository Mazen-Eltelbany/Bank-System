#pragma once
#include <iostream>
#include<iomanip>
#include "clsbankclient.h"
#include "clsScreen.h"
using namespace std;
class clsUpdateClientScreen :protected clsScreen
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
	static void _ReadClientInfo(clsbankclient& client) {
		cout << "Enter FirstName: ";
		client.FirstName = clsinputvalidate::ReadString();
		cout << "Enter LastName: ";
		client.LastName = clsinputvalidate::ReadString();
		cout << "Enter Email: ";
		client.Email = clsinputvalidate::ReadString();
		cout << "Enter Phone: ";
		client.Phone = clsinputvalidate::ReadString();
		cout << "Enter PinCode: ";
		client.pincode = clsinputvalidate::ReadString();
		cout << "Enter Account Balance: ";
		client.AccountBalance = clsinputvalidate::ReadNumber<float>();
	}

public:
	static void ShowUpdateClientScreen() {
		if (!CheckAccessRights(clsUser::enpermissions::eupdateclient)) {
			return;
		}
		_DrawScreenHeader("\t Update Client Screen");
		string AccountNumber = "";
		cout << "\nPlease Enter Client Account Number: ";
		AccountNumber = clsinputvalidate::ReadString();
		while (!clsbankclient::IsClientExist(AccountNumber)) {
			cout << "Account Number is not found,Choose Another One: ";
			AccountNumber = clsinputvalidate::ReadString();
		}
		clsbankclient client1 = clsbankclient::Find(AccountNumber);
		_printclient(client1);
		cout << "\n\nUpdate Client Info:";
		cout << "\n---------------------\n";
		_ReadClientInfo(client1);
		clsbankclient::ensaveresult saveresult;
		saveresult = client1.save();
		switch (saveresult) {
		case clsbankclient::ensaveresult::svsucceeded:
			cout << "\nAccount Updated Successfully :-)\n";
			_printclient(client1);
			break;
		case clsbankclient::ensaveresult::svfailedemptyobject:
			cout << "\nError account was not saved because it's Empty";
			break;
		}
	}
};


