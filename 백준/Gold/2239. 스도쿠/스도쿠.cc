#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <tuple>

using namespace std;

bool backTracking(vector<vector<int>>& _board, int _x, int _y, vector<vector<bool>> _check[])
{
	while (_x < 9)
	{
		if (_board[_x][_y] != 0)
		{
			_y++;
			if (_y >= 9)
			{
				_y = 0;
				_x++;
			}
			if (_x >= 9) 
			{
				return true;
			}
			continue;
		}

		for (int i = 0; i < 9; i++)
		{
			if (_check[0][_y][i] || _check[1][_x][i] || _check[2][(_y / 3) * 3 + _x / 3][i])
			{
				continue;
			}
			bool sotre[3] =
			{
				_check[0][_y][i],
				_check[1][_x][i],
				_check[2][(_y / 3) * 3 + _x / 3][i]
			};
			_check[0][_y][i] = true;
			_check[1][_x][i] = true;
			_check[2][(_y / 3) * 3 + _x / 3][i] = true;
			_board[_x][_y] = i + 1;
			if (backTracking(_board, _x, _y, _check)) 
			{
				return true;
			}
			_check[0][_y][i] = sotre[0];
			_check[1][_x][i] = sotre[1];
			_check[2][(_y / 3) * 3 + _x / 3][i] = sotre[2];
			_board[_x][_y] = 0;
		}
		return false;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	vector<vector<int>> board(9, vector<int>(9, 0));

	vector<vector<bool>> check[3] =
	{
		vector<vector<bool>>(9, vector<bool>(9, 0)),
		vector<vector<bool>>(9, vector<bool>(9, 0)),
		vector<vector<bool>>(9, vector<bool>(9, 0))
	};

	for (int i = 0; i < 9; i++)
	{
		int num;
		cin >> num;
		for (int j = 0; j < 9; j++)
		{
			int value = num % 10;
			num /= 10;
			if (value != 0)
			{
				check[0][9 - j - 1][value - 1] = true;
				check[1][i][value - 1] = true;
				check[2][((9 - j - 1) / 3) * 3 + (i / 3)][value - 1] = true;
			}
			board[i][9 - j - 1] = value;
		}
	}

	backTracking(board, 0, 0, check);

	for(auto b : board) 
	{
		for(auto n : b) 
		{
			cout << n;
		}
		cout << "\n";
	}

	return 0;
}