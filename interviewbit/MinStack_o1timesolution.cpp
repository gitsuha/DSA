#include "Header.h"

class Stack
{
	static const int size = 100;
	int arr[size];
	int index;

public:
	Stack() { index = -1; }
	bool IsFull()
	{
		if (index == size - 1)
			return true;
		return false;
	}
	bool IsEmpty()
	{
		if (index == -1)
			return true;
		return false;
	}
	void push(int x)
	{
		if (IsFull())
		{
			cout << "buffer overflow" << endl;
			abort();
		}
		arr[++index] = x;
	}
	int top()
	{
		if (IsEmpty())
			return -1;
		return arr[index];
	}
	int pop()
	{
		if (IsEmpty())
		{
			cout << "buffer underflow" << endl;
			abort();
		}
		int x = arr[index];
		index--;
		return x;
	}
};

class MinStack : public Stack
{
	Stack minS;
public:
	int getMin()
	{
		if (minS.IsEmpty())
			return -1;
		return minS.top();
	}
	void push(int x)
	{
		if (IsEmpty())
		{
			Stack::push(x);
			minS.push(x);
		}
		else
		{
			Stack::push(x);
			int top = minS.top();
			int val = min(top, x);
			minS.push(val);
		}
	}
	int pop()
	{
		minS.pop();
		return Stack::pop();
	}
};

int main()
{
	MinStack ms;

	ms.push(8);
	cout << ms.getMin() << endl; // 8

	ms.push(4);
	cout << ms.getMin() << endl; // 4

	ms.push(14);
	cout << ms.getMin() << endl; // 4

	ms.push(2);
	cout << ms.getMin() << endl; // 2

	ms.pop();
	cout << ms.getMin() << endl; // 4


	system("pause");
	return 0;
}