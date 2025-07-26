#pragma once
#include<iostream>
#include "clsinputvalidate.h"
#include "clsbankclient.h"
#include "clsScreen.h"
using namespace std;
class clsTransferLogScreen:clsScreen
{
private:
    static void PrintTransferLogRecordLine(clsbankclient::sttransferrecord TransferLogRecord)
    {
        cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLogRecord.datetime;
        cout << "| " << setw(8) << left << TransferLogRecord.transferfrom;
        cout << "| " << setw(8) << left << TransferLogRecord.transferto;
        cout << "| " << setw(8) << left << TransferLogRecord.transferamount;
        cout << "| " << setw(10) << left << TransferLogRecord.accbalancetransfrom;
        cout << "| " << setw(10) << left << TransferLogRecord.accbalancetransto;
        cout << "| " << setw(8) << left << TransferLogRecord.Username;
    }

public:
    static void ShowTransferLogScreen() {
        vector<clsbankclient::sttransferrecord>vtl = clsbankclient::gettransferlogfromfile();
        string Title = "\tTransfer Log List Screen";
        string SubTitle = "\t    (" + to_string(vtl.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        if (vtl.size() == 0) {
            cout << "\t\t\t\tNo Transfers Available In the System!";
        }
        else {
            for (clsbankclient::sttransferrecord str : vtl) {
                PrintTransferLogRecordLine(str);
                cout << endl;
            }
        }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }
};

