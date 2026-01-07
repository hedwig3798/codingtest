#include <bits/stdc++.h>
#include <unordered_set>

#define MAX_COUNT 16

int N;
int house[MAX_COUNT][MAX_COUNT] = { 0, };

// right : 0 / down : 1 / diagonal : 2
int dp[MAX_COUNT][MAX_COUNT][3] = { 0, };

int DP(int _cx, int _cy, int _dir)
{
	if (_cx == N - 1 
		&& _cy == N - 1)
	{
		return 1;
	}

	if (-1 != dp[_cx][_cy][_dir])
	{
		return dp[_cx][_cy][_dir];
	}

	int right = 0, down = 0, diagonal = 0;

	auto GoRight = [&]()
		{
			int nx = _cx + 1;
			int ny = _cy;

			if (nx < 0
				|| ny < 0
				|| nx >= N
				|| ny >= N
				|| 1 == house[nx][ny])
			{
				return;
			}
			house[nx][ny] = 1;

			right = DP(nx, ny, 0);

			house[nx][ny] = 0;
		};

	auto GoDown = [&]()
		{
			int nx = _cx;
			int ny = _cy + 1;

			if (nx < 0
				|| ny < 0
				|| nx >= N
				|| ny >= N
				|| 1 == house[nx][ny])
			{
				return;
			}
			house[nx][ny] = 1;

			down = DP(nx, ny, 1);

			house[nx][ny] = 0;
		};

	auto GoDiagonal = [&]()
		{
			int nx = _cx + 1;
			int ny = _cy + 1;

			if (nx < 0
				|| ny < 0
				|| nx >= N
				|| ny >= N
				|| 1 == house[nx][ny]
				|| 1 == house[nx - 1][ny]
				|| 1 == house[nx][ny - 1])
			{
				return;
			}
			house[nx][ny] = 1;
			house[nx - 1][ny] = 1;
			house[nx][ny - 1] = 1;

			diagonal = DP(nx, ny, 2);

			house[nx][ny] = 0;
			house[nx - 1][ny] = 0;
			house[nx][ny - 1] = 0;
		};

	switch (_dir)
	{
	case 0:
	{
		GoRight();
		GoDiagonal();
		break;
	}
	case 1:
	{
		GoDown();
		GoDiagonal();
		break;
	}
	case 2:
	{
		GoRight();
		GoDown();
		GoDiagonal();
		break;
	}
	default:
		break;
	}

	dp[_cx][_cy][_dir] = right + down + diagonal;
	return dp[_cx][_cy][_dir];
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cin >> house[j][i];
			for (int k = 0; k < 3 ; k++)
			{
				dp[i][j][k] = -1;
			}
		}
	}
	house[0][0] = 1;
	house[0][1] = 1;

	std::cout << DP(1, 0, 0);

	return 0;
}