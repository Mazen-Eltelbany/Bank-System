#pragma once
#include<iostream>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsinputvalidate.h"
using namespace std;
class clsListUserScreen :protected clsScreen
{
private:
	static void _printuserrecordline(clsUser user) {
        cout << setw(8) << left << "" << "| " << setw(12) << left << user.UserName;
        cout << "| " << setw(25) << left << user.FullName();
        cout << "| " << setw(12) << left << user.Phone;
        cout << "| " << setw(20) << left << user.Email;
        cout << "| " << setw(10) << left << user.Password;
        cout << "| " << setw(12) << left << user.Permissions;
	}
public:
    static void ShowUserList() {
        vector <clsUser> vUsers = clsUser::GetUsersList();

        string Title = "\t  User List Screen";
        string SubTitle = "\t    (" + to_string(vUsers.size()) + ") User(s).";
        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(12) << "UserName";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vUsers.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (clsUser User : vUsers)
            {

                _printuserrecordline(User);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }
};

