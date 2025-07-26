#pragma once
#include <iostream>
#include<iomanip>
#include "clsbankclient.h"
#include "clsinputvalidate.h"
#include "clsUtil.h"
#include "clsUser.h"
#include "Global.h"
#include "ClsDate.h"
using namespace std;
class clsScreen
{
protected:
	static void _DrawScreenHeader(string title, string subtitle = "") {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << title;
        if (subtitle != "")
        {
            cout << "\n\t\t\t\t\t  " << subtitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        cout << "\t\t\t\t\t User: " << currentuser.UserName;
        cout << "\n\t\t\t\t\t Date: "<<clsDate::datetostring(clsDate())<< "\n";
    }

    static bool CheckAccessRights(clsUser::enpermissions Permission)
    {
        if (!currentuser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }
    }
};

