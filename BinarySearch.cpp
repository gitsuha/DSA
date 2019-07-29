#include "Header.h"

int binarySearch(vector<int> a, int l, int h, int t)
{
	if (l <= h)
	{
		int m = (l + h) / 2;
		if (a[m] == t)
			return m;
		else if (a[m] > t)
			return binarySearch(a, l, m - 1, t);
		else if (a[m] < t)
			return binarySearch(a, m + 1, h, t);
	}

	return -1;
}

int main()
{
	cout << "sorted ascending - left" << endl;
	vector<int> a1 = { 1,2,3,4,5,6,7,8,9 };
	cout << binarySearch(a1, 0, 9, 2) << endl;

	cout << "sorted ascending - right" << endl;
	vector<int> a2 = { 1,2,3,4,5,6,7,8,9 };
	cout << binarySearch(a2, 0, 9, 8) << endl;

	cout << "sorted ascending - the middle" << endl;
	vector<int> a3 = { 1,2,3,4,5,6,7,8,9 };
	cout << binarySearch(a3, 0, 9, 5) << endl;

	cout << "sorted ascending - finding the last element" << endl;
	vector<int> a4 = { 1,2,3,4,5,6,7,8,9 };
	cout << binarySearch(a4, 0, 9, 9) << endl;

	cout << "sorted ascending - finding the first element" << endl;
	vector<int> a5 = { 1,2,3,4,5,6,7,8,9 };
	cout << binarySearch(a5, 0, 9, 1) << endl;

	return 0;
}