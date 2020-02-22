#include "Header.h"

int main()
{
	vector<int> v = { 8, 4, 5, 4, 8, 3, 9, 4, 2 };
	map<int, int> m;
	for (int i : v)
		m[i]++;

	multimap<int, int> m2;
	for (pair<int, int> p : m)
		m2.insert(make_pair(p.second, p.first));

	for (pair<int, int> p : m2)
		for (int i = 0; i < p.first; i++)
			cout << p.second << " ";

	cout << endl;

	return 0;
}
