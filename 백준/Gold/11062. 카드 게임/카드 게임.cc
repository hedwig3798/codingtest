#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>

#define MAX_COUNT 1'000

int T, N;

int dp[MAX_COUNT][MAX_COUNT] = { 0, };
bool chooseLeft[MAX_COUNT][MAX_COUNT] = { 0, };
int cards[MAX_COUNT];

void DP(int _left, int _right)
{
	if (0 != dp[_left][_right])
	{
		return;
	}

	if (_left == _right)
	{
		dp[_left][_right] = cards[_left];
		return;
	}

	int l = cards[_left];
	int r = cards[_right];
	if (_right - _left == 1)
	{
		if (l > r)
		{
			chooseLeft[_left][_right] = true;
			dp[_left][_right] = l;
		}
		else
		{
			chooseLeft[_left][_right] = false;
			dp[_left][_right] = r;
		}
		dp[_left][_left] = l;
		dp[_right][_right] = r;

		return;
	}

	DP(_left + 1, _right);
	DP(_left, _right - 1);

	// 왼쪽 선택, 상대도 왼쪽 선택
	if (true == chooseLeft[_left + 1][_right])
	{
		if (dp[_left][_right] < l + dp[_left + 2][_right])
		{
			dp[_left][_right] = l + dp[_left + 2][_right];
			chooseLeft[_left][_right] = true;
		}
	}
	// 왼쪽 선택 상대는 오른쪽 선택
	if (false == chooseLeft[_left + 1][_right])
	{
		if (dp[_left][_right] < l + dp[_left + 1][_right - 1])
		{
			dp[_left][_right] = l + dp[_left + 1][_right - 1];
			chooseLeft[_left][_right] = true;
		}
	}
	// 오른쪽 선택, 상대도 오른쪽 선택
	if (false == chooseLeft[_left][_right - 1])
	{
		if (dp[_left][_right] < r + dp[_left][_right - 2])
		{
			dp[_left][_right] = r + dp[_left][_right - 2];
			chooseLeft[_left][_right] = false;
		}
	}
	// 오른쪽 선택 상대는 왼쪽 선택
	if (true == chooseLeft[_left][_right - 1])
	{
		if (dp[_left][_right] < r + dp[_left + 1][_right - 1])
		{
			dp[_left][_right] = r + dp[_left + 1][_right - 1];
			chooseLeft[_left][_right] = false;
		}
	}
	return;
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
		DP(0, N - 1);

		std::cout << dp[0][N - 1] << '\n';
	}

	return 0;
}