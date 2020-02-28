#pragma once
#include<string>
#include"date.h"
#include<map>
#include<set>
#include"node.h"
#include<functional>
#include<utility>

using namespace std;

class Database
{
public:
	void Add(Date date, string event);

	void Print(ostream& os) const;

	pair<Date,string> Last(Date date) const;

	map<Date, vector<string>> FindIf(function<bool(Date, string)> func) const;

	string FindLast(function<bool(Date, string)> func) const;

	int RemoveIf(function<bool(Date, string)> func);

protected:
	map<Date, set<string>> set_base;
	map<Date, vector<string>> v_base;
};

ostream& operator << (ostream& os, const pair<const Date, vector<string>>& d_e);
ostream& operator << (ostream& os, const pair<const Date, string>& d_e);