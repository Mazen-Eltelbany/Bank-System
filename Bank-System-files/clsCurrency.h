#pragma once
#include <iostream>
#include<string>
#include "clsString.h"
#include<vector>
#include<fstream>
class clsCurrency
{
private:
	enum enmode {
		Emptymode = 0,
		Updatemode=1
	};
	enmode _Mode;
	string _Country;
	string _CurrencyCode;
	 string _CurrencyName;
	float _Rate=0;
	static clsCurrency _Converlinetocurrencyobject(string line,string sep="#//#") {
		vector<string>vcurrency = clsString::split(line, sep);
		if (vcurrency.size() >= 4) {
			return clsCurrency(enmode::Updatemode,
				vcurrency[0], vcurrency[1], vcurrency[2], stod(vcurrency[3]));
		}

	}

	static string _ConverCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
	{

		string stCurrencyRecord = "";
		stCurrencyRecord += Currency.Country() + Seperator;
		stCurrencyRecord += Currency.CurrencyCode() + Seperator;
		stCurrencyRecord += Currency.CurrencyName() + Seperator;
		stCurrencyRecord += to_string(Currency.Rate());

		return stCurrencyRecord;

	}
	static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrencys)
	{

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsCurrency C : vCurrencys)
			{
				DataLine = _ConverCurrencyObjectToLine(C);
				MyFile << DataLine << endl;
			}

			MyFile.close();

		}

	}


	static vector <clsCurrency>_LoadCurrencyDataFromFile() {
		vector<clsCurrency>vcurrency;
		fstream file;
		file.open("Currencies.txt", ios::in);
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				clsCurrency currency = _Converlinetocurrencyobject(line);
				vcurrency.push_back(currency);
			}
			file.close();
		}
		return vcurrency;
	}
	 void _Update() {
		vector<clsCurrency>_vcurrency;
		_vcurrency = _LoadCurrencyDataFromFile();
		for (clsCurrency& c : _vcurrency) {
			if (c.CurrencyCode() == CurrencyCode()) {
				c = *this;
				break;
			}

		}
		_SaveCurrencyDataToFile(_vcurrency);
	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enmode::Emptymode, "", "", "", 0);
	}

public:
	clsCurrency(enmode mode,string Country,string Currencycode,string Currencyname,float rate) {
		_Mode = mode;
		_Country = Country;
		_CurrencyCode = Currencycode;
		_CurrencyName = Currencyname;
		_Rate = rate;
	}

	bool IsEmpty() {
		return _Mode == enmode::Emptymode;
	}
	 string Country() {
		return _Country;
	}
	 string CurrencyCode() {
		return _CurrencyCode;
	}
	string CurrencyName() {
		return _CurrencyName;
	}
	 void UpdateRate(float NewRate) {
		_Rate = NewRate;
		_Update();
	}
	float Rate() {
		return _Rate;
	}
	static clsCurrency FindbyCode(string Currencycode) {
		Currencycode = clsString::upperallstring(Currencycode);
		fstream file;
		file.open("Currencies.txt", ios::in);
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				clsCurrency currency = _Converlinetocurrencyobject(line);
				if (currency.CurrencyCode() == Currencycode) {
					file.close();
					return currency;
				}
			}
		}
		return _GetEmptyCurrencyObject();
	}
	static clsCurrency FindbyCountry(string Country) {
		Country = clsString::upperallstring(Country);
		fstream file;
		file.open("Currencies.txt", ios::in);
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				clsCurrency currency = _Converlinetocurrencyobject(line);
				if (clsString::upperallstring( currency.Country()) == Country) {
					file.close();
					return currency;
				}
			}
		}
		return _GetEmptyCurrencyObject();
	}
	static bool IsCurrencyExist(string CurrencyCode) {
		clsCurrency c1 = clsCurrency::FindbyCode(CurrencyCode);
		return !(c1.IsEmpty());
	}
	static vector<clsCurrency>GetCurrencyList() {
		return _LoadCurrencyDataFromFile();
	}
	 float convertcurrencytousd(float amount) {
		return (float)amount /Rate();
	}
	 float convertcurrency(clsCurrency currencycodeto,float amount) { 
		float amountInUSD = convertcurrencytousd(amount);
		if (currencycodeto.CurrencyCode() == "USD") {
			return amountInUSD;
		}

			return(float)(amountInUSD*currencycodeto.Rate()); // Return as int
		}
};

