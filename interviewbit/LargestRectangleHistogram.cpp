#include "Header.h"

int maxArea(vector<int> h)
{
	int maxArea = 0;
	for (int i = 0; i < h.size(); i++)
	{
		int area = 0;
		for (int j = i; j < h.size(); j++)
		{
			if (h[j] < h[i])
				break;
			area += h[i];
		}
		for (int j = i - 1; j >= 0; j--)
		{
			if (h[j] < h[i])
				break;
			area += h[i];
		}
		maxArea = max(area, maxArea);
	}
	return maxArea;
}

int largestRectanglularAreaInHistogram(vector<int> hist) {
	stack<int> s;

	int maxArea = 0;
	int tp;
	int areaWithTop;

	int i = 0;
	while (i < hist.size()) {
		if (s.empty() || hist[s.top()] <= hist[i]) {
			s.push(i++);
		}
		else {
			tp = s.top();
			s.pop();
			int w = s.empty() ? i : i - s.top() - 1;
			areaWithTop = hist[tp] * w;

			if (maxArea < areaWithTop)
				maxArea = areaWithTop;
		}
	}

	while (!s.empty()) {
		tp = s.top();
		s.pop();
		int w = s.empty() ? i : i - s.top() - 1;
		areaWithTop = hist[tp] * w;

		if (maxArea < areaWithTop)
			maxArea = areaWithTop;
	}

	return maxArea;
}

int main()
{
	int a = largestRectanglularAreaInHistogram({ 2,1,6,5,6,2,3 });
	return 0;
}