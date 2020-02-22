#include "Header.h"

vector<int> NextGreaterElement(vector<int> a)
{
	vector<int> r;
	stack<int> s;
	for (size_t i = 0; i < a.size(); i++)
	{
		if (s.empty())
			s.push(a[i]);
		else
		{
			int top = s.top();
			if (top < a[i])
			{
				s.pop();
				s.push(a[i]);
				r.push_back(a[i]);
			}
			else
			{
				s.push(a[i]);
				r.push_back(0);
			}
		}
	}
	return r;
}

int main()
{
	vector<int> a = { 98,23,54,12,20,7,27 };
	printVector(NextGreaterElement(a));
	return 0;
}
