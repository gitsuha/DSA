#pragma once

#include <assert.h>
#include <limits>
#include <iostream>
#include <random>
#include <bitset>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <iterator>
#include <thread>
#include <stack>
#include <numeric>
#include <queue>
#include <unordered_set>
#include <set>

using namespace std;

#include <chrono> 
using namespace std::chrono;

#pragma warning(disable  : 4996)

template <class T>
void printVector(vector<T> v)
{
	for (T& i : v)
	{
		cout << i << " ";
	}
	cout << endl;
}

void printVectorOfVector(const vector<vector<int>>& v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		for (size_t j = 0; j < v[i].size(); j++)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
