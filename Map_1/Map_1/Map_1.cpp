// Map_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <iterator>
#include <map>
#include <iostream>
#include <vector>

#define  CHECK_RANGE(x,i,j) x>i && x<j

using namespace std;

void print_map(const map<int,int> &Map)
{
	for(auto Pair : Map)
		cout << "Pair: " << Pair.first << " Votes: " << Pair.second << endl;
}

int main()
{
	map<int, int> *PairMap = new map<int, int>();
	for (int i = 1; i < 17; i++)
	{
		PairMap->insert(make_pair(i, 0));
	}

	print_map(*PairMap);


	int pair_number = 1;

	cout << "SMS input(input -1 to exit)" << endl;
	while (pair_number != -1)
	{

		cin >> pair_number;
		cout << endl;

		if(CHECK_RANGE(pair_number,1,17))
			PairMap->at(pair_number) += 1;
	}
	auto l = [](std::pair<int, int> a, std::pair<int, int> b) {return a.second != b.second ? a.second < b.second : a.first < b.first; };
	//sort map max to min


	//Because map is not sortable by defenition
	vector<pair<int, int>> *sort_vector = new vector<pair<int, int>>();
	for_each(PairMap->begin(), PairMap->end(), [sort_vector](pair<int, int> a) {sort_vector->push_back(a); return; });

	sort(sort_vector->begin(), sort_vector->end(), [](pair<int, int> a, pair<int, int> b) { return a.second > b.second; });

	for_each(sort_vector->begin(), sort_vector->end(), [](pair<int, int> a) {cout << "Pair: " << a.first << " Votes: " << a.second << endl; return; });

	int k;
	cin >> k;

	delete PairMap;
    return 0;
}

