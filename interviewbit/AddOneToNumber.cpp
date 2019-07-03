//	Given a non - negative number represented as an array of digits,
//	
//	add 1 to the number(increment the number represented by the digits).
//	
//	The digits are stored such that the most significant digit is at the head of the list.
//	
//	Example:
//	
//	If the vector has[1, 2, 3]
//	
//	the returned vector should be[1, 2, 4]
//	
//	as 123 + 1 = 124

#include <iostream>
#include <vector>

using namespace std;

void printVec(vector<int> &A)
{
	for (int const& val : A)
		cout << val << " ";
	cout << endl;
}

vector<int> plusOne(vector<int> &A)
{
	bool carryOver = false;
	int carryFwd = 1;
	vector<int> B;
	for (int i = A.size() - 1; i >= 0; i--)
	{
		if (A[i] + carryFwd > 9)
		{
			B.push_back(A[i] + carryFwd - 10);
			carryFwd = 1;
		}
		else
		{
			B.push_back(A[i] + carryFwd);
			carryFwd = 0;
		}
	}

	if (carryFwd > 0)
		B.push_back(carryFwd);

	reverse(B.begin(), B.end());

	vector<int> C;
	for (size_t i = 0; i < B.size(); i++)
	{
		if (B[i] != 0)
		{
			C.assign(B.begin() + i, B.end());
			break;
		}
	}

	return C;
}

int main()
{
	vector<int> a = { 0, 0, 4, 4, 6, 0, 9, 6, 5, 1 };
	vector<int> b = plusOne(a);
	printVec(b);

	system("pause");
	return 0;
}
