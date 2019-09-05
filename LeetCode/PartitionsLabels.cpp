#include "Header.h"

vector<int> partitionLabels(string S) {
	vector<int> partionLengths;
	int lastIndexes[26];
	for (int i = 0; i < S.length(); i++)
	{
		lastIndexes[S.at(i) - 'a'] = i;
	}

	int i = 0;
	while (i < S.length())
	{
		int end = lastIndexes[S.at(i) - 'a'];
		int j = i;
		while (j < end)
		{
			end = max(end, lastIndexes[S.at(j++) - 'a']);
		}
		partionLengths.push_back(j - i + 1);
		i = j + 1;
	}
	return partionLengths;
}

int main()
{
	printVector(partitionLabels("ababcbacadefegdehijhklij"));

	system("pause");
	return 0;
}