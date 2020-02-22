#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool IsClosing(char c1, char c2)
{
	if (c1 == '(' && c2 == ')')
		return true;
	if (c1 == '{' && c2 == '}')
		return true;
	if (c1 == '[' && c2 == ']')
		return true;
	return false;
}
bool isValid(string s) {
	stack<char> st;
	for (int i = 0; i < s.length(); i++)
	{
		char c2 = s.at(i);
		if (!st.empty())
		{
			char c1 = st.top();
			if (IsClosing(c1, c2))
				st.pop();
			else
				st.push(c2);
		}
		else
			st.push(c2);
	}

	return st.empty();
}

int main()
{
	cout << isValid("{[]}");
	return 0;
}
