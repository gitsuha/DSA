#include "Header.h"

int increment(int x) { return (x + 1); }

string rollString(string str, vector<int> roll)
{
	int len = str.length();
	vector<int> cumRoll(len, 0);
	for (size_t i = 0; i < roll.size(); i++)
	{
		++cumRoll[0];
		int nRoll = roll[i];
		if (nRoll >= cumRoll.size())
			continue;
		else
			--cumRoll[nRoll];
	}

	for (size_t i = 1; i < len; i++)
		cumRoll[i] = cumRoll[i] + cumRoll[i - 1];

	string res;
	for (size_t i = 0; i < len; i++)
	{
		if (cumRoll[i] > 0)
		{
			int ci = (int)str.at(i);
			ci -= 'a';
			ci += cumRoll[i];
			ci %= 26;
			ci += 'a';
			char c = (char)ci;
			res.push_back(c);
		}
		else
			res.push_back(str.at(i));
	}
	return res;
}

int main()
{
	//cout << rollString("geeks", { 1, 2, 5 }) << endl;
	cout << rollString("vgxgpuamkx", { 5,5,2,4,7,6,2,2,8,7 }) << endl;

	return 0;
}
