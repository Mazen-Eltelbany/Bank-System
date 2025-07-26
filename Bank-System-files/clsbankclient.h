#pragma once
#include<iostream>
#include<string>
#include "clsPerson.h"
#include "clsString.h"
#include "clsinputvalidate.h"
#include<fstream>
#include<vector>
using namespace std;
class clsbankclient :public clsPerson
{
private:
	enum enMode { Emptymode = 0, updatemode = 1,addnewmode=2};
	enMode _mode;
	string _accountnumber;
	string _pincode;
	float _accountbalance;
	bool _markedfordelete=false;
	static clsbankclient _convertlinetoclientobject(string line, string seprator = "#//#") {
		vector<string>vs = clsString::split(line, seprator);
		if (vs.size() >= 7) {
			return (clsbankclient(enMode::updatemode, vs[0], vs[1], vs[2],
				vs[3], vs[4], vs[5], stod(vs[6])));
		}

	}
	static string _convertclientobjecttoline(clsbankclient client, string sep = "#//#") {
		string s="";
		s += client.FirstName + sep;
		s += client.LastName + sep;
		s += client.Email + sep;
		s += client.Phone + sep;
		s += client.Accountnumber() + sep;
		s += client.pincode+ sep;
		s += to_string(client.AccountBalance) + sep;
		return s;
	}
	static vector<clsbankclient>_loadclientsfromfile() {
		vector<clsbankclient>vc;
		fstream file;
		file.open("Clients.txt", ios::in);
		if (file.is_open()) {
			string line = "";
			while (getline(file, line)) {
				clsbankclient cl = _convertlinetoclientobject(line);
				vc.push_back(cl);
			}
			file.close();
		}
		return vc;
	}
	static clsbankclient _getemptyclientobject() {
		return clsbankclient(enMode::Emptymode, "", "", "", "", "", "", 0);
	}
	static void _saveclientsdatatofile(vector<clsbankclient>vc) {
		fstream file;
		file.open("Clients.txt", ios::out);
		string dataline;
		if (file.is_open()) {
			for (clsbankclient c : vc) {
				if (!c._markedfordelete) {
					dataline = _convertclientobjecttoline(c);
					file << dataline << endl;
				}
			}
			file.close();
		}
	}
	void _Update() {
		vector<clsbankclient>_vc = _loadclientsfromfile();
		for (clsbankclient& c : _vc) {
			if (c.Accountnumber() == Accountnumber()) {
				c = *this;
				break;
			}
		}
		_saveclientsdatatofile(_vc);
	}
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
	void _AddDataLineToFile(string stdataline) {
		fstream file;
		file.open("Clients.txt", ios::out | ios::app);
		if (file.is_open()) {
			file << stdataline << endl;
			file.close();
		}
	}
	void _AddNew() {
		_AddDataLineToFile(_convertclientobjecttoline(*this));
	}
	string _PrepareTransferRecord(float amount,clsbankclient destinationclient,string Username,string sep="#//#") {
		string s;
		s += clsDate::GetSystemDatetimestring() + sep;
		s += Accountnumber() + sep;
		s += destinationclient.Accountnumber() + sep;
		s += to_string(amount) + sep;
		s += to_string(AccountBalance) + sep;
		s += to_string(AccountBalance) + sep;
		s += Username;
		return s;
	}
	void _RegisterTransferlog(float amount,clsbankclient destinationclient,string Username) {
		string stdataline = _PrepareTransferRecord(amount, destinationclient, Username);
		fstream file;
		file.open("TransferLog.txt",ios::out|ios::app);
		if (file.is_open()) {
			file << stdataline << endl;
			file.close();
		}
	}
	struct sttransferrecord;

	static sttransferrecord _ConverlinetoTransferrecord(string line, string sep = "#//#") {
		sttransferrecord transfer;
		vector<string>transferrecord=clsString::split(line,sep);
		if (transferrecord.size() >= 7) {
			transfer.datetime = transferrecord[0];
			transfer.transferfrom = transferrecord[1];
			transfer.transferto = transferrecord[2];
			transfer.transferamount = stoi(transferrecord[3]);
			transfer.accbalancetransfrom = stoi(transferrecord[4]);
			transfer.accbalancetransto = stoi(transferrecord[5]);
			transfer.Username = transferrecord[6];
		}
		return transfer;

	}
	static vector<sttransferrecord> _loadTransferlogfromfile() {
		vector<sttransferrecord>vtl;
		fstream file("TransferLog.txt", ios::in);
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				sttransferrecord tr = _ConverlinetoTransferrecord(line);
				vtl.push_back(tr);
			}
			file.close();
		}
		return vtl;
	}
