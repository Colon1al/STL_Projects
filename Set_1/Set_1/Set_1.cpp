#include <iostream>
#include <set>
#include <time.h>
#include <algorithm>


using namespace std;


int main()
{
	srand(time(NULL));

	set<int> S, A, B,res1,res2,buffer;

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
		for (int j = 0; j < count_if(S.begin(), S.end(), [ind](int a) {return a == ind;}); j++)
		A.insert(ind);
	}

	cout << "A:" << endl;
	for_each(A.begin(), A.end(), [](int a) {cout << "  Element: " << a << endl; return; });


	cout << "B:" << endl;
	for_each(B.begin(), B.end(), [](int a) {cout << "  Element: " << a << endl; return; });



	//first

	set_union(A.begin(), A.end(), B.begin(), B.end(), back_inserter(res1,res1.rbegin()));

	//second

	set_symmetric_difference(S.begin(), S.end(), A.begin(), A.end(), back_inserter(buffer));
	A.clear();

	set_symmetric_difference(S.begin(), S.end(), B.begin(), B.end(), back_inserter(A));

	
	set_intersection(A.begin(), A.end(), buffer.begin(), buffer.end(), back_inserter(res2));


	cout << "Res1:" << endl;
	for_each(res2.begin(), res2.end(), [](int a) {cout << "  Element: " << a << endl; return; });


	cout << "Res2:" << endl;
	for_each(res2.begin(), res2.end(), [](int a) {cout << "  Element: " << a << endl; return; });

}

