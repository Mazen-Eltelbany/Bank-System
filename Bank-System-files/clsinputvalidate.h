#pragma once
#include <iostream>
#include "ClsDate.h"
#include "clsUtil.h"
#include "clsinputvalidate.h"
#include "clsString.h"
using namespace std;
class clsinputvalidate
{
public:
	 template<typename t>static t IsNumberBetween(t num,t from,t to) {
		return(num >= from && num  <= to);
	}
	static bool IsDateBetween(clsDate date, clsDate datefrom, clsDate dateto) {
		if (clsDate::IsDate1BeforeDate2(dateto, datefrom)) {
			clsDate::swapdates(datefrom, dateto);
		}
		if ((clsDate::IsDate1BeforeDate2(date, dateto)||clsDate::isdate1equaldate2(date,dateto))
			&& (clsDate::isdate1afterdate2(date, datefrom)||clsDate::isdate1equaldate2(date,datefrom))) {
			return true;
		}
		return false;
	}
	template<typename t>static t ReadNumber(string errormessage= "Invalid Number, Enter again\n") {
		t x;
		while (!(cin>>x)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << errormessage;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return x;	 
	}
	template <typename t> static t ReadNumberBetween(t from,t to,string errormessage= "Number is not within range\n") {
		int num=0;
		num = ReadNumber<t>();
		while (!IsNumberBetween<t>(num, from, to)) {
			cout << errormessage << endl;
			num = ReadNumber<t>();
		}
		return num;
	}
	static bool IsValidDate(clsDate date) {
		return clsDate::isvalid(date);
	}
	static string ReadString() {
		string s1 = "";
		getline(cin >> ws, s1);
		return s1;
	}
};

 