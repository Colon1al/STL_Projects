// Vector_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
int average(const vector<int>* vec)
{
	return accumulate(vec->cbegin(), vec->cend(), 0) / vec->size();
}



void main()
{
	int k = 1;
	vector<int>* vec = new vector<int>({ 1, 6, -34, 0, 88, 465, 2234, -435, 1, 45, 0, 2234, -1 });
	vector<int>* vecMod = new vector<int>(vec->size());

	cout << "Input K: ";
	cin >> k;
	cout << endl;

	vector<int>::iterator it = copy_if(vec->begin(), vec->end(), vecMod->begin(), [k](int elem) {return elem % k == 0 && elem != 0; });
	vecMod->resize(it-vecMod->begin());
	
	cout << "Average: " << average(vecMod) << endl;
	delete vecMod;

	vector<int>* vecSave = new vector<int>(*vec);
	vector<int>::iterator first_max = max_element(vecSave->begin(), vecSave->end());
	vector<int>::iterator last_max = first_max;
	if (first_max < vecSave->end())
	{
		last_max = max_element(first_max + 1, vecSave->end());
	}

	cout << "First max: " << first_max - vecSave->begin() << endl << "Last max: " << last_max - vecSave->begin() << endl;


	for (auto it = first_max + 1; it < last_max; it++)
	{
		(*it) *= -1;
	}
	
	cout << "Before swap" << endl;
	std::copy(vecSave->begin(), vecSave->end(), std::ostream_iterator<int>(std::cout, " "));

	vector<int>::iterator first_negative = find_if(vecSave->begin(), vecSave->end(), [](int elem) {return elem < 0; });
	if ((first_negative - vecSave->begin()) % 2 == 0) //+1 because indexing starts from 0
	{
		vector<int>* vecTmp = new vector<int>();
		copy(first_negative + 1, vecSave->end(), back_inserter(*vecTmp));
		vecTmp->push_back(*first_negative);
		copy(vecSave->begin(), first_negative, back_inserter(*vecTmp));
		cout << endl << "After swap" << endl;
		std::copy(vecTmp->begin(), vecTmp->end(), std::ostream_iterator<int>(std::cout, " "));
	}
	else
		cout << "No swap" << endl;

	remove_if(vecSave->begin(), vecSave->end(), [](int elem) {return elem == 0; });

	cout << endl << "Before sort" << endl;
	std::copy(vec->begin(), vec->end(), std::ostream_iterator<int>(std::cout, " "));

	sort(vec->begin(), (vec->end() - (int)(vec->size() / 2)));

	cout << endl << "After sort" << endl;
	std::copy(vec->begin(), vec->end(), std::ostream_iterator<int>(std::cout, " "));

}

