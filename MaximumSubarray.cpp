#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMaxSum_BF(vector<int>& a)
{
	int sum = 0;
	for (size_t i = 0; i < a.size(); i++)
	{
		int localSum = 0;
		for (size_t j = i; j < a.size(); j++)
		{
			localSum += a[j];
			sum = max(sum, localSum);
		}		
	}
	return sum;
}

int getMaxSum_Kadanes(vector<int>& a)
{
	int localSum = 0, globalSum = INT_MIN;
	for (size_t i = 0; i < a.size(); i++)
	{
		localSum = max(a[i], a[i] + localSum);
		globalSum = max(localSum, globalSum);
	}
	return globalSum;
}

int main()
{
	vector<int> a = { -2,1,-3,4,-1,2,1,-5,4 };
	cout << getMaxSum_BF(a) << endl;
	cout << getMaxSum_Kadanes(a) << endl;

	system("pause");
	return 0;
}