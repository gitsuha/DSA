#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> solve(int A) 
{
	vector<vector<int>> ex;
	if (A == 0)
		return ex;

	// for row 1
	vector<int> in = {1};
	ex.push_back(in);
	if (A == 1)
		return ex;
	in.clear();

	// for row 2
	in.push_back(1);
	in.push_back(1);
	ex.push_back(in);
	if (A == 2)
		return ex;
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
	return ex;
}

int main()
{
	vector<vector<int>> a = solve(0);
	for (size_t i = 0; i < a.size(); i++)
	{
		vector<int> b = a[i];
		for (size_t j = 0; j < b.size(); j++)
		{
			cout << b[j] << " ";
		}
		cout << endl;
	}
	return 0;
}