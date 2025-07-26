#pragma once
#include <iostream>
#include<iomanip>
#include "clsbankclient.h"
#include "clsScreen.h"
using namespace std;
class clsAddNewClientScreen:protected clsScreen
{
private:
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
	static void showaddnewclientscreen() {
		if (!CheckAccessRights(clsUser::enpermissions::eaddnewclient)) {
			return;
		}
		_DrawScreenHeader("\t Add New Client Screen");
		string accountnumber = "";
		cout << "Please enter account number: ";
		accountnumber = clsinputvalidate::ReadString();
		while (clsbankclient::IsClientExist(accountnumber)) {
			cout << "\nAccount Number Is Already Used,Choose Another one: ";
			accountnumber = clsinputvalidate::ReadString();
		}
		clsbankclient newclient = clsbankclient::GetAddNewClientObject(accountnumber);
		_ReadClientInfo(newclient);
		clsbankclient::ensaveresult saveresult;
		saveresult = newclient.save();
		switch (saveresult) {
		case  clsbankclient::ensaveresult::svsucceeded:
		{
			cout << "\nAccount Addeded Successfully :-)\n";
			_printclient(newclient);
			break;
		}
		case clsbankclient::ensaveresult::svfailedemptyobject:
		{
			cout << "\nError account was not saved because it's Empty";
			break;

		}
		case clsbankclient::ensaveresult::svfailedaccountnumexist:
		{
			cout << "\nError account was not saved because account number is used!\n";
			break;

		}
		}
	}
};

