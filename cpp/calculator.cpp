#include <iostream>
#include <queue>
#include <string>

using namespace std;

int calculate(queue<char>& q) {
	long long curr_num = 0, prev_num = 0, res = 0;
	char prev_op = '+';

	while (!q.empty())
	{
		char c = q.front();
		q.pop();
		
		if (c >= '0' && c <= '9') {
			curr_num += curr_num * 10 + c - '0';
		}
		else if (c == '(') {
			curr_num = calculate(q);
		}
		else {
			switch (prev_op)
			{
			case '+':
				res += prev_num;
				prev_num = curr_num;
				break;
			case '-':
				res += prev_num;
				prev_num = -curr_num;
				break;
			case '*':
				prev_num *= curr_num;
				break;
			case '/':
				prev_num /= curr_num;
				break;
			default:
				break;
			}
			if (c == ')') break;
			curr_num = 0;
			prev_op = c;
		}
	}
	return res + prev_num;
}

int calculate(string s) {
	queue<char> q;
	// lets put the string into a queue discarding the spaces
	for (char c : s) {
		if (c != ' ')
			q.push(c);
	}

	// pushing a space in the end to consider the last calc
	q.push(' ');

	return calculate(q);
}

int main() {

	int n = calculate("(3+(4-2))* 2");
	return 0;
}
