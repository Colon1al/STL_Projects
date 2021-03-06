// ConsoleApplication5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<float> vec = { -10.5f, 2.6f, -3.0f, 4.1f, -5.5f, 6.6f, -7.3f, 8.4f, -9.6f, -10.1f };
	vector<float> tmp_vec = vec;

	vec.clear();
	vec.resize(tmp_vec.size());

	copy_if(tmp_vec.begin(), tmp_vec.end(), inserter(vec,vec.begin()), [](float i) {return i > 0; });
	copy(vec.begin(), vec.end(), ostream_iterator<float>(std::cout, " ")); // print vector after copy_if 

	if (find(vec.begin(), vec.end(), 0) == vec.begin())
		cout << endl <<  "No positive numbers" << endl;
	else
    	cout << endl << "Min index(from 1) = " << min_element(vec.begin(), vec.end())-vec.begin() << endl;

	//w8 to see the results
	int k;
	cin >> k;
	return 0;
}


