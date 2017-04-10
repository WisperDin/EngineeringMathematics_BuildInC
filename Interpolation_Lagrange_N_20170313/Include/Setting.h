#pragma once
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;
class Setting
{
public:
	Setting(string filename = "./setting.txt")
	{
		ifstream fin(filename);
		if (!fin)
		{
			cerr << "setting dosen't exist" << endl;
		}
		//char str[LINE_LENGTH];

		string str;
		while (!fin.eof())
		{
			getline(fin, str);
			//×¢ÊÍ
			if (str[0] == '#')
			{
				continue;
			}
			int pos = str.find("=");
			if (pos == -1)
				continue;
			string key = str.substr(0, pos);
			string value = str.substr(pos+1, str.length());
			data[key] = value;

			if (!fin.good())
			{
				break;
			}
		}
	}
	string getData(string key)
	{
		map<string, string>::iterator iter = data.find(key);
		if (iter==data.end())
		{
			cerr << "paraname not correct" << endl;
		}
		return iter->second;
	}
	//~Setting();

private:
	map<string, string> data;
};

