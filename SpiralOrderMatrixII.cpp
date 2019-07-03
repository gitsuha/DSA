#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
void printVector(const vector<T>& v)
{
	for (auto const& i : v)
	{
		cout << i << " ";
	}
	cout << endl;
}

template <class T>
void printVectorOfVector(const vector<vector<T>>& v)
{
	for (auto const& i : v)
	{
		printVector(i);
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

vector<vector<int>> generateMatrix(int A)
{
	vector<vector<int> > res(A);
	for (int i = 0; i < A; i++) res[i].resize(A);

	int top = 0, bottom = A - 1, left = 0, right = A - 1, n = 1;
	while (n <= A * A) {
		for (int i = left; i <= right; i++) res[top][i] = n++;
		top++;
		for (int i = top; i <= bottom; i++) res[i][right] = n++;
		right--;
		for (int i = right; i >= left; i--) res[bottom][i] = n++;
		bottom--;
		for (int i = bottom; i >= top; i--) res[i][left] = n++;
		left++;
	}
	return res;
}

int main()
{
	printVectorOfVector(generateMatrix(3));

	system("pause");
	return 0;
}