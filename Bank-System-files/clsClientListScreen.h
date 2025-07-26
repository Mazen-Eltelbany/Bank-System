#pragma once
#include <iostream>
#include<iomanip>
#include "clsbankclient.h"
#include "clsScreen.h"
#include "clsUser.h"
using namespace std;
class clsClientListScreen:protected clsScreen
{
private:
	static void _printclientrecordline(clsbankclient client) {
		cout << setw(8) << left << "" << "| " << setw(15) << left << client.Accountnumber();
		cout << "| " << setw(20) << left << client.FullName();
		cout << "| " << setw(12) << left << client.Phone;
		cout << "| " << setw(20) << left << client.Email;
		cout << "| " << setw(10) << left << client.pincode;
		cout << "| " << setw(12) << left << client.AccountBalance;
	}
public:
	static void showclientslist() {
		if (!CheckAccessRights(clsUser::enpermissions::elistclient)) {
			return;
		}
		
		vector<clsbankclient>vclients = clsbankclient::getclientlist();
		string Title = "\t  Client List Screen";
		string SubTitle = "\t    (" + to_string(vclients.size()) + ") Client(s).";
		_DrawScreenHeader(Title, SubTitle);
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
		cout << "|" << left << setw(20) << "Client Name";
		cout << "|" << left << setw(12) << "Phone";
		cout << "|" << left << setw(20) << "Email";
		cout << "|" << left << setw(10) << "Pin Code";
		cout << "|" << left << setw(12) << "Balance";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		if (vclients.size() == 0) {
			cout << "\t\t\t\tNo Clients Available In the System!";
		}
		else {
			for (clsbankclient Client : vclients) {
				_printclientrecordline(Client);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	}
};

