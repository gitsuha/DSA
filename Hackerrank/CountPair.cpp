#include "Header.h"

int countPairs(vector<int> numbers, int k) {

	sort(numbers.begin(), numbers.end());
	unordered_multiset<int> ms;
	for (int i : numbers)
		ms.insert(i);

	set<pair<int, int>> pairs;
	int count = 0;
	for (int i : numbers)
	{
		if (ms.find(i + k) != ms.end())
			pairs.insert(make_pair(i, k));
	}

	return pairs.size();
}

int main()
{
	vector<int> v = { 1,1,2,2,3,3 };
	int n = countPairs(v, 1);

	system("pause");
	return 0;
}