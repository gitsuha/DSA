#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices) {
	//find the difference array
	vector<int> dif;
	for (int i = 1; i < prices.size(); i++)
		dif.push_back(prices[i] - prices[i - 1]);

	int localMax = 0, maxProfit = 0;
	for (size_t i = 0; i < dif.size(); i++)
	{
		localMax = max(dif[i], dif[i] + localMax);
		maxProfit = max(localMax, maxProfit);
	}

	return maxProfit;
}

int main()
{
	vector<int> a = { 7,1,5,3,6,4 };
	cout << maxProfit(a) << endl;

	system("pause");
	return 0;
}
