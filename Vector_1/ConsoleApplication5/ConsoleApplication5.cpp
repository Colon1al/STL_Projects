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
	vector<float> vec = { 10.5f, 2.6f, 3.0f, -4.1f, 5.5f, 6.6f, 7.3f,8.4f,9.6f,10.1f };
	copy_if(vec.begin(), vec.end(), vec.begin(), [](float i) {return i > 0; });
	if (vec.empty())
		cout << "No positive numbers" << endl;
	else
    	cout << "Min index = " << min_element(vec.begin(), vec.end())-vec.begin() << endl;

	return 0;
}


