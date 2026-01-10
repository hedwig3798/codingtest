#include <bits/stdc++.h>
#include <unordered_set>

std::vector<int>cost;
std::vector<int>sum;
std::vector<std::vector<int>>dp;

int FileSum(int _left, int _right)
{
	if (INT_MAX != dp[_left][_right])
	{
		return dp[_left][_right];
	}

	if (_left == _right)
	{
		dp[_left][_right] = 0;
		return 0;
	}

	if (1 == _right - _left)
	{
		dp[_left][_right] = cost[_left] + cost[_right];
		return dp[_left][_right];
	}

	for (int i = _left; i < _right; i++)
	{
		int leftMin = FileSum(_left, i);
		int rightMin = FileSum(i + 1, _right);

		dp[_left][_right] = std::min(dp[_left][_right], leftMin + rightMin);
	}
	dp[_left][_right] += sum[_right] - sum[_left - 1];

	return dp[_left][_right];
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	int T;
	std::cin >> T;

	for (int tc = 0; tc < T; tc++)
	{
		int K;
		std::cin >> K;
		
		cost = std::vector<int>(K + 1, 0);
		sum = std::vector<int>(K + 1, 0);
		dp = std::vector<std::vector<int>>(K + 1, std::vector<int>(K + 1, INT_MAX));
		for (int i = 1; i <= K ; i++)
		{
			std::cin >> cost[i];
			sum[i] = sum[i - 1] + cost[i];
		}

		std::cout << FileSum(1, K) << '\n';
	}

	return 0;
}