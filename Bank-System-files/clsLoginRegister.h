#pragma warning(disable : 4996)	
#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "Global.h"
using namespace std;
class clsLoginRegister :protected clsScreen
{
private:
    static void _printloginregisterrecordline(clsUser::stloginregisterrecord login) {
        cout << setw(8) << left << "" << "| " << setw(35) << left << login.datetime;
        cout << "| " << setw(20) << left << login.Username;
        cout << "| " << setw(20) << left << login.password;
        cout << "| " << setw(10) << left << login.permissions;
    }
public:
     static void ShowLoginRegister() {
         if (!CheckAccessRights(clsUser::enpermissions::eLoginRegister)) {
             return;
         }
        vector<clsUser::stloginregisterrecord>vuser = clsUser::GetLoginRegister();
        string Title = "\tLogin Register List Screen";
        string SubTitle = "\t\t(" + to_string(vuser.size()) + ") Record(s).";
        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vuser.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else

            for (clsUser::stloginregisterrecord Record : vuser)
            {

                _printloginregisterrecordline(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};

