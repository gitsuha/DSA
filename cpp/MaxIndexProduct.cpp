#include "Header.h"

vector<int> NextGreaterElement_L(vector<int> a)
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
				r.push_back(i + 1);
			}
			else
			{
				s.push(a[i]);
				r.push_back(0);
			}
		}
	}
	r.push_back(0);	// for the last element
	return r;
}

vector<int> NextGreaterElement_R(vector<int> a)
{
	vector<int> r;
	stack<int> s;
	for (int i = a.size() - 1; i >= 0; i--)
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
				r.push_back(i + 1);
			}
			else
			{
				s.push(a[i]);
				r.push_back(0);
			}
		}
	}
	r.push_back(0);	// for the last element
	reverse(r.begin(), r.end());
	return r;
}

int solve(vector<int> arr) {
	int n = arr.size();
	vector<int> left = NextGreaterElement_L(arr);
	vector<int> right = NextGreaterElement_R(arr);

	int ans = 0;
	for (size_t i = 0; i < n; i++)
	{
		ans = max(ans, left[i] * right[i]);
	}
	return ans;
}

int main()
{
	vector<int> a = { 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 };
	cout << solve(a);
	return 0;
}


