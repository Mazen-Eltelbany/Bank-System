#pragma once
#include <iostream>
#include "clsMainScreen.h"
#include "clsUser.h"
#include "Global.h"
using namespace std;
class clsLoginScreen:protected clsScreen
{
private:
	static bool _login(){
		bool loginfailed = false;
		short trials = 0;
		string username, password;
		do {
			if (loginfailed) {
				trials++;
				cout << "\nInvalid Username/Password!\n";
				cout << "You have " << 3 - trials << " Trial(s) to login.\n\n";
			}
			if (trials == 3) {
				cout << "Your are locked after 3 Failed trials\n\n";
				return false;
			}
			cout << "Enter Username? ";
			cin >> username;
			cout << "Enter Password? ";
			cin >> password;
			currentuser = clsUser::Find(username, password);
			loginfailed = currentuser.IsEmpty();
		} while (loginfailed);
		currentuser.RegisterLogin();
		clsMainScreen::ShowMainMenu();
	}
public:
	static bool ShowLoginScreen() {
		system("cls");
		_DrawScreenHeader("\t Login Screen");
		return _login();
	}
};

