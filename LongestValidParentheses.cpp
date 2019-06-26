#include <iostream>
#include <string>

using namespace std;

int longestValidParentheses_BF(string s) {
	if (s.length() == 0)
		return 0;

	bool start = false;
	int status = 0, count = 0;
	for (size_t i = 0; i < s.length(); i++)
	{
		if (s.at(i) == '(')
			status++;
		else if (s.at(i) == ')')
			status--;
		if (status == 0)
			count++;
	}
	return count * 2;
}

int main()
{
	string str = ")()())"; // ")(())))(())())";
	cout << longestValidParentheses_BF(str) << endl;

	system("pause");
	return 0;
}