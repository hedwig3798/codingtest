#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>

#define MAX_COUNT 1'000

int T, N;

int dp[MAX_COUNT][MAX_COUNT] = { 0, };
int cards[MAX_COUNT];

int DP(int _left, int _right, bool _turn)
{
	if (0 != dp[_left][_right])
	{
		return dp[_left][_right];
	}

	if (_left > _right)
	{
		return 0;
	}

	if (true == _turn)
	{
		dp[_left][_right] = std::max(cards[_left] + DP(_left + 1, _right, !_turn), cards[_right] + DP(_left, _right - 1, !_turn));
	}
	else
	{
		dp[_left][_right] = std::min(DP(_left + 1, _right, !_turn), DP(_left, _right - 1, !_turn));
	}


	return dp[_left][_right];
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> T;
	while (0 < T--)
	{
		std::cin >> N;
		
		for (int i = 0; i < N ; i++)
		{
			std::cin >> cards[i];
			for (int j = 0; j < N; j++)
			{
				dp[i][j] = 0;
			}
		}
		std::cout << DP(0, N - 1, true) << '\n';
	}

	return 0;
}