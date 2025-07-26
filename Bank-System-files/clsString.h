#pragma once
#include<iostream>
#include<vector>
using namespace std;
class clsString {
private:
    string _value;
public:
    clsString() {};
    clsString(string value) {
        _value = value;
    }
    void setvalue(string value) {
        _value = value;
    }
    string getvalue() {
        return _value;
    }
    __declspec(property(get = getvalue, put = setvalue)) string value;
    static short CountWords(string S1)
    {

        string delim = " ";
        short Counter = 0;
        short pos = 0;
        string sWord;
        while ((pos = S1.find(delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos);
            if (sWord != "")
            {
                Counter++;
            }
            S1.erase(0, pos + delim.length());
        }
        if (S1 != "")
        {
            Counter++;
        }
        return Counter;
    }
    short CountWords() {
        return CountWords(_value);
    }
    static string lowerallstring(string s) {
        for (int i = 0; i < s.length(); i++) {
            s[i] = tolower(s[i]);
        }
        return s;
    }
    string lowerallstring() {
        return lowerallstring(_value);
    }
    static string upperallstring(string s) {
        for (int i = 0; i < s.length(); i++) {
            s[i] = toupper(s[i]);
        }
        return s;
    }
    string upperallstring() {
        return upperallstring(_value);
    }
    static char invertchar(char& c) {
        return isupper(c) ? tolower(c) : toupper(c);
    }
    static string inverallstring(string& s) {
        for (int i = 0; i < s.length(); i++) {
            s[i] = invertchar(s[i]);
        }
        return s;
    }
    string inverallstring() {
        return inverallstring(_value);
    }
   static int countcapitalletter(string& s) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (isupper(s[i])) {
                count++;
            }
        }
        return count;
    }
    int countcapitalletter() {
        return countcapitalletter(_value);
    }
    static int countlowerletter(string& s) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (islower(s[i])) {
                count++;
            }
        }
        return count;
    }
    int countlowerletter() {
        return countlowerletter(_value);
    }
   static int countspacificletter(string& s, char& c) {
        short count = 0;
        for (short i = 0; i < s.length(); i++) {
            if (s[i] == c) {
                count++;
            }
        }
        return count;
    }
    int countspacificletter(char& c) {
        return countspacificletter(_value, c);
    }
    static int countsmallandlargeletters(string& s, char& c) {
        int count = 0;
        for (short i = 0; i < s.length(); i++) {
            if (s[i] == c || s[i] == toupper(c)) {
                count++;
            }
        }
        return count;
    }
    int countsmallandlargeletters(char& c) {
        return countsmallandlargeletters(_value, c);
    }
    static vector<string>split(string line,string delm="#//#") {
        vector<string>vs;
        string word = " ";
        int pos;
        while ((pos = line.find(delm)) != string::npos) {
            word = line.substr(0, pos);
            if (word != "") {
                vs.push_back(word);
            }
            line.erase(0, pos + delm.length());
        }
        if (line != "") {
            vs.push_back(line);
        }
        return vs;
    }
   vector<string>split(string delm) {
        return split(_value, delm);
    }
    static string trimleft(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i]!= ' ') {
                return s.substr(i, s.length() - 1);
            }
        }
        return "";
    }
    string trimleft() {
        return trimleft(_value);
    }
    static string trimright(string s) {
        for (int i = s.length() - 1; i > 0; i--) {
            if (s[i] != ' ') {
                return s.substr(0, i + 1);
            }
        }
        return "";
    }
    string trimright() {
        return trimright(_value);
    }
    static string trim(string s) {
        return (trimleft(trimright(s)));
    }
    string trim() {
        return trim(_value);
    }
    string revwordinstring(string s) {
        vector <string> vstr;
        string s2 = "";
        vstr = split(s, " ");
        vector <string>::iterator itr = vstr.end();
        while (itr != vstr.begin()) {
            --itr;
            s2 += *itr + " ";
        }
        s2 = s2.substr(0, s2.length() - 1);
        return s2;
    }
    string revwordinstring() {
        return revwordinstring(_value);
    }
    static string joinvectorstring(vector <string>vstr, string delm) {
        string s = "";
        for (string& g : vstr)
        {
            s = s + g + delm;
        }
        cout << delm.length();
        return s.substr(0, s.length() - delm.length());
    }
    static string joinarraystring(string arr[], short len, string delm) {
        string s = "";
        for (int i = 0; i < len; i++) {
            s = s + arr[i] + delm;
        }
        return s.substr(0, s.length() - delm.length());
    }
    static string replacewordinstring(string s, string s1, string s2) {
        int pos = s.find(s1);
        while (pos != string::npos) {
            s = s.replace(pos, s1.length(), s2);
            pos = s.find(s1);
        }
        return s;
    }
    string replacewordinstring (string wordtoreplace, string wordreplacefor) {
        return replacewordinstring(_value, wordtoreplace, wordreplacefor);
    }
   static string replacewordinstringusingsplit(string s1, string s2, string s3, bool matchcase = true) {
        vector <string>vstr;
        vstr = split(s1, " ");
        for (string& s : vstr) {
            if (matchcase) {
                if (s == s2) {
                    s = s3;
                }
            }
            else {
                if (lowerallstring(s) ==
                    lowerallstring(s2)) {
                    s = s3;
                }
            }

        }
        return joinvectorstring(vstr, " ");
    }
    string replacewordinstringusingsplit(string wordtoreplace, string wordreplacefor, bool matchcase = true) {
        return  replacewordinstringusingsplit(_value, wordtoreplace, wordreplacefor, matchcase = true);
    }
    static string removepunctution(string s) {
        string s2 = "";
        for (int i = 0; i < s.length(); i++) {
            if (!ispunct(s[i])) {
                s2 += s[i];
            }
        }
        return s2;
    }
    string removepunctution() {
        return removepunctution(_value);
    }
    static bool isallstringdigit(string s) {
        int countdigit = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                countdigit++;
            }
        }
        if (countdigit == s.length()) {
            return true;
        }
        return false;
    }
    bool isallstringdigit() {
        return isallstringdigit(_value);
    }
    static bool isstringcontaindigit(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                return true;
            }
        }
        return false;
    }
    bool isstringcontaindigit() {
        return isstringcontaindigit(_value);
    }
};

