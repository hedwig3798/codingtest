#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <tuple>
#include <set>

#define INF 1e9
using namespace std;

int N;
long long ans;

// board에서 최대 값 구하는 함수
long long GetMax(vector<vector<long long>> board)
{
	long long res = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			res = max(res, board[i][j]);
		}
	}
	return res;
}

// 오른쪽 이동
vector<vector<long long>> Right(vector<vector<long long>> board)
{
	vector<vector<bool>> check(N, vector<bool>(N, false));

	for (int i = 0; i < N; i++)
	{
		for (int j = N - 2; j >= 0; j--)
		{
			if (board[i][j] == 0)
				continue;
			for (int k = j + 1; k < N; k++)
			{
				if (board[i][k] == board[i][k - 1] && !check[i][k])
				{
					board[i][k] *= 2;
					board[i][k - 1] = 0;
					check[i][k] = true;
					break;
				}
				else if (board[i][k] == 0)
				{
					board[i][k] = board[i][k - 1];
					board[i][k - 1] = 0;
				}
				else
				{
					break;
				}
			}
		}
	}
	return board;
}

// 왼쪽 이동
vector<vector<long long>> Left(vector<vector<long long>> board)
{
	vector<vector<bool>> check(N, vector<bool>(N, false));

	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j < N; j++)
		{
			if (board[i][j] == 0)
				continue;
			for (int k = j - 1; k >= 0; k--)
			{
				if (board[i][k] == board[i][k + 1] && !check[i][k])
				{
					board[i][k] *= 2;
					board[i][k + 1] = 0;
					check[i][k] = true;
					break;
				}
				else if (board[i][k] == 0)
				{
					board[i][k] = board[i][k + 1];
					board[i][k + 1] = 0;
				}
				else
				{
					break;
				}
			}
		}
	}
	return board;
}

// 아래 이동
vector<vector<long long>> Down(vector<vector<long long>> board)
{
	vector<vector<bool>> check(N, vector<bool>(N, false));

	for (int i = 0; i < N; i++)
	{
		for (int j = N - 2; j >= 0; j--)
		{
			if (board[j][i] == 0)
				continue;
			for (int k = j + 1; k < N; k++)
			{
				if (board[k][i] == board[k - 1][i] && !check[k][i])
				{
					board[k][i] *= 2;
					board[k - 1][i] = 0;
					check[k][i] = true;
					break;
				}
				else if (board[k][i] == 0)
				{
					board[k][i] = board[k - 1][i];
					board[k - 1][i] = 0;
				}
				else
				{
					break;
				}
			}
		}
	}
	return board;
}

// 위로 이동
vector<vector<long long>> Up(vector<vector<long long>> board)
{
	vector<vector<bool>> check(N, vector<bool>(N, false));

	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j < N; j++)
		{
			if (board[j][i] == 0)
				continue;
			for (int k = j - 1; k >= 0; k--)
			{
				if (board[k][i] == board[k + 1][i] && !check[k][i])
				{
					board[k][i] *= 2;
					board[k + 1][i] = 0;
					check[k][i] = true;
					break;
				}
				else if (board[k][i] == 0)
				{
					board[k][i] = board[k + 1][i];
					board[k + 1][i] = 0;
				}
				else
				{
					break;
				}
			}
		}
	}
	return board;
}

void dfs(int L, vector<vector<long long>> board)
{
	ans = max(ans, GetMax(board));
	if (L == 5)
	{
		return;
	}
	dfs(L + 1, Right(board));
	dfs(L + 1, Left(board));
	dfs(L + 1, Up(board));
	dfs(L + 1, Down(board));
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	vector<vector<long long>> board(N, vector<long long>(N));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}

	dfs(0, board);
	cout << ans << '\n';

	return 0;
}