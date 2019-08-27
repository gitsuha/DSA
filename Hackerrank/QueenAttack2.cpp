#include "Header.h"

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {

	set<pair<int, int>> obstacleSet;
	for (vector<int> v : obstacles) {
		if (v.size() == 2)
			obstacleSet.insert(make_pair(v[0], v[1]));
	}

	int nSquares = 0;
	for (int i = r_q + 1; i <= n; i++) {
		if (obstacleSet.find(make_pair(i, c_q)) != obstacleSet.end())
			break;
		else
			nSquares++;
	}
	for (int i = r_q - 1; i >= 1; i--) {
		if (obstacleSet.find(make_pair(i, c_q)) != obstacleSet.end())
			break;
		else
			nSquares++;
	}
	for (int i = c_q + 1; i <= n; i++) {
		if (obstacleSet.find(make_pair(r_q, i)) != obstacleSet.end())
			break;
		else
			nSquares++;
	}
	for (int i = c_q - 1; i >= 1; i--) {
		if (obstacleSet.find(make_pair(r_q, i)) != obstacleSet.end())
			break;
		else
			nSquares++;
	}
	for (int i = r_q + 1, j = c_q - 1; i <= n && j >= 1; i++, j--) {
		if (obstacleSet.find(make_pair(i, j)) != obstacleSet.end())
			break;
		else
			nSquares++;
	}
	for (int i = r_q - 1, j = c_q + 1; i >= 1 && j <= n; i--, j++) {
		if (obstacleSet.find(make_pair(i, j)) != obstacleSet.end())
			break;
		else
			nSquares++;
	}
	for (int i = r_q + 1, j = c_q + 1; i <= n && j <= n; i++, j++) {
		if (obstacleSet.find(make_pair(i, j)) != obstacleSet.end())
			break;
		else
			nSquares++;
	}
	for (int i = r_q - 1, j = c_q - 1; i >= 1 && j >= 1; i--, j--) {
		if (obstacleSet.find(make_pair(i, j)) != obstacleSet.end())
			break;
		else
			nSquares++;
	}

	return nSquares;
}

int main()
{
	int n = 5, k = 3, r_q = 4, c_q = 3;
	vector<vector<int>> obstacles = { {5, 5}, {4, 2}, {2, 3} };
	int nSq = queensAttack(n, k, r_q, c_q, obstacles);
	return 0;
}