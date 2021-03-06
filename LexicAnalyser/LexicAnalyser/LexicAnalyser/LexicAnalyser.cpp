// LexicAnalyser.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "stdio.h"

using namespace std;

bool isDigit(char c)
{
	return c >= '0' && c <= '9';
}
bool isChar(char c)
{
	return (c >= 'a' && c <= 'z') || (c>='A' && c<='Z');
}





int main()
{
	int S = 0;
	bool flag;
	string code;

	vector<multimap<int, bool(*)(char)>> StateVec;
	
	StateVec.push_back({ { 1,[](char c)->bool {return c == 'd'; } } });//0
	StateVec.push_back({ { 2,[](char c)->bool {return c == 'o'; } } });//1
	StateVec.push_back({ { 3,[](char c)->bool {return c == ' '; } } });//2
	StateVec.push_back({ { 4,[](char c)->bool {return c == 'w'; } } });//3
	StateVec.push_back({ { 5,[](char c)->bool {return c == 'h'; } } });//4
	StateVec.push_back({ { 6,[](char c)->bool {return c == 'i'; } } });//5
	StateVec.push_back({ { 7,[](char c)->bool {return c == 'l'; } } });//6
	StateVec.push_back({ { 8,[](char c)->bool {return c == 'e'; } } });//7
	StateVec.push_back({ { 9,[](char c)->bool {return c == ' '; } } });//8
	//<find variable name>
	StateVec.push_back({ //9
		{ 9,[](char c)->bool {return isChar(c); } }, 
		{ 10,[](char c)->bool {return isDigit(c); } } });
	StateVec.push_back({ //10
		{ 10,[](char c)->bool {return isChar(c); } }, 
		{ 10,[](char c)->bool {return isDigit(c); } },
		{ 11,[](char c)->bool {return c=='<' || c == '>'; } } });
	//<find variable name/>
	StateVec.push_back({ //11
		{ 11,[](char c)->bool {return isDigit(c); } }, 
		{ 12,[](char c)->bool {return c==' '; } } });
	//<find variable name>
	StateVec.push_back({ //12
		{ 12,[](char c)->bool {return isChar(c); } }, 
		{ 13,[](char c)->bool {return isDigit(c); } } });
	StateVec.push_back({ //13
		{ 13,[](char c)->bool {return isChar(c); } },
		{ 13,[](char c)->bool {return isDigit(c); } },
		{ 14,[](char c)->bool {return c == '='; } } });
	//</find variable name>
	//<find variable name or digit>
	StateVec.push_back({ //14
		{ 16,[](char c)->bool {return isChar(c); } },
		{ 15,[](char c)->bool {return isDigit(c); } },
		{ 17,[](char c)->bool {return c == '+' || c == '-' || c == '/' || c == '*'; } } });
	StateVec.push_back({ //15
		{ 15,[](char c)->bool {return isDigit(c); } },
		{ 17,[](char c)->bool {return c == '+' || c == '-' || c == '/' || c == '*'; } } });
	StateVec.push_back({ //16
		{ 16,[](char c)->bool {return isChar(c); } },
		{ 16,[](char c)->bool {return isDigit(c); } },
		{ 17,[](char c)->bool {return c == '+' || c == '-' || c == '/' || c == '*'; } } });
	//</find variable name or digit>
	StateVec.push_back({ //17
		{ 19,[](char c)->bool {return isChar(c); } },
		{ 18,[](char c)->bool {return isDigit(c); } },
		{ 20,[](char c)->bool {return c == '+' || c == '-' || c == '/' || c == '*'; } } });
	StateVec.push_back({ //18
		{ 18,[](char c)->bool {return isDigit(c); } },
		{ 20,[](char c)->bool {return c == ' '; } } });
	StateVec.push_back({ //19
		{ 19,[](char c)->bool {return isChar(c); } },
		{ 19,[](char c)->bool {return isDigit(c); } },
		{ 20,[](char c)->bool {return c == ' '; } } });

	StateVec.push_back({ { 21,[](char c)->bool {return c == 'l'; } } }); //20
	StateVec.push_back({ { 22,[](char c)->bool {return c == 'o'; } } }); //21
	StateVec.push_back({ { 23,[](char c)->bool {return c == 'o'; } } }); //22
	StateVec.push_back({ { 24,[](char c)->bool {return c == 'p'; } } }); //23






	while (getline(cin, code), code != "")
	{
		for (auto i : code)
		{
			int S_old = S;
			for (auto Elem : StateVec[S])
			{
				
				if (flag = Elem.second(i))
				{
					S = Elem.first;
					printf("\nState: %d Goto: %d End Char: %c", S_old, S, i);
					break;
				}
			}
			if (!flag)
			{
				break;
			}
		}
	}

	if (S == 24)
	{
		cout << "Test passed" << endl;
	}

	int k;
	cin >> k;

	return 0;
}

