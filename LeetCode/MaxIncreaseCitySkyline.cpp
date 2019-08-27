#include "Header.h"

int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {

	vector<int> topBotMax, leftRightMax;
	int rowCount = grid.size();
	int colCount = grid[0].size();

	int rowMax = 0, colMax = 0;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			rowMax = max(rowMax, grid[i][j]);
		}
		leftRightMax.push_back(rowMax);
		rowMax = 0;
	}
	for (int i = 0; i < colCount; i++)
	{
		for (int j = 0; j < rowCount; j++)
		{
			colMax = max(colMax, grid[j][i]);
		}
		topBotMax.push_back(colMax);
		colMax = 0;
	}
	int increament = 0;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			int newVal = min(topBotMax[j], leftRightMax[i]);
			//grid[i][j] = newVal;
			increament += newVal - grid[i][j];
		}
	}
	printVectorOfVector(grid);

	return increament;
}

int main() {

	vector<vector<int>> grid = { {3, 0, 8, 4}, {2, 4, 5, 7}, {9, 2, 6, 3}, {0, 3, 1, 0} };

	int n = maxIncreaseKeepingSkyline(grid);

	return 0;
}