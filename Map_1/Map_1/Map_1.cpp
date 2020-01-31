// Map_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <iterator>
#include <map>
#include <iostream>
#include <vector>
using namespace std;

void print_map(const map<int,int> &Map)
{
	for(auto Pair : Map)
		cout << "Key: " << Pair.first << " Value: " << Pair.second << endl;

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

		if(pair_number>0 &&pair_number<17)
			PairMap->at(pair_number) += 1;
	}
	auto l = [](std::pair<int, int> a, std::pair<int, int> b) {return a.second != b.second ? a.second < b.second : a.first < b.first; };
	//sort map max to min

	vector<pair<int, int>> *sort_vector = new vector<pair<int, int>>();
	for_each(PairMap->begin(), PairMap->end(), [sort_vector](pair<int, int> a) {sort_vector->push_back(a); return; });

	sort(sort_vector->begin(), sort_vector->end(), [](pair<int, int> a, pair<int, int> b) { return a.second > b.second; });

	PairMap->clear();

	for_each(sort_vector->begin(), sort_vector->end(), [PairMap](pair<int, int> a) {PairMap->insert(a); return; });

	for (auto a : *sort_vector)
	{
		cout << "First: " << a.first << "Second: " << a.second << endl;
	}

	int k;
	cin >> k;


	delete PairMap;
    return 0;
}

