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

vector<int> solve(int A)
{
	A++;
	vector<vector<int>> ex;
	if (A == 0)
		return vector<int>();

	// for row 1
	vector<int> in = { 1 };
	ex.push_back(in);
	if (A == 1)
		return ex[0];
	in.clear();

	// for row 2
	in.push_back(1);
	in.push_back(1);
	ex.push_back(in);
	if (A == 2)
		return ex[1];
	in.clear();

	for (size_t i = 2; i < A; i++)
	{
		in = ex[i - 1];
		vector<int> v;
		v.push_back(1);
		for (size_t j = 1; j <= i - 1; j++)
		{
			v.push_back(in[j - 1] + in[j]);
		}
		v.push_back(1);
		ex.push_back(v);
	}
	return ex[A - 1];
}

int main()
{
	printVector(solve(3));

	system("pause");
	return 0;
}
