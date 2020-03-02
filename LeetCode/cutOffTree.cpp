#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Tree {
	int _i, _j, _h;
	Tree(int i, int j, int h) : _i(i), _j(j), _h(h) {}
};


int dist(vector<vector<int>>& forest, int sr, int sc, int tr, int tc) {
	int x[] = { 1, -1, 0, 0 };
	int y[] = { 0, 0, 1, -1 };
	queue<Tree> q;
	q.push(Tree(sr, sc, 0));
	vector<vector<int>> visited(forest.size(), vector<int>(forest[0].size(), 0));
	while (!q.empty())
	{
		Tree t = q.front();
		q.pop();
		if (t._i == tr && t._j == tc) 
			return t._h;
		for (size_t i = 0; i < 4; i++)
		{
			int r = t._i + x[i];
			int c = t._j + y[i];
			if (0 <= r && 0 <= c && r < forest.size() && c < forest[0].size() && visited[r][c] == 0 && forest[r][c] > 0) {
				visited[r][c] = 1;
				q.push(Tree(r, c, t._h + 1));
			}
		}
	}
	return -1;
}

int cutOffTree(vector<vector<int>>& forest) {
	// find all the cells with trees...
	vector<Tree> treePos;
	for (size_t i = 0; i < forest.size(); i++)
	{
		for (size_t j = 0; j < forest[0].size(); j++)
		{
			if (forest[i][j] > 1) {
				treePos.push_back(Tree(i, j, forest[i][j]));
			}
		}
	}

	// now short the list w.r.t tree height...
	sort(treePos.begin(), treePos.end(), [] (const Tree& t1, const Tree& t2) -> bool
	{
		return t1._h < t2._h;
	});

	// now iterate over the list to find the distance
	int d = 0, sr = 0, sc = 0;
	for (Tree& t : treePos) {
		int di = dist(forest, sr, sc, t._i, t._j);
		if (di < 0) return -1;
		d += di;
		sr = t._i;
		sc = t._j;
	}
	return d;
}

int main() {
	vector<vector<int>> forest = {
		{1, 2, 3},
		{0, 0, 4},
		{7, 6, 5}
	};
	int d = cutOffTree(forest);
	return 0;
}