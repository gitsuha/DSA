#include "Header.h"

int lengthOfLongestSubstring(string s) {

	if (s.empty()) return 0;
	int maxLen = 0;
	string str;
	for (int i = 0; i < s.size(); i++)
	{
		string::size_type pos = str.find(s.at(i));
		if (pos != string::npos)
		{
			int size = str.size();
			maxLen = max(maxLen, size);
			str.erase(0, pos + 1);
		}
		str.push_back(s.at(i));
	}
	int size = str.size();
	maxLen = max(maxLen, size);

	return maxLen;
}

int main()
{
	int n = lengthOfLongestSubstring("abcabcbb");
	return 0;
}
