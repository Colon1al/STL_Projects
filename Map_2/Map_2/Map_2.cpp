// Map_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include <string>
#include <iostream>

using namespace std;


struct IP
{
	int First;
	int Second;
	int Third;
	int Fourth;
	IP()
	{
		First = 0;
		Second = 0;
		Third = 0;
		Fourth = 0;
	}
};

struct User
{
	string Name;
	string Login;
	IP Adress;
};


int main()
{

	User U;
	int n = 0;
	while (n < 0 && n>100)
	{
		cin >> n;
	}
	if (!scanf("%d", U.Adress.First))
	{
		scanf("%d.%d", U.Adress.First, U.Adress.Second);
	}
	













	int k;
	cin >> k;
    return 0;
}

