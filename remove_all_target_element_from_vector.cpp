#include "Header.h"

int removeElement(vector<int>& nums, int val) {

	vector<int>::iterator it = nums.begin();
	while (it != nums.end())
	{
		if (*it == val)
			it = nums.erase(it);
		else
			it++;
	}
	return nums.size();
}

int main()
{
	vector<int> v = { 0,1,2,2,3,0,4,2 };
	removeElement(v, 2);

	return 0;
}