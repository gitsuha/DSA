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

using namespace std;

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