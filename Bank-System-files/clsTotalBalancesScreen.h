#pragma once
#include <iostream>
#include<iomanip>
#include "clsinputvalidate.h"
#include "clsScreen.h"
#include "clsbankclient.h"
using namespace std;
class clsTotalBalancesScreen:clsScreen
{
private:
	static void _printclientrecordbalanceline(clsbankclient client) {
		cout << setw(25) << left << "" << "| " << setw(15) << left << client.Accountnumber();
		cout << "| " << setw(40) << left << client.FullName();
		cout << "| " << setw(12) << left << client.AccountBalance;
	}
public:
	static void showtotalbalances() {
		vector<clsbankclient>vclients = clsbankclient::getclientlist();
		string Title = "\t  Balances List Screen";
		string SubTitle = "\t    (" + to_string(vclients.size()) + ") Client(s).";
		_DrawScreenHeader(Title, SubTitle);
		cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		cout << setw(25) << left << "" << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout << setw(25) << left << "" << "\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		double totalbalances = clsbankclient::gettotalbalances();
		if (vclients.size() == 0) {
			cout << "\t\t\t\tNo Clients Available In the System!";
		}
		else {
			for (clsbankclient client : vclients) {
				_printclientrecordbalanceline(client);
				cout << endl;
			}
		}
		cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		cout << setw(8) << left << "" << "\t\t\t\t\t\t\t     Total Balances = " << totalbalances << endl;
		cout << setw(8) << left << "" << "\t\t\t\t  ( " << clsUtil::numtotext(totalbalances) << ")";


	}
};

