#include "Header.h"

/*
input:
grid = [[1, 1, 1, 1], [0, 0, 0, 1], [1, 1, 1, 1]]
sr = 0, sc = 0, tr = 2, tc = 0
output: 8
(The lines below represent this grid:)
1111
0001
1111

grid = [[1, 1, 1, 1], [0, 0, 0, 1], [1, 0, 1, 1]]
sr = 0, sc = 0, tr = 2, tc = 0
output: -1
(The lines below represent this grid:)
1111
0001
1011
*/
struct Cell {
	pair<int, int> coord;
	int dist;
	Cell(pair<int, int> p, int d) : coord(p), dist(d) {}
};

vector<pair<int, int>> findAdjCells(pair<int, int> ip, int r, int c) {
	vector<pair<int, int>> adj;

	if (ip.first + 1 >= 0 && ip.first + 1 < r && ip.second >= 0 && ip.second < c)
		adj.push_back(make_pair(ip.first + 1, ip.second));
	
	if (ip.first - 1 >= 0 && ip.first - 1 < r && ip.second >= 0 && ip.second < c)
		adj.push_back(make_pair(ip.first - 1, ip.second));
	
	if (ip.first >= 0 && ip.first < r && ip.second + 1 >= 0 && ip.second + 1 < c)
		adj.push_back(make_pair(ip.first, ip.second + 1));

	if (ip.first >= 0 && ip.first < r && ip.second - 1 >= 0 && ip.second - 1 < c)
		adj.push_back(make_pair(ip.first, ip.second - 1));

	return adj;
}

int shortestCellPath(const vector<vector<int>>& grid, int sr, int sc, int tr, int tc)	{
	int r = grid.size();
	if (r <= 0) return -1;

	int c = grid[0].size();
	if (c <= 0) return -1;

	vector<vector<bool>> visited(r, vector<bool>(c, false));
	queue<Cell> q;

	q.push(Cell(make_pair(sr, sc), 0));
	visited[sr][sc] = true;

	int d = 0;
	while (!q.empty()) {
		Cell cell = q.front();
		pair<int, int> p = cell.coord;
		d = cell.dist;
		if (p.first == tr && p.second == tc) return d;
		q.pop();
		vector<pair<int, int>> adj = findAdjCells(p, r, c);
		for (int i = 0; i < adj.size(); i++) {
			pair<int, int> pp = adj[i];
			if (!visited[pp.first][pp.second] && grid[pp.first][pp.second])	{
				q.push(Cell(pp, d + 1));
				visited[pp.first][pp.second] = true;
			}				
		}
	}
	return -1;
}

int shortestCellPathProd(const vector<vector<int>>& grid, int sr, int sc, int tr, int tc) {
	int r = grid.size();
	if (r <= 0) return 0;

	int c = grid[0].size();
	if (c <= 0) return 0;

	vector<vector<int>> visited(r, vector<int>(c, 0));
	queue<Cell> q;

	q.push(Cell(make_pair(sr, sc), grid[sr][sc]));
	visited[sr][sc]++;
	int maxPrd = INT_MIN;
	int d = 1;
	while (!q.empty()) {
		Cell cell = q.front();
		pair<int, int> p = cell.coord;
		d = cell.dist;
		maxPrd = max(d, maxPrd);
		//if (p.first == tr && p.second == tc) return maxPrd;
		q.pop();
		vector<pair<int, int>> adj = findAdjCells(p, r, c);
		for (int i = 0; i < adj.size(); i++) {
			pair<int, int> pp = adj[i];
			if (visited[pp.first][pp.second] <= 2) {
				q.push(Cell(pp, d * grid[pp.first][pp.second]));
				visited[pp.first][pp.second]++;
			}
		}
	}
	return maxPrd;
}

int main()	{
	vector<vector<int>> grid1 = { {1, 1, 1}, {0, 0, 0 }, {0, 0, 0} };
	int sr = 0, sc = 1, tr = 0, tc = 0;
	int d = shortestCellPath(grid1, sr, sc, tr, tc);

	vector<vector<int>> grid2 = { {1, 2, 3},{4, 5, 6}, {7, 8, 9} };
	sr = 0, sc = 0, tr = 2, tc = 2;
	d = shortestCellPathProd(grid2, sr, sc, tr, tc);

	vector<vector<int>> grid3 = { {-1, 2, 3},{4, 5, -6}, {7, 8, 9} };
	sr = 0, sc = 0, tr = 2, tc = 2;
	d = shortestCellPathProd(grid3, sr, sc, tr, tc);

	return 0;
}