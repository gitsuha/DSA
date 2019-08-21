#include "Header.h"

string rollString(string str, vector<int> a)
{
	sort(a.begin(), a.end());
	int len = str.length();
	vector<int> roll(len, 0);
	for (size_t i = 0; i < a.size(); i++)
	{
		for (size_t j = 0; j < a[i]; j++)
		{
			roll[j]++;
		}
	}
	string res;
	for (size_t i = 0; i < len; i++)
	{
		if (roll[i] > 0)
		{
			int ci = (int)str.at(i);
			ci -= 'a';
			ci += roll[i];
			ci %= 26;
			ci += 'a';
			char c = (char)ci;
			res.push_back(c);
		}
	}
	return res;
}

int main()
{
	cout << rollString("geeks", { 1, 2, 5 }) << endl;
	cout << rollString("zzzz", { 1, 2, 4 }) << endl;
	return 0;
}