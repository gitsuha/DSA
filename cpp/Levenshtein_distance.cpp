#include "Header.h"

/*
Levenshtein distance : https://en.wikipedia.org/wiki/Levenshtein_distance
*/

int deletionDistanceRecurr( int i1, int i2, const string& str1, const string& str2 ) 
{
	if (i1 == 0)
		return i2;

	if (i2 == 0)
		return i1;

	if (str1[i1 - 1] == str2[i2 - 1])
		return deletionDistanceRecurr(i1 - 1, i2 - 1, str1, str2);

	return 1 + min(min(deletionDistanceRecurr(i1 - 1, i2, str1, str2), 
									deletionDistanceRecurr(i1, i2 - 1, str1, str2)),
									deletionDistanceRecurr(i1 - 1, i2 - 1, str1, str2));
}

int deletionDistanceDP(const string& str1, const string& str2)
{
	int str1Len = str1.length();
	int str2Len = str2.length();

	//# allocate a 2D array with str1Len + 1 rows and str2Len + 1 columns
	vector<vector<int>> memo(str1Len + 1, vector<int>(str2Len + 1, 0));
	for (size_t i = 0; i <= str1Len; i++)
	{
		for (size_t j = 0; j <= str2Len; j++)
		{
			if (i == 0)
				memo[i][j] = j;
			else if (j == 0)
				memo[i][j] = i;
			else if (str1[i - 1] == str2[j - 1])
				memo[i][j] = memo[i - 1][j - 1];
			else
				memo[i][j] = 1 + min(min(memo[i - 1][j], memo[i][j - 1]), memo[i - 1][j - 1]);
		}
	}

	printVectorOfVector(memo);
	return memo[str1Len][str2Len];
}

int main()
{
	string str1 = "heat";
	string str2 = "hit";
	int n = deletionDistanceRecurr(str1.length(), str2.length(), str1, str2);
	n = deletionDistanceDP(str1, str2);
	return 0;
}
