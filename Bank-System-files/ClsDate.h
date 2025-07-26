#pragma warning(disable : 4996)	
#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
using namespace std;
class clsDate
{
private:
	short _day = 0;
	short _month = 0;
	short _year = 0;
public:
	clsDate() {
		time_t t = time(0);
		tm now;
		localtime_s(&now, &t);
		_day = now.tm_mday;
		_month = now.tm_mon + 1;
		_year = now.tm_year + 1900;
	}
	clsDate(string s) {
		vector<string>vs = clsString::split(s, "/");
		_day = stoi(vs[0]);
		_month = stoi(vs[1]);
		_year = stoi(vs[2]);
	}
	clsDate(int day, int month, int year) {
		_day = day;
		_month = month;
		_year = year;
	}
	clsDate(int daysinorder, int year) {
		int remaningdays = daysinorder;
		short monthsday = 0;
		_year = year;
		_month = 1;
		while (true) {
			monthsday = numofdaysinmonth(_month, year);
			if (remaningdays > monthsday) {
				remaningdays -= monthsday;
				_month++;
			}
			else {
				_day = remaningdays;
				break;
			}
		}
	}
	void setday(int day) {
		_day = day;
	}
	short getday() {
		return _day;
	}
	_declspec(property(get = getday, put = setday))short day;
	void setmonth(int month) {
		_month = month;
	}
	short getmonth() {
		return _month;
	}
	_declspec(property(get = getmonth, put = setmonth))short month;
	void setyear(short year) {
		_year = year;
	}
	short getyear() {
		return _year;
	}
	_declspec(property(get = getyear, put = setyear))short year;
	static bool isleapyear(int year) {
		return ((year % 100 != 0 && year % 4 == 0) || (year % 400 == 0));
	}
	bool isleapyear() {
		return isleapyear(_year);
	}
	static void swapdates(clsDate& date1, clsDate& date2) {
		clsDate temp;
		temp.year = date1.year;
		temp.month = date1.month;
		temp.day = date1.day;

		date1.year = date2.year;
		date1.month = date2.month;
		date1.day = date2.day;

		date2.year = temp.year;
		date2.month = temp.month;
		date2.day = temp.day;


	}
	static clsDate getsystemdate() {
		clsDate date;
		time_t t = time(0);
		tm now;
		localtime_s(&now, &t);
		date.year = now.tm_year + 1900;
		date.month = now.tm_mon + 1;
		date.day = now.tm_mday;
		return date;
	}
	static short dayofweekorder(short year, short month, short day) {
		int a = (14 - month) / 12;
		int y = year - a;
		int m = month + 12 * a - 2;
		return  (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}
	short dayofweekorder() {
		return dayofweekorder(_year, _month, _day);
	}
	static short numofdaysinmonth(short month, short year) {
		if (month < 1 || month>12) {
			return 0;
		}
		if (month == 2) {
			return isleapyear(year) ? 29 : 28;
		}
		int arr31days[7] = { 1,3,5,7,8,10,12 };
		for (int i = 1; i <= 7; i++) {
			if (arr31days[i - 1] == month) {
				return 31;
			}
		}
		return 30;
	}
	short numofdaysinmonth() {
		return numofdaysinmonth(_month, _year);
	}
	static string monthshortname(short monthnum) {
		string month[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep",
			"Oct","Nov","Dec" };
		return month[monthnum - 1];
	}
	string monthshortname() {
		return monthshortname(_month);
	}
	static string datetostring(clsDate date) {
		return to_string(date.day) + "/" + to_string(date.month)
			+ "/" + to_string(date.year);
	}
	string datetostring() {
		return datetostring(*this);
	}
	void print() {
		cout << datetostring() <<endl;
	}
	static void printmonthcalender(short month, short year) {
		int numofdays = numofdaysinmonth(month, year);
		int current = dayofweekorder(year, month, 1);
		printf("\n _______________%s_______________\n\n",
			monthshortname(month).c_str());
		printf(" Sun Mon Tue Wed Thu Fri Sat\n");
		int i = 0;
		for (i = 0; i < current; i++) {
			printf("    ");
		}
		for (int j = 1; j <= numofdays; j++) {
			printf("%4d", j);
			if (++i == 7) {
				i = 0;
				printf("\n");
			}

		}
		printf("\n _________________________________\n");
	}
	void printmonthcalender() {
		printmonthcalender(_month, _year);
	}
	static void printyearcalender(int year) {
		printf("\n _________________________________\n\n");
		printf("        Calender-%d\n", year);
		printf("\n _________________________________\n\n");
		for (int i = 1; i <= 12; i++) {
			printmonthcalender(i, year);
		}
	}
	void printyearcalender() {
		printyearcalender(_year);
	}
	static bool isvalid(clsDate date) {
		if (date.day > numofdaysinmonth(date.month,date.year) || date.day < 1) {
			return false;
		}
		if (date.month < 1 || date.month>12) {
			return false;
		}
		return true;
	}
	bool isvalid() {
		return isvalid(*this);
	}
	static int numofdaysinyear(int year) {
		return isleapyear(year) ? 366 : 365;
	}
	int numofdaysinyear() {
		return numofdaysinyear(_year);
	}
	static int numofhoursinyear(int year) {
		return numofdaysinyear(year) * 24;
	}
	int numofhoursinyear() {
		return numofhoursinyear(_year);
	}
	static int numofminutesinyear(short year) {
		return numofhoursinyear(year) * 60;
	}
	int numofminutesinyear() {
		return numofminutesinyear(_year);
	}
	static int numofsecondsinyear(short year) {
		return numofminutesinyear(year) * 60;
	}
	int numofsecondsinyear() {
		return numofsecondsinyear(_year);
	}
	static short numofhoursinmonth(short month, short year) {
		return numofdaysinmonth(month, year) * 24;
	}
	short numofhoursinmonth() {
		return numofhoursinmonth(_month, _year);
	}
	static int numofminutesinmonth(short month, short year) {
		return numofhoursinmonth(month, year) * 60;
	}
	int numofminutesinmonth() {
		return numofhoursinmonth(_month, _year);
	}
	static int numofsecondsinmonth(short month, short year) {
		return numofminutesinmonth(month, year) * 60;
	}
	int numofsecondsinmonth() {
		return numofminutesinmonth(_month, _year);
	}
	static string Dayshortname(short dayofweekorder) {
		string arr[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
		return arr[dayofweekorder];
	}
	string Dayshortname() {
		return Dayshortname(dayofweekorder(_year, _month, _day));
	}
	static string Dayshortname(short day, short month, short year) {
		string arr[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
		return arr[dayofweekorder(year, month, day)];
	}
	static string Dayname(short day, short month, short year) {
		string arr[] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
		return arr[dayofweekorder(year, month, day)];
	}
	string Dayname() {
		return Dayname(day, month, year);
	}
	static int thedayfrombeganningoftheyear(short Year, short month, short day) {
		int total = 0;
		for (int i = 1; i <= month - 1; i++) {//1,i<=11
			total += numofdaysinmonth(i, Year);
		}
		total += day;
		return total;
	}
	void dateadddays(short days, clsDate date) {
		short remaingdays = days + thedayfrombeganningoftheyear(date.year, date.month, date.day);
		short monthsday = 0;
		date.month = 1;
		while (true) {
			monthsday = numofdaysinmonth(date.month, date.year);
			if (remaingdays > monthsday) {
				remaingdays -= monthsday;
				date.month++;
				if (date.month > 12) {
					date.month = 1;
					date.year++;
				}
			}

			else {
				date.day = remaingdays;
				break;
			}
		}
	}
	void dateadddays(short days) {
		dateadddays(days, *this);
	}
	static clsDate datefromdayorderinyear(short daysinorder, short year) {
		clsDate date;
		short remaindays = daysinorder;
		short monthsday = 0;
		date.year = year;
		date.month = 1;
		while (true) {
			monthsday = numofdaysinmonth(date.month, year);
			if (remaindays > monthsday) {
				remaindays -= monthsday;
				date.month++;
			}
			else {
				date.day = remaindays;
				break;
			}
		}
		return date;
	}
	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1.year < Date2.year) ? true : ((Date1.year ==
			Date2.year) ? (Date1.month < Date2.month ? true : (Date1.month ==
				Date2.month ? Date1.day < Date2.day : false)) : false);
	}
	bool IsDate1BeforeDate2(clsDate Date2) {
		return IsDate1BeforeDate2(*this, Date2);
	}
	static bool islastdayinmonth(clsDate date) {
		short monthsday = numofdaysinmonth(date.month, date.year);
		if (monthsday == date.day) {
			return true;
		}
		return false;
	}
	bool islastdayinmonth() {
		return islastdayinmonth(*this);
	}
	static bool islastmonthinyear(short month) {
		return (month == 12);
	}
	bool islastmonthinyear() {
		return islastmonthinyear(month);
	}
	static clsDate increasedatebyoneday(clsDate& date) {
		if (islastdayinmonth(date)) {
			if (islastmonthinyear(date.month)) {
				date.year++;
				date.day = 1;
				date.month = 1;
			}
			else {
				date.month++;
				date.day = 1;
			}
		}
		else {
			date.day++;
		}
		return date;
	}
	void increasedatebyoneday() {
		increasedatebyoneday(*this);
	}
	static int getdiffindays(clsDate date1, clsDate date2, bool includelast = false) {
		int days = 0;
		int swapflag = 1;
		if (!IsDate1BeforeDate2(date1, date2)) {
			swapdates(date1, date2);
			swapflag = -1;
		}
		while (IsDate1BeforeDate2(date1, date2)) {
			days++;
			date1 = increasedatebyoneday(date1);
		}
		return includelast ? ++days * swapflag : days * swapflag;
	}
	int getdiffindays(clsDate date2, bool includelast = false) {
		return getdiffindays(*this, date2, includelast);
	}
	static short calculatemyageindays(clsDate datebrith) {
		return getdiffindays(datebrith,
			clsDate::getsystemdate(), true);
	}
	static clsDate increasedatebyxdays(short days, clsDate& date) {
		for (int i = 0; i < days; i++) {
			date = increasedatebyoneday(date);
		}
		return date;
	}
	void increasedatebyxdays(short day) {
		increasedatebyxdays(day, *this);
	}
	static clsDate increasedatebyoneweek(clsDate& date) {
		for (int i = 0; i < 7; i++) {
			date = increasedatebyoneday(date);
		}
		return date;
	}
	void increasedatebyoneweek() {
		increasedatebyoneweek(*this);
	}
	static clsDate increasedatebyxweek(clsDate& date, short weeks) {
		for (int i = 0; i < weeks; i++)
		{
			date = increasedatebyoneweek(date);
		}
		return date;
	}
	void increasedatebyxweek(short weeks) {
		increasedatebyxweek(*this, weeks);
	}
	static clsDate increasedatebyonemonth(clsDate& date) {
		if (date.month == 12) {
			date.month = 1;
			date.year++;
		}
		else {
			date.month++;
		}
		short numofdayinmonth = numofdaysinmonth(date.month, date.year);
		if (date.day > numofdayinmonth) {
			date.day = numofdayinmonth;
		}
		return date;
	}
	void increasedatebyonemonth() {
		increasedatebyonemonth(*this);
	}
	static clsDate increasedatebyxmonth(clsDate& date, short months) {
		for (int i = 0; i < months; i++) {
			date = increasedatebyonemonth(date);
		}
		return date;
	}
	void increasedatebyxmonth(short months) {
		increasedatebyxmonth(*this, months);
	}
	static clsDate increasedatebyoneyear(clsDate& date) {
		date.year++;
		return date;
	}
	void increasedatebyoneyear() {
		increasedatebyoneyear(*this);
	}
	static clsDate increasedatebyxyear(clsDate& date, short years) {
		for (int i = 0; i < years; i++) {
			date = increasedatebyoneyear(date);
		}
		return date;
	}
	void increasedatebyxyear(short years) {
		increasedatebyxyear(*this, years);
	}
	static clsDate increasedatebyxyearfaster(clsDate& date, short years) {
		date.year += years;
		return date;
	}
	void increasedatebyxyearfaster(short years) {
		increasedatebyxyearfaster(*this, years);
	}
	clsDate increasedatebyonedecade(clsDate& date) {
		date.year += 10;
		return date;
	}
	void increasedatebyonedecade() {
		increasedatebyonedecade(*this);
	}
	static clsDate increasedatebyxdecadefaster(clsDate& date, short decads) {
		date.year += decads * 10;
		return date;
	}
	void increasedatebyxdecadefaster(short decads) {
		increasedatebyxdecadefaster(*this, decads);
	}
	static clsDate increasedatebyonecentury(clsDate& date) {
		date.year += 100;
		return date;
	}
	void increasedatebyonecentury() {
		increasedatebyonecentury(*this);
	}
	static clsDate increasedatebyxcentury(clsDate& date, int centuries) {
		date.year += 100 * centuries;
		return date;
	}
	void increasedatebyxcentury(int centuries) {
		increasedatebyxcentury(*this, centuries);
	}
	static clsDate increasedatebyonemillennium(clsDate& date) {
		date.year += 1000;
		return date;
	}
	void increasedatebyonemillennium() {
		increasedatebyonemillennium(*this);
	}
	static clsDate decreasedatebyoneday(clsDate& date) {
		if (date.day == 1) {
			if (date.month == 1) {
				date.year--;
				date.month = 12;
				date.day = 31;
			}
			else {
				date.month--;
				date.day = numofdaysinmonth(date.month, date.year);
			}
		}
		else {
			date.day--;
		}
		return date;
	}
	void decreasedatebyoneday() {
		decreasedatebyoneday(*this);
	}
	static clsDate decreasedatebyxdays(short days, clsDate& date) {
		for (int i = 0; i < days; i++) {
			date = decreasedatebyoneday(date);
		}
		return date;
	}
	void decreasedatebyxdays(short days) {
		decreasedatebyxdays(days, *this);
	}
	static clsDate decreasedatebyoneweek(clsDate& date) {
		for (int i = 0; i < 7; i++) {
			date = decreasedatebyoneday(date);
		}
		return date;
	}
	void decreasedatebyoneweek() {
		decreasedatebyoneweek(*this);
	}
	static clsDate decreasedatebyxweek(clsDate& date, short weeks) {
		for (int i = 0; i < weeks; i++)
		{
			date = decreasedatebyoneweek(date);
		}
		return date;
	}
	void decreasedatebyxweek(short weeks) {
		decreasedatebyxweek(*this, weeks);
	}
	static clsDate decreasedatebyonemonth(clsDate& date) {
		if (date.month == 1) {
			date.month = 12;
			date.year--;
		}
		else {
			date.month--;
		}
		short numofdayinmonth = numofdaysinmonth(date.month, date.year);
		if (date.day > numofdayinmonth) {
			date.day = numofdayinmonth;
		}
		return date;
	}
	void decreasedatebyonemonth() {
		decreasedatebyonemonth(*this);
	}
	static clsDate decreasedatebyxmonth(clsDate& date, short months) {
		for (int i = 0; i < months; i++) {
			date = decreasedatebyonemonth(date);
		}
		return date;
	}
	void decreasedatebyxmonth(short months) {
		decreasedatebyxmonth(*this, months);
	}
	static clsDate decreasedatebyoneyear(clsDate& date) {
		date.year--;
		return date;
	}
	void decreasedatebyoneyear() {
		decreasedatebyoneyear(*this);
	}
	static clsDate decreasedatebyxyear(clsDate& date, short years) {
		for (int i = 0; i < years; i++) {
			date = decreasedatebyoneyear(date);
		}
		return date;
	}
	void decreasedatebyxyear(short years) {
		decreasedatebyxyear(*this, years);
	}
	static clsDate decreasedatebyxyearfaster(clsDate& date, short years) {
		date.year -= years;
		return date;
	}
	void decreasedatebyxyearfaster(short years) {
		decreasedatebyxyearfaster(*this, years);
	}
	static clsDate decreasedatebyonedecade(clsDate& date) {
		date.year -= 10;
		return date;
	}
	void decreasedatebyonedecade() {
		decreasedatebyonedecade(*this);
	}
	static clsDate decreasedatebyxdecade(clsDate& date, short decades) {
		for (int i = 0; i < decades * 10; i++) {
			date = decreasedatebyoneyear(date);
		}
		return date;
	}
	void decreasedatebyxdecade(short decades) {
		decreasedatebyxdecade(*this, decades);
	}
	static clsDate decreasedatebyxdecadefaster(clsDate& date, short decads) {
		date.year -= decads * 10;
		return date;
	}
	void decreasedatebyxdecadefaster(short decads) {
		decreasedatebyxdecadefaster(*this, decads);
	}
	static clsDate decreasedatebyonecentury(clsDate& date) {
		date.year -= 100;
		return date;
	}
	void decreasedatebyonecentury() {
		decreasedatebyonecentury(*this);
	}
	static clsDate decreasedatebyonemillennium(clsDate& date) {
		date.year -= 1000;
		return date;
	}
	void decreasedatebyonemillennium() {
		decreasedatebyonemillennium(*this);
	}
	static bool isendofaweek(clsDate date) {
		short dayofweeksorder = dayofweekorder(date.year, date.month, date.day);
		string dayname = Dayshortname(dayofweeksorder);
		return dayname == "Sat";
	}
	bool isendofaweek() {
		return isendofaweek(*this);
	}
	static bool isweekend(clsDate date) {
		return (dayofweekorder(date.year, date.month, date.day) == 6 || dayofweekorder(date.year, date.month, date.day) == 5);
	}
	bool isweekend() {
		return isweekend(*this);
	}
	static bool isbussinessday(clsDate date) {
		return !isweekend(date);
	}
	bool isbussinessday() {
		return isbussinessday(*this);
	}
	static short daysuntiltheendoftheweek(clsDate date) {
		short dayweeksorder = dayofweekorder(date.year, date.month, date.day);
		short ans = 6 - dayweeksorder;
		return ans;
	}
	short daysuntiltheendoftheweek() {
		return daysuntiltheendoftheweek(*this);
	}
	static short daysuntiltheendofthemonth(clsDate date) {
		short monthdays = numofdaysinmonth(date.month, date.year);
		return monthdays - date.day;
	}
	short daysuntiltheendofthemonth() {
		return daysuntiltheendofthemonth(*this);
	}
	static short daysuntiltheendoftheyear(clsDate date) {
		short days = thedayfrombeganningoftheyear(date.year, date.month, date.day);
		return (isleapyear(date.year)) ? 366 - days : 365 - days;
	}
	short daysuntiltheendoftheyear() {
		return daysuntiltheendoftheyear(*this);
	}
	static short calculatebussinessdays(clsDate datefrom, clsDate dateto) {
		short days = 0;
		while (IsDate1BeforeDate2(datefrom, dateto)) {
			if (isbussinessday(datefrom)) {
				days++;
			}
			datefrom = increasedatebyoneday(datefrom);
		}
		return days;
	}
	static short calculatevacationday(clsDate datefrom, clsDate dateto) {
		return calculatebussinessdays(datefrom,dateto);
	}
	static clsDate calculatevacationreturndate(clsDate vactionstart, short vacationdays) {
		short weekendcounter = 0;
		while (isweekend(vactionstart)) {
			vactionstart = increasedatebyoneday(vactionstart);
		}
		for (int i = 1; i < vacationdays + weekendcounter; i++) {
			if (isweekend(vactionstart)) {
				weekendcounter++;
			}
			vactionstart = increasedatebyoneday(vactionstart);
		}
		while (isweekend(vactionstart)) {
			vactionstart = increasedatebyoneday(vactionstart);
		}
		return vactionstart;
	}
	void  calculatevacationreturndate(short vacationdays) {
		calculatevacationreturndate(*this, vacationdays);
	}
	static bool isdate1equaldate2(clsDate date1, clsDate date2) {
		return (date1.year == date2.year) ? ((date1.month == date2.month) ?
			((date1.day == date2.day) ? true : false) : false) : false;
	}
	bool isdate1equaldate2(clsDate date2) {
		return isdate1equaldate2(*this, date2);
	}
	static bool isdate1afterdate2(clsDate date1, clsDate date2) {
		return !IsDate1BeforeDate2(date1, date2) && !isdate1equaldate2(date1, date2);
	}
	bool isdate1afterdate2(clsDate date2) {
		return isdate1afterdate2(*this, date2);
	}
	enum encomp { before = -1, equal, after };
	static encomp comparedates(clsDate date1, clsDate date2) {
		if (IsDate1BeforeDate2(date1, date2)) {
			return encomp::before;
		}
		if (isdate1equaldate2(date1, date2)) {
			return encomp::equal;
		}
		return encomp::after;
	}
	encomp comparedates( clsDate date2) {
		return comparedates(*this, date2);
	}
	static string formatdate(clsDate date, string dateformat = "dd/mm/yyyy") {
		string formatteddates = "";
		formatteddates = clsString::replacewordinstring(dateformat, "dd", to_string(date.day));
		formatteddates = clsString::replacewordinstring(formatteddates, "mm", to_string(date.month));
		formatteddates = clsString::replacewordinstring(formatteddates, "yyyy", to_string(date.year));
		return formatteddates;
	}
	string formatdate(string dateformat = "dd/mm/yyyy") {
		return formatdate(*this, dateformat);
	}
	static string thedayyoubrithname(clsDate datebrith) {
		string dayyoubrith = Dayname(datebrith.day, datebrith.month, datebrith.year);
		return dayyoubrith;
	}
	string thedayyoubrithname() {
		return thedayyoubrithname(*this);
	}
	static string GetSystemDatetimestring() {
		time_t t = time(0);
		tm now;
		localtime_s(&now,&t);
		short Day, Month, Year, hour, minute, seconds;
		Year = now.tm_year + 1900;
		Month = now.tm_mon + 1;
		Day = now.tm_mday;
		hour = now.tm_hour;	
		minute = now.tm_min;
		seconds = now.tm_sec;
		return (to_string(Day) + "/" + to_string(Month) + "/"+
			to_string(Year)+" - " + to_string(hour) + ":" +
			to_string(minute)+":"+to_string(seconds));
	}
};

