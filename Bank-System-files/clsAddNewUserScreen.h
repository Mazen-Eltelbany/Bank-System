#pragma once
#include<iostream>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsinputvalidate.h"
using namespace std;
class clsAddNewUserScreen:protected clsScreen
{
private:
    static int _readpermissiontoset() {
        int premissions = 0;
        char ans = 'n';
        cout << "\nDo you want to give full access? y/n? ";
        cin >> ans;
        ans = tolower(ans);
        if (ans == 'y') {
            return -1;
        }
        cout << "\nDo you want to give access to : \n ";
        cout << "\nShow Client List? y/n? ";
        cin >> ans;
        ans = tolower(ans);
        if (ans == 'y') {
            premissions += clsUser::enpermissions::elistclient;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> ans;
        if (ans == 'y' || ans == 'Y')
        {
            premissions += clsUser::enpermissions::eaddnewclient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> ans;
        if (ans == 'y' || ans == 'Y')
        {
            premissions += clsUser::enpermissions::edeleteclient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> ans;
        if (ans == 'y' || ans == 'Y')
        {
            premissions += clsUser::enpermissions::eupdateclient;
        }

        cout << "\nFind Client? y/n? ";
        cin >> ans;
        if (ans == 'y' || ans == 'Y')
        {
            premissions += clsUser::enpermissions::efindclient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> ans;
        if (ans == 'y' || ans == 'Y')
        {
            premissions += clsUser::enpermissions::etransaction;
        }

        cout << "\nManage Users? y/n? ";
        cin >> ans;
        if (ans == 'y' || ans == 'Y')
        {
            premissions += clsUser::enpermissions::emanageusers;
        }
        cout << "\n Show Login Register? y/n? ";
        cin >> ans;
        if (ans == 'y' || ans == 'Y') {
            premissions += clsUser::enpermissions::eLoginRegister;
        }
        cout << "\n Currency Exchange? y/n? ";
        cin >> ans;
        if (ans == 'y' || ans == 'Y') {
            premissions += clsUser::enpermissions::ecurrency;
        }
        return premissions;
    }
    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter FirstName: ";
        User.FirstName = clsinputvalidate::ReadString();

        cout << "\nEnter LastName: ";
        User.LastName = clsinputvalidate::ReadString();

        cout << "\nEnter Email: ";
        User.Email = clsinputvalidate::ReadString();

        cout << "\nEnter Phone: ";
        User.Phone = clsinputvalidate::ReadString();

        cout << "\nEnter Password: ";
        User.Password = clsinputvalidate::ReadString();

        cout << "\nEnter Permission: ";
        User.Permissions = _readpermissiontoset();
    }
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }
public:
    static void ShowAddNewUserScreen()
    {

        _DrawScreenHeader("\t  Add New User Screen");
        string UserName = "";

        cout << "\nPlease Enter UserName: ";
        UserName = clsinputvalidate::ReadString();
        while (clsUser::IsUserExist(UserName))
        {
            cout << "\nUserName Is Already Used, Choose another one: ";
            UserName = clsinputvalidate::ReadString();
        }

        clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

        _ReadUserInfo(NewUser);

        clsUser::enSaveResults SaveResult;

        SaveResult = NewUser.Save();

        switch (SaveResult)
        {
        case  clsUser::enSaveResults::svSucceeded:
        {
            cout << "\nUser Addeded Successfully :-)\n";
            _PrintUser(NewUser);
            break;
        }
        case clsUser::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError User was not saved because it's Empty";
            break;

        }
        case clsUser::enSaveResults::svFaildUserExists:
        {
            cout << "\nError User was not saved because UserName is used!\n";
            break;

        }
        }
    }


};

