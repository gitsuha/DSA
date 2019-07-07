#include <iostream>

using namespace std;

void reverse(char* str)
{
	char* end = str;
	while (*end)
	{
		++end;
	}
	--end;

	char tmp;
	while (str < end)
	{
		cout << *str << " " << *end << endl;

		tmp = *str;
		*str++ = *end;
		*end-- = tmp;		
	}
}

int main()
{
	char arr[] = { 'a','b','c','d','e','\0'};
	char* sz = new char[sizeof(arr)/sizeof(char)];
	sz = arr;
	reverse(sz);
	cout << sz << endl;

	system("pause");
	return 0;
}