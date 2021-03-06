// Set_1(VS17).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <set>
#include <time.h>
#include <algorithm>
#include <vector>
#include <iterator>


using namespace std;


int main()
{
	set<int> S, A, B, res1, res2, buffer1, buffer2;

	int N, ia, ib;

	cout << "Input N and range for random numbers" << endl;
	cin >> N >> ia >> ib;

	for (int i = 0; i < N; i++)
	{
		S.insert(rand() % (ia - ib) + ia);
	}


	for_each(S.begin(), S.end(), [](int a) {cout << "Element: " << a << endl; return; });

	for_each(S.begin(), S.end(), [&B](int a) {if (a % 2 != 0) { B.insert(a); } });
	cout << "Input number of elements to choose" << endl;

	cin >> N;

	cout << "Input element:" << endl;
	for (int i = 0; i < N; i++)
	{
		int ind;
		cin >> ind;
		for (int j = 0; j < count_if(S.begin(), S.end(), [ind](int a) {return a == ind; }); j++)
			A.insert(ind);
	}

	cout << "A:" << endl;
	for_each(A.begin(), A.end(), [](int a) {cout << "  Element: " << a << endl; return; });


	cout << "B:" << endl;
	for_each(B.begin(), B.end(), [](int a) {cout << "  Element: " << a << endl; return; });


	//first

	set_union(A.begin(), A.end(), B.begin(), B.end(), inserter(res1,res1.end()));

	//second

	set_difference(S.begin(), S.end(), A.begin(), A.end(), inserter(buffer1, buffer1.end())); // /A

	set_difference(S.begin(), S.end(), B.begin(), B.end(), inserter(buffer2, buffer2.end())); // /B


	set_intersection(buffer2.begin(), buffer2.end(), buffer1.begin(), buffer1.end(), inserter(res2, res2.end())); // /A  /B
	buffer1.clear();
	buffer2.clear();

	set_difference(S.begin(), S.end(), res2.begin(), res2.end(), inserter(buffer1, buffer1.end())); // /(/A /B)

	cout << "Res1:" << endl;
	for_each(res1.begin(), res1.end(), [](int a) {cout << "  Element: " << a << endl; return; });


	cout << "Res2:" << endl;
	for_each(buffer1.begin(), buffer1.end(), [](int a) {cout << "  Element: " << a << endl; return; });



	cout << "Res2 only odd:" << endl;
	for_each(buffer1.begin(), buffer1.end(), [](int a) {if (a % 2 != 0) { cout << "  Element: "<< a << endl; } });


	int k;
	cin >> k;

	return 0;
}





