#include "Header.h"

int maximumGap(const vector<int> &A) {
	map<int, int, less <int>> m;
	for (int i = 0; i < A.size(); i++)
		m[A[i]] = i;

	map<int, int> ::iterator it;
	for (it = m.begin(); it != m.end(); it++)
		cout << "(" << (*it).first << ", " << (*it).second << ")" << endl;

	int prev = A.size();
	int result = -1;
	vector<int> indexes;
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
		indexes.push_back(it->second);

	for (int i = 1; i < indexes.size(); i++)
	{
		if (indexes[i] > indexes[i - 1]) {
			continue;
		}
	}

	return result;
}

int main()
{
	vector<int> v = { 9, 2, 3, 4, 5, 6, 7, 8, 18, 0 };
	cout << maximumGap(v) << endl;

	return 0;
}