public:
	clsbankclient(enMode mode, string firstname, string lastname,
		string email, string phone, string accountnumber,
		string pincode, float accounbalance) :
		clsPerson(firstname, lastname, email, phone) {
		_mode = mode;
		_accountnumber = accountnumber;
		_pincode = pincode;
		_accountbalance = accounbalance;
	}
	struct sttransferrecord {
		string datetime = "";
		string transferfrom = "";
		string transferto = "";
		double transferamount = 0;
		double accbalancetransfrom = 0;
		double accbalancetransto = 0;
		string Username = "";
	};
	bool isEmpty() {
		return(_mode == enMode::Emptymode);
	}
	string Accountnumber() {
		return _accountnumber;
	}
	void setpincode(string pincode) {
		_pincode = pincode;
	}
	string getpincode() {
		return _pincode;
	}
	__declspec(property(get = getpincode, put = setpincode))string pincode;
	void setAccountBalance(float accountbalance) {
		_accountbalance = accountbalance;
	}
	float getAccountBalance() {
		return _accountbalance;
	}
	_declspec(property(get = getAccountBalance, put = setAccountBalance))float AccountBalance;
	void print() {
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName  : " << FirstName;
		cout << "\nLastName   : " << LastName;
		cout << "\nFull Name  : " << FullName();
		cout << "\nEmail      : " << Email;
		cout << "\nPhone      : " << Phone;
		cout << "\nAcc. Number: " << _accountnumber;
		cout << "\nPassword   : " << _pincode;
		cout << "\nBalance    : " << _accountbalance;
		cout << "\n___________________\n";
	}
	static clsbankclient Find(string AccountNumber) {
		vector<clsbankclient>vc;
		fstream file;
		file.open("Clients.txt", ios::in);
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				clsbankclient client = _convertlinetoclientobject(line);
				if (client.Accountnumber() == AccountNumber) {
					file.close();
					return client;
				}
				vc.push_back(client);
			}
			file.close();
		}
		return _getemptyclientobject();
	}
	static clsbankclient Find(string AccountNumber,string pincode) {
		vector<clsbankclient>vc;
		fstream file;
		file.open("Clients.txt", ios::in);
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				clsbankclient client = _convertlinetoclientobject(line);
				if (client.Accountnumber() == AccountNumber&&client.pincode==pincode) {
					file.close();
					return client;
				}
				vc.push_back(client);
			}
			file.close();
		}
		return _getemptyclientobject();
	}
	static bool IsClientExist(string AccountNumber) {
		clsbankclient client = Find(AccountNumber);
		return !(client.isEmpty());
	}
	enum ensaveresult{svfailedemptyobject=0,svsucceeded=1,svfailedaccountnumexist=2};
	ensaveresult save() {
	switch (_mode) {
	case enMode::Emptymode:
	{
		if (isEmpty()) {
			return ensaveresult::svfailedemptyobject;
		}
	}
	case enMode::updatemode:
	{
		_Update();
		return ensaveresult::svsucceeded;
		break;
	}
	case enMode::addnewmode:
		if (clsbankclient::IsClientExist(_accountnumber)) {
			return ensaveresult::svfailedaccountnumexist;
		}
		else {
			_AddNew();
			_mode = enMode::updatemode;
			return ensaveresult::svsucceeded;
		}

		}
	}
	void UpdateClient() {
		string AccountNumber = "";
		cout << "\nPlease Enter Client Account Number: ";
		AccountNumber =  clsinputvalidate::ReadString();
		while (!IsClientExist(AccountNumber)) {
			cout << "Account Number is not found,Choose Another One: ";
			AccountNumber = clsinputvalidate::ReadString();
		}
		clsbankclient client1 = clsbankclient::Find(AccountNumber);
		client1.print();
		cout << "\n\nUpdate Client Info:";
		cout << "\n---------------------\n";
		_ReadClientInfo(client1);
		clsbankclient::ensaveresult saveresult;
		saveresult = client1.save();
		switch (saveresult) {
		case ensaveresult::svsucceeded:
			cout << "\nAccount Updated Successfully :-)\n";
			client1.print();
			break;
		case ensaveresult::svfailedemptyobject:
			cout << "\nError account was not saved because it's Empty";
			break;
		}
	}
	static clsbankclient GetAddNewClientObject(string accnum) {
		return clsbankclient(enMode::addnewmode, "", "", "", "", accnum, "",0);
	}
	bool Delete() {
		vector<clsbankclient>_vc;
		_vc = _loadclientsfromfile();
		for (clsbankclient& c : _vc) {
			if (c.Accountnumber() == _accountnumber) {
				c._markedfordelete = true;
				break;
			}
		}
		_saveclientsdatatofile(_vc);
		*this = _getemptyclientobject();
		return true;
	}
	static vector<clsbankclient> getclientlist() {
		return _loadclientsfromfile();
	}
	static double gettotalbalances() {
		vector<clsbankclient>vclients = getclientlist();
		double total = 0;
		for (clsbankclient client : vclients) {
			total += client.AccountBalance;
		}
		return total;
	}
	void Deposit(double amount) {
		_accountbalance += amount;
		save();
	}
	bool Withdraw(double amount) {
		if (amount > _accountbalance) {
			return false;
		}
		else {
			_accountbalance -= amount;
			save();
		}
	}
	bool Transfer(double amount, clsbankclient& destinationclient,string username) {
		if (amount > AccountBalance) {
			return false;
		}
		Withdraw(amount);
		destinationclient.Deposit(amount);
		_RegisterTransferlog(amount, destinationclient, username);

		return true;
	}
	static vector<sttransferrecord>gettransferlogfromfile() {
		return _loadTransferlogfromfile();
	}
};

