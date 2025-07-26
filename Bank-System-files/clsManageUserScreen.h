#pragma once
#include<iostream>
#include<string>
#include "clsinputvalidate.h"
#include "clsScreen.h"
#include "clsbankclient.h"
#include "clsListUserScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
using namespace std;
class clsManageUserScreen:protected clsScreen
{
private:
	enum enmanageusermenuoption {
		elistuser=1,
		eaddnewuser=2,
		edeleteuser=3,
		eupdateuser=4,
		efinduser=5,
		emainmenu=6
	};
    static short ReadManageUsersMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsinputvalidate::ReadNumberBetween<short>(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static void _GoBackToManageUsersMenue()
    {
        cout << "\n\nPress any key to go back to Manage Users Menue...";
        system("pause>0");
        ShowManageUsersMenue();
    }

    static void _ShowListUsersScreen()
    {
        clsListUserScreen::ShowUserList();

    }

    static void _ShowAddNewUserScreen()
    {
        clsAddNewUserScreen::ShowAddNewUserScreen();

    }

    static void _ShowDeleteUserScreen()
    {
        clsDeleteUserScreen::ShowDeleteUserScreen();

    }

    static void _ShowUpdateUserScreen()
    {
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }

    static void _ShowFindUserScreen()
    {
        clsFindUserScreen::ShowFindUserScreen();
    }


    static void _PerformManageUsersMenueOption(enmanageusermenuoption ManageUsersMenueOption)
    {

        switch (ManageUsersMenueOption)
        {
        case enmanageusermenuoption::elistuser:
        {
            system("cls");
            _ShowListUsersScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enmanageusermenuoption::eaddnewuser:
        {
            system("cls");
            _ShowAddNewUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enmanageusermenuoption::edeleteuser:
        {
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enmanageusermenuoption::eupdateuser:
        {
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enmanageusermenuoption::efinduser:
        {
            system("cls");

            _ShowFindUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enmanageusermenuoption::emainmenu:
        {
            //do nothing here the main screen will handle it :-) ;
        }
        }

    }   
public:
    static void ShowManageUsersMenue()
    {
        system("cls");
        if (!CheckAccessRights(clsUser::enpermissions::emanageusers)) {
            return;
        }
        _DrawScreenHeader("\t Manage Users Screen");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerformManageUsersMenueOption((enmanageusermenuoption)ReadManageUsersMenueOption());
    }
};

