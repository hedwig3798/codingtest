#include <bits/stdc++.h>
#include <unordered_set>

int N;

int d[20][20];

int dp[20][1 << 20];

int DFS(int _now, unsigned int _bitmask)
{
	if (_now == N)
	{
		return 0;
	}

	if (-1 != dp[_now][_bitmask])
	{
		return dp[_now][_bitmask];
	}

	dp[_now][_bitmask] = INT_MAX;
	for (int i = 0; i < N ; i++)
	{
		if (0 != (_bitmask & (1 << i)))
		{
			continue;
		}

		dp[_now][_bitmask] = std::min(dp[_now][_bitmask], d[_now][i] + DFS(_now + 1, _bitmask | 1 << i));
	}

	return dp[_now][_bitmask];
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cin >> d[i][j];
		}
	}

	::memset(dp, -1, sizeof(dp));

	std::cout << DFS(0, 0);

	return 0;
}