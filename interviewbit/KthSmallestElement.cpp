#include "Header.h"

int KthSmallestElement(vector<int> A, int B)
{
	map<int, int> minIndexValMap;
	int count = 1;
	while(count <= B)
	{
		int minVal = INT_MAX;
		int minIndex = -1;
		for (size_t i = 0; i < A.size(); i++)
		{
			if (minIndexValMap.find(i) != minIndexValMap.end())
				continue;

			if (A[i] < minVal)
			{
				minVal = A[i];
				minIndex = i;
			}
		}
		if (count == B)
			return minVal;
		minIndexValMap[minIndex] = minVal;
		count++;
	}
}

int main()
{
	vector<int> A = { 8, 16, 80, 55, 32, 8, 38, 40, 65, 18, 15, 45, 50, 38, 54, 52, 23, 74, 81, 42, 28, 16, 66, 35, 91, 36, 44, 9, 85, 58, 59, 49, 75, 20, 87, 60, 17, 11, 39, 62, 20, 17, 46, 26, 81, 92 }; // 7 for B = 3
	int res = KthSmallestElement(A, 9);

	return 0;
}