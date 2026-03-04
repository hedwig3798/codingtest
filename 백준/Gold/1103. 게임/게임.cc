#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using ll = long long;

int N, M;
int board[50][50] = { 0, };
int dp[50][50] = { 0, };
bool isVisit[50][50] = { 0, };

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int DFS(int _x, int _y)
{
	if (_x < 0
		|| _x >= N
		|| _y < 0
		|| _y >= M
		|| 'H' == board[_x][_y])
	{
		return 0;
	}

	if (true == isVisit[_x][_y])
	{
		return -1;
	}

	if (-1 != dp[_x][_y])
	{
		return dp[_x][_y];
	}

	isVisit[_x][_y] = true;
	int curr = board[_x][_y] - '0';
	int res = 0;
	for (int i = 0; i < 4; ++i)
	{
		int nx = _x + dx[i] * curr;
		int ny = _y + dy[i] * curr;

		int temp = DFS(nx, ny);
		if (-1 == temp)
		{
			return -1;
		}
		res = std::max(res, temp + 1);
	}
	isVisit[_x][_y] = false;

	dp[_x][_y] = res;
	return res;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		std::string s;
		std::cin >> s;
		for (int j = 0; j < M; ++j)
		{
			board[i][j] = s[j];
			dp[i][j] = -1;
		}
	}

	std::cout << DFS(0, 0);

	return 0;
}