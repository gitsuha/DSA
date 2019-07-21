#include "Header.h"

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool cmpInterval(Interval l, Interval b) {
	return (l.start <= l.end);
}

vector<Interval> merge(vector<Interval> &A) {
	//sort the intervals first
	sort(A.begin(), A.end(), cmpInterval);
	return A;
}

int main()
{
	vector<Interval> A;
	A.push_back(Interval(2, 6));
	A.push_back(Interval(15, 18));
	A.push_back(Interval(1, 3));
	A.push_back(Interval(8, 10));
	sort(A.begin(), A.end(), cmpInterval);
	return 0;
}