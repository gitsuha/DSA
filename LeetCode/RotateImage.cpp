#include "Header.h"

void rotateAntiClockwise(vector<vector<int>>& matrix) 
{
	for (size_t i = 0; i < matrix.size(); i++)
	{
		for (size_t j = 0; j < matrix[i].size(); j++)
		{
			reverse(matrix[i].begin(), matrix[i].end());
		}
	}
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = i + 1; j < matrix.size(); j++)
		{
			int tmp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = tmp;
		}
	}
}

void rotateClockwise(vector<vector<int>>& matrix) {

	if (matrix.size() == 0) {
		return;
	}

	int rows = matrix.size();
	int cols = matrix[0].size();
	// Reverse top to down
	for (int i = 0; i < rows / 2; i++) {
		for (int j = 0; j < cols; j++) {
			int temp = matrix[i][j];
			matrix[i][j] = matrix[rows - i - 1][j];
			matrix[rows - i - 1][j] = temp;
		}
	}
	// Swap the symmetry
	for (int i = 0; i < rows; i++) {
		for (int j = i; j < cols; j++) {
			int temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
	}
}

int main()
{
	vector<vector<int>> v1 = {
		{7, 4, 1},
		{8, 5, 2},
		{9, 6, 3}
	};

	rotateAntiClockwise(v1);
	rotateClockwise(v1);
	printVectorOfVector(v1);

	vector<vector<int>> v2 = {
		{5, 1, 9, 11},
		{2, 4, 8, 10},
		{13, 3, 6, 7},
		{15,14,12,16}
	};

	rotateAntiClockwise(v2);
	rotateClockwise(v2);
	printVectorOfVector(v2);

	return 0;
}