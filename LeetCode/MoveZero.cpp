#include "Header.h"

void moveZeroes(vector<int>& nums) {

	int zeroCount = 0;
	int l = 0;
	while (l < nums.size()) {
		if (nums[l] == 0) {
			nums.erase(nums.begin() + l);
			zeroCount++;
		}
		else
			l++;
	}

	if (zeroCount > 0)
		nums.insert(nums.end(), zeroCount, 0);
}

int main()
{
	vector<int> v = { 0,1,0,3,12 };
	moveZeroes(v);

	return 0;
}