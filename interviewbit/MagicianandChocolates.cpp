#include "Header.h"

int nchoc(int A, vector<int> &B) {
	long long int m = 1000000007;
	long long int res = 0;
	for (int i = 1; i <= A; i++) {
		sort(B.begin(), B.end());
		long long int add = B[B.size() - 1];
		res += add % m;
		B[B.size() - 1] = floor(add / 2);
	}
	return res % m;
}

int main()
{
	int A = 10;
	vector<int> B = { 2147483647, 2000000014, 2147483647 };
	int f = nchoc(A, B);

	system("pause");
	return 0;
}