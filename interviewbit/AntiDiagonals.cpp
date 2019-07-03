#include <iostream>
#include <vector>

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
vector<vector<int>> diagonal(vector<vector<int> > &A) {
	vector<vector<int>> v;

	for (size_t i = 0; i < A.size(); i++)
	{
		vector<int> v1;
		for (size_t j = 0; j <= i; j++)
		{
			v1.push_back(A[j][i - j]);
		}
		v.push_back(v1);
	}
	for (size_t i = 1; i < A.size() - 1; i++)
	{
		vector<int> v1;
		for (size_t j = A.size() - 1; j > 0; j--)
		{
			v1.push_back(A[j - i][j]);
		}
		v.push_back(v1);
	}
	return v;
}

int main()
{
	vector<vector<int>> v = { {1, 2, 3},
													{4, 5, 6},
													{7, 8, 9} };
	printVectorOfVector(diagonal(v));

	system("pause");
	return 0;
}