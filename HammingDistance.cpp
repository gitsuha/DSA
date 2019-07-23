#include "Header.h"

int hammingDistance(const vector<int>& A) {
	int inputSize = A.size();
	int mod = 1000000007;
	int sum = 0;
	for (int bitPosition = 0; bitPosition < 31; bitPosition++) {
		int cntBitOne = 0, cntBitZero = 0;
		for (int i = 0; i < inputSize; i++) {
			if (A[i] & (1 << bitPosition)) cntBitOne++;
			else cntBitZero++;
		}
		sum = sum + ((2LL * cntBitOne * cntBitZero) % mod);
		if (sum >= mod) sum = sum - mod;
	}
	return sum;
}

int main()
{
	vector<int> v = { 2, 4, 6 };
	cout << hammingDistance(v);
	return 0;
}