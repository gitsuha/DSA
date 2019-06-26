#include <iostream>
#include <string>

using namespace std;

int longestValidParentheses_BF(string s) {
	if (s.length() == 0)
		return 0;

	int count = 0;
	for (size_t i = 1; i < s.length(); i++)
	{
		if (s.at(i) == ')')
			if (s.at(i - 1) == '(')
				count += 2;
	}
	return count;
}

int main()
{
	string str = /*")()())"; // */")(())))(())())";
	cout << longestValidParentheses_BF(str) << endl;

	system("pause");
	return 0;
